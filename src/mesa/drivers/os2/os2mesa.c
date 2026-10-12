/*
 * OS/2 Presentation Manager device driver for Mesa 7.11.2
 *
 * Ported from the Mesa 5.0 WarpMesaGL driver (Evgeny Kotsuba, 2002) and
 * the Mesa 7.x Windows GDI driver (wmesa.c).
 *
 * Rendering pipeline:
 *   GL app → Mesa core → TNL → swrast_setup → swrast → renderbuffer
 *   callbacks (PutRow / GetRow) → back-buffer pixel store → GpiBitBlt → screen
 *
 * Coordinate system:
 *   OS/2 GPI and OpenGL both have Y=0 at the bottom of the window.
 *   The back buffer is stored with BRA_BOTTOMUP, so no Y-flip is needed
 *   in the span routines.
 *
 * Limitations of this initial port:
 *   - 32 bpp only (PF_8R8G8B path).  16/24 bpp can be added later.
 *   - GPI blit only; DIVE hardware-accelerated path is a TODO.
 *   - Double-buffered only; single-buffer falls back on double-buffer logic.
 */

#include "os2mesa.h"
#include "os2mesadef.h"

#include "main/context.h"
#include "main/extensions.h"
#include "main/framebuffer.h"
#include "main/renderbuffer.h"
#include "main/macros.h"
#include "drivers/common/driverfuncs.h"
#include "drivers/common/meta.h"
#include "vbo/vbo.h"
#include "swrast/swrast.h"
#include "swrast_setup/swrast_setup.h"
#include "tnl/tnl.h"
#include "tnl/t_context.h"
#include "tnl/t_pipeline.h"

/* -----------------------------------------------------------------------
 * Framebuffer linked list
 * --------------------------------------------------------------------- */

static WMesaFramebuffer FirstFramebuffer = NULL;

static WMesaFramebuffer
os2mesa_new_framebuffer(HWND hwnd, HPS hps, HAB hab,
                        struct gl_config *visual)
{
    WMesaFramebuffer fb =
        (WMesaFramebuffer) calloc(1, sizeof(struct os2mesa_framebuffer));
    if (fb) {
        _mesa_initialize_window_framebuffer(&fb->Base, visual);
        fb->hwnd = hwnd;
        fb->hps  = hps;
        fb->hab  = hab;
        fb->hdc  = WinQueryWindowDC(hwnd);
        fb->next = FirstFramebuffer;
        FirstFramebuffer = fb;
    }
    return fb;
}

static void
os2mesa_free_framebuffer(HWND hwnd)
{
    WMesaFramebuffer fb, prev = NULL;
    for (fb = FirstFramebuffer; fb; prev = fb, fb = fb->next) {
        if (fb->hwnd == hwnd)
            break;
    }
    if (fb) {
        struct gl_framebuffer *base = &fb->Base;
        if (fb == FirstFramebuffer)
            FirstFramebuffer = fb->next;
        else
            prev->next = fb->next;
        _mesa_reference_framebuffer(&base, NULL);
    }
}

static WMesaFramebuffer
os2mesa_lookup_framebuffer(HWND hwnd)
{
    WMesaFramebuffer fb;
    for (fb = FirstFramebuffer; fb; fb = fb->next)
        if (fb->hwnd == hwnd)
            return fb;
    return NULL;
}

/* Cast helpers — safe because Base / gl_ctx are first members */
static WMesaFramebuffer os2fb(struct gl_framebuffer *b)
    { return (WMesaFramebuffer) b; }
static WMesaContext     os2ctx(const struct gl_context *c)
    { return (WMesaContext) c; }

/* -----------------------------------------------------------------------
 * Back-buffer allocation / release
 * --------------------------------------------------------------------- */

static void
get_window_size(HWND hwnd, GLuint *w, GLuint *h)
{
    RECTL r;
    WinQueryWindowRect(hwnd, &r);
    *w = (GLuint)(r.xRight - r.xLeft);
    *h = (GLuint)(r.yTop   - r.yBottom);
}

static GLboolean
os2mesa_create_back_buffer(WMesaFramebuffer fb, GLuint width, GLuint height)
{
    PSZ   pszData[4] = { "Display", NULL, NULL, NULL };
    SIZEL sizel      = { 0, 0 };

    /* Determine bits-per-pixel from the screen DC */
    LONG caps[1];
    DevQueryCaps(fb->hdc, CAPS_COLOR_BITCOUNT, 1, caps);
    fb->cColorBits = (UINT)caps[0];
    /* Normalise: we only handle 16 and 32 for now */
    if (fb->cColorBits != 16)
        fb->cColorBits = 32;

    fb->pixelformat = (fb->cColorBits == 16) ? PF_5R6G5B : PF_8R8G8B;

    /* Scan-line stride, aligned to 4 bytes */
    fb->ScanWidth = ((width * (fb->cColorBits / 8)) + 3) & ~3u;

    /* Pixel buffer */
    if (fb->pbPixels)
        free(fb->pbPixels);
    fb->pbPixels = (PBYTE) malloc(fb->ScanWidth * height);
    if (!fb->pbPixels)
        return GL_FALSE;
    memset(fb->pbPixels, 0, fb->ScanWidth * height);

    /* BITMAPINFOHEADER2 for GpiBitBlt */
    memset(&fb->bmi, 0, sizeof(fb->bmi));
    fb->bmi.cbFix        = sizeof(BITMAPINFOHEADER2);
    fb->bmi.cx           = width;
    fb->bmi.cy           = height;
    fb->bmi.cPlanes      = 1;
    fb->bmi.cBitCount    = (USHORT)fb->cColorBits;
    fb->bmi.ulCompression = BCA_UNCOMP;
    fb->bmi.usRecording  = BRA_BOTTOMUP;   /* Y=0 at bottom, matches GL */
    fb->bmi.usRendering  = BRH_NOTHALFTONED;
    fb->bmi.ulColorEncoding = BCE_RGB;

    /* Memory DC + PS for the blit */
    if (fb->hpsMem) {
        if (fb->hbm) {
            GpiSetBitmap(fb->hpsMem, NULLHANDLE);
            GpiDeleteBitmap(fb->hbm);
            fb->hbm = NULLHANDLE;
        }
        GpiDestroyPS(fb->hpsMem);
        DevCloseDC(fb->hdcMem);
    }
    fb->hdcMem = DevOpenDC(fb->hab, OD_MEMORY, "*", 4,
                           (PDEVOPENDATA)pszData, NULLHANDLE);
    fb->hpsMem = GpiCreatePS(fb->hab, fb->hdcMem, &sizel,
                             PU_PELS | GPIA_ASSOC | GPIT_MICRO);
    return GL_TRUE;
}

static void
os2mesa_delete_back_buffer(WMesaFramebuffer fb)
{
    if (fb->hpsMem) {
        if (fb->hbm) {
            GpiSetBitmap(fb->hpsMem, NULLHANDLE);
            GpiDeleteBitmap(fb->hbm);
            fb->hbm = NULLHANDLE;
        }
        GpiDestroyPS(fb->hpsMem);
        DevCloseDC(fb->hdcMem);
        fb->hpsMem = NULLHANDLE;
        fb->hdcMem = NULLHANDLE;
    }
    if (fb->pbPixels) {
        free(fb->pbPixels);
        fb->pbPixels = NULL;
    }
}

/* -----------------------------------------------------------------------
 * Blit back buffer to screen (swap)
 * --------------------------------------------------------------------- */

static void
os2mesa_blit(WMesaFramebuffer fb)
{
    POINTL aptl[4];
    HPS    hps;

    if (!fb->pbPixels || !fb->hwnd)
        return;

    /* The PS handed to WMesaCreateContext is released by the caller, so
     * never keep it: acquire a fresh window PS for every blit. */
    hps = WinGetPS(fb->hwnd);
    if (!hps)
        return;

    /* Destination rectangle: inclusive-inclusive, bottom-up window coords */
    aptl[0].x = 0;                 aptl[0].y = 0;
    aptl[1].x = fb->bmi.cx - 1;    aptl[1].y = fb->bmi.cy - 1;
    /* Source rectangle: inclusive-exclusive, bottom-up bitmap coords */
    aptl[2].x = 0;                 aptl[2].y = 0;
    aptl[3].x = fb->bmi.cx;        aptl[3].y = fb->bmi.cy;

    GpiDrawBits(hps, fb->pbPixels, (PBITMAPINFO2)&fb->bmi, 4L, aptl,
                ROP_SRCCOPY, BBO_IGNORE);

    WinReleasePS(hps);
}

/* -----------------------------------------------------------------------
 * Driver callbacks
 * --------------------------------------------------------------------- */

static const GLubyte *
os2mesa_get_string(struct gl_context *ctx, GLenum name)
{
    (void) ctx;
    return (name == GL_RENDERER) ?
        (const GLubyte *) "WarpMesaGL OS/2 PM (Mesa 7.11.2)" : NULL;
}

static void
os2mesa_get_buffer_size(struct gl_framebuffer *buffer,
                        GLuint *width, GLuint *height)
{
    WMesaFramebuffer fb = os2fb(buffer);
    get_window_size(fb->hwnd, width, height);
}

static void
os2mesa_flush(struct gl_context *ctx)
{
    if (ctx->Visual.doubleBufferMode) {
        WMesaFramebuffer fb = os2fb(ctx->WinSysDrawBuffer);
        os2mesa_blit(fb);
    }
}

static void
os2mesa_clear_color(struct gl_context *ctx, const GLfloat color[4])
{
    WMesaContext c = os2ctx(ctx);
    GLubyte r, g, b;
    CLAMPED_FLOAT_TO_UBYTE(r, color[0]);
    CLAMPED_FLOAT_TO_UBYTE(g, color[1]);
    CLAMPED_FLOAT_TO_UBYTE(b, color[2]);
    c->clearColor = BGR32(r, g, b);
}

static void
os2mesa_clear(struct gl_context *ctx, GLbitfield mask)
{
    WMesaContext     c   = os2ctx(ctx);
    WMesaFramebuffer fb  = os2fb(ctx->DrawBuffer);
    GLuint           w   = ctx->DrawBuffer->Width;
    GLuint           h   = ctx->DrawBuffer->Height;

    if ((mask & BUFFER_BIT_BACK_LEFT) && ctx->Visual.doubleBufferMode &&
        fb->pbPixels && fb->cColorBits == 32) {
        /* Fast 32-bit clear of the entire back buffer */
        ULONG  *row = (ULONG *)fb->pbPixels;
        GLuint  i;
        GLuint  stride32 = fb->ScanWidth / 4;

        /* Fill first row */
        for (i = 0; i < w; i++)
            row[i] = c->clearColor;
        /* Copy first row to subsequent rows */
        for (i = 1; i < h; i++)
            memcpy(row + i * stride32, row, w * 4);

        mask &= ~BUFFER_BIT_BACK_LEFT;
    }

    /* Let swrast handle depth, stencil, accum, and any remaining bits */
    if (mask)
        _swrast_Clear(ctx, mask);
}

static void
os2mesa_resize_buffers(struct gl_context *ctx,
                       struct gl_framebuffer *buffer,
                       GLuint width, GLuint height)
{
    WMesaFramebuffer fb = os2fb(buffer);

    if (fb->Base.Width != width || fb->Base.Height != height) {
        if (ctx->Visual.doubleBufferMode) {
            os2mesa_delete_back_buffer(fb);
            os2mesa_create_back_buffer(fb, width, height);
        }
    }
    _mesa_resize_framebuffer(ctx, buffer, width, height);
}

static void
os2mesa_viewport(struct gl_context *ctx,
                 GLint x, GLint y, GLsizei w, GLsizei h)
{
    GLuint nw, nh;
    (void) x; (void) y; (void) w; (void) h;
    os2mesa_get_buffer_size(ctx->WinSysDrawBuffer, &nw, &nh);
    os2mesa_resize_buffers(ctx, ctx->WinSysDrawBuffer, nw, nh);
    ctx->NewState |= _NEW_BUFFERS;
}

static void
os2mesa_update_state(struct gl_context *ctx, GLuint new_state)
{
    _swrast_InvalidateState(ctx, new_state);
    _swsetup_InvalidateState(ctx, new_state);
    _vbo_InvalidateState(ctx, new_state);
    _tnl_InvalidateState(ctx, new_state);
}

/* -----------------------------------------------------------------------
 * Renderbuffer — 32-bit back buffer span routines
 *
 * OS/2 GPI with BRA_BOTTOMUP: pbPixels[y * ScanWidth + x*4] is the
 * pixel at (x, y) where y=0 is the bottom of the window.  This matches
 * OpenGL's convention, so no Y-flip is applied.
 * --------------------------------------------------------------------- */

/* Helper: pointer to 32-bit pixel at (x, y) in the back buffer */
#define PIXEL32(fb, x, y) \
    ((ULONG *)((fb)->pbPixels + (y) * (fb)->ScanWidth) + (x))

static void
write_rgba_span_32(struct gl_context *ctx, struct gl_renderbuffer *rb,
                   GLuint n, GLint x, GLint y,
                   const void *values, const GLubyte *mask)
{
    const GLubyte (*rgba)[4] = (const GLubyte (*)[4]) values;
    WMesaFramebuffer fb = os2fb(ctx->DrawBuffer);
    ULONG *dst = PIXEL32(fb, x, y);
    GLuint i;
    if (mask) {
        for (i = 0; i < n; i++)
            if (mask[i])
                dst[i] = BGR32(rgba[i][RCOMP], rgba[i][GCOMP], rgba[i][BCOMP]);
    } else {
        for (i = 0; i < n; i++)
            *dst++ = BGR32(rgba[i][RCOMP], rgba[i][GCOMP], rgba[i][BCOMP]);
    }
}

static void
write_rgb_span_32(struct gl_context *ctx, struct gl_renderbuffer *rb,
                  GLuint n, GLint x, GLint y,
                  const void *values, const GLubyte *mask)
{
    const GLubyte (*rgb)[3] = (const GLubyte (*)[3]) values;
    WMesaFramebuffer fb = os2fb(ctx->DrawBuffer);
    ULONG *dst = PIXEL32(fb, x, y);
    GLuint i;
    if (mask) {
        for (i = 0; i < n; i++)
            if (mask[i])
                dst[i] = BGR32(rgb[i][RCOMP], rgb[i][GCOMP], rgb[i][BCOMP]);
    } else {
        for (i = 0; i < n; i++)
            *dst++ = BGR32(rgb[i][RCOMP], rgb[i][GCOMP], rgb[i][BCOMP]);
    }
}

static void
write_mono_rgba_span_32(struct gl_context *ctx, struct gl_renderbuffer *rb,
                        GLuint n, GLint x, GLint y,
                        const void *value, const GLubyte *mask)
{
    const GLchan *color = (const GLchan *) value;
    WMesaFramebuffer fb = os2fb(ctx->DrawBuffer);
    ULONG *dst = PIXEL32(fb, x, y);
    ULONG  pixel = BGR32(color[RCOMP], color[GCOMP], color[BCOMP]);
    GLuint i;
    if (mask) {
        for (i = 0; i < n; i++)
            if (mask[i]) dst[i] = pixel;
    } else {
        for (i = 0; i < n; i++)
            *dst++ = pixel;
    }
}

static void
write_rgba_pixels_32(struct gl_context *ctx, struct gl_renderbuffer *rb,
                     GLuint n, const GLint x[], const GLint y[],
                     const void *values, const GLubyte *mask)
{
    const GLubyte (*rgba)[4] = (const GLubyte (*)[4]) values;
    WMesaFramebuffer fb = os2fb(ctx->DrawBuffer);
    GLuint i;
    for (i = 0; i < n; i++)
        if (mask[i])
            *PIXEL32(fb, x[i], y[i]) =
                BGR32(rgba[i][RCOMP], rgba[i][GCOMP], rgba[i][BCOMP]);
}

static void
write_mono_rgba_pixels_32(struct gl_context *ctx, struct gl_renderbuffer *rb,
                          GLuint n, const GLint x[], const GLint y[],
                          const void *value, const GLubyte *mask)
{
    const GLchan *color = (const GLchan *) value;
    WMesaFramebuffer fb = os2fb(ctx->DrawBuffer);
    ULONG pixel = BGR32(color[RCOMP], color[GCOMP], color[BCOMP]);
    GLuint i;
    for (i = 0; i < n; i++)
        if (mask[i])
            *PIXEL32(fb, x[i], y[i]) = pixel;
}

static void
read_rgba_span_32(struct gl_context *ctx, struct gl_renderbuffer *rb,
                  GLuint n, GLint x, GLint y, void *values)
{
    GLubyte (*rgba)[4] = (GLubyte (*)[4]) values;
    WMesaFramebuffer fb = os2fb(ctx->DrawBuffer);
    const ULONG *src = PIXEL32(fb, x, y);
    GLuint i;
    for (i = 0; i < n; i++) {
        ULONG p = src[i];
        rgba[i][RCOMP] = (GLubyte)((p >> 16) & 0xff);
        rgba[i][GCOMP] = (GLubyte)((p >>  8) & 0xff);
        rgba[i][BCOMP] = (GLubyte)( p        & 0xff);
        rgba[i][ACOMP] = 255;
    }
}

static void
read_rgba_pixels_32(struct gl_context *ctx, struct gl_renderbuffer *rb,
                    GLuint n, const GLint x[], const GLint y[], void *values)
{
    GLubyte (*rgba)[4] = (GLubyte (*)[4]) values;
    WMesaFramebuffer fb = os2fb(ctx->DrawBuffer);
    GLuint i;
    for (i = 0; i < n; i++) {
        ULONG p = *PIXEL32(fb, x[i], y[i]);
        rgba[i][RCOMP] = (GLubyte)((p >> 16) & 0xff);
        rgba[i][GCOMP] = (GLubyte)((p >>  8) & 0xff);
        rgba[i][BCOMP] = (GLubyte)( p        & 0xff);
        rgba[i][ACOMP] = 255;
    }
}

/* -----------------------------------------------------------------------
 * Renderbuffer object plumbing
 * --------------------------------------------------------------------- */

static void
os2mesa_delete_renderbuffer(struct gl_renderbuffer *rb)
{
    free(rb);
}

static GLboolean
os2mesa_renderbuffer_storage(struct gl_context *ctx,
                             struct gl_renderbuffer *rb,
                             GLenum internalFormat,
                             GLuint width, GLuint height)
{
    (void) ctx; (void) internalFormat;
    rb->Width  = width;
    rb->Height = height;
    return GL_TRUE;
}

static struct gl_renderbuffer *
os2mesa_new_renderbuffer(void)
{
    struct gl_renderbuffer *rb = CALLOC_STRUCT(gl_renderbuffer);
    if (!rb)
        return NULL;
    _mesa_init_renderbuffer(rb, 0);
    rb->_BaseFormat   = GL_RGBA;
    rb->InternalFormat = GL_RGBA;
    rb->DataType      = CHAN_TYPE;
    rb->Delete        = os2mesa_delete_renderbuffer;
    rb->AllocStorage  = os2mesa_renderbuffer_storage;
    return rb;
}

static void
os2mesa_set_renderbuffer_funcs(struct gl_renderbuffer *rb, int double_buffer)
{
    if (double_buffer) {
        /* Back buffer — 32-bit BGR pixel store */
        rb->PutRow       = write_rgba_span_32;
        rb->PutRowRGB    = write_rgb_span_32;
        rb->PutMonoRow   = write_mono_rgba_span_32;
        rb->PutValues    = write_rgba_pixels_32;
        rb->PutMonoValues = write_mono_rgba_pixels_32;
        rb->GetRow       = read_rgba_span_32;
        rb->GetValues    = read_rgba_pixels_32;
    }
    /* Front buffer: let swrast use GpiSetPel (slow but correct) — TODO */
}

/* -----------------------------------------------------------------------
 * Public API
 * --------------------------------------------------------------------- */

WMesaContext
WMesaCreateContext(HWND hwnd, HPS hps, HAB hab,
                   GLboolean db_flag, GLboolean alpha_flag)
{
    WMesaContext          c;
    struct dd_function_table funcs;
    struct gl_context    *ctx;
    struct gl_config     *visual;

    c = (WMesaContext) calloc(1, sizeof(struct os2mesa_context));
    if (!c)
        return NULL;

    c->hwnd = hwnd;
    c->hps  = hps;
    c->hab  = hab;
    c->hdc  = WinQueryWindowDC(hwnd);

    /* Build the GL visual descriptor */
    visual = _mesa_create_visual(
        db_flag,              /* double buffer */
        GL_FALSE,             /* stereo */
        8, 8, 8,              /* R G B bits */
        alpha_flag ? 8 : 0,   /* A bits */
        DEFAULT_SOFTWARE_DEPTH_BITS,
        8,                    /* stencil */
        16, 16, 16,           /* accum RGB */
        alpha_flag ? 16 : 0,  /* accum A */
        1);                   /* samples */
    if (!visual) {
        free(c);
        return NULL;
    }

    /* Populate driver function table */
    _mesa_init_driver_functions(&funcs);
    funcs.GetString     = os2mesa_get_string;
    funcs.UpdateState   = os2mesa_update_state;
    funcs.GetBufferSize = os2mesa_get_buffer_size;
    funcs.Flush         = os2mesa_flush;
    funcs.Clear         = os2mesa_clear;
    funcs.ClearColor    = os2mesa_clear_color;
    funcs.ResizeBuffers = os2mesa_resize_buffers;
    funcs.Viewport      = os2mesa_viewport;

    /* Initialise the embedded gl_context */
    ctx = &c->gl_ctx;
    _mesa_initialize_context(ctx, API_OPENGL, visual, NULL, &funcs, (void *)c);
    _mesa_destroy_visual(visual);   /* copied into ctx by the call above */

    _mesa_enable_sw_extensions(ctx);
    _mesa_enable_1_3_extensions(ctx);
    _mesa_enable_1_4_extensions(ctx);
    _mesa_enable_1_5_extensions(ctx);
    _mesa_enable_2_0_extensions(ctx);
    _mesa_enable_2_1_extensions(ctx);

    _mesa_meta_init(ctx);

    /* Initialise software rasteriser and helpers */
    if (!_swrast_CreateContext(ctx)  ||
        !_vbo_CreateContext(ctx)     ||
        !_tnl_CreateContext(ctx)     ||
        !_swsetup_CreateContext(ctx)) {
        _mesa_free_context_data(ctx);
        free(c);
        return NULL;
    }
    _swsetup_Wakeup(ctx);
    TNL_CONTEXT(ctx)->Driver.RunPipeline = _tnl_run_pipeline;

    return c;
}


void
WMesaDestroyContext(WMesaContext c)
{
    struct gl_context *ctx = &c->gl_ctx;
    WMesaFramebuffer   fb;
    GET_CURRENT_CONTEXT(cur);

    if (cur == ctx)
        WMesaMakeCurrent(NULL, NULLHANDLE);

    fb = os2mesa_lookup_framebuffer(c->hwnd);
    if (fb) {
        if (ctx->Visual.doubleBufferMode)
            os2mesa_delete_back_buffer(fb);
        os2mesa_free_framebuffer(c->hwnd);
    }

    _mesa_meta_free(ctx);
    _swsetup_DestroyContext(ctx);
    _tnl_DestroyContext(ctx);
    _vbo_DestroyContext(ctx);
    _swrast_DestroyContext(ctx);
    _mesa_free_context_data(ctx);
    free(c);
}


void
WMesaMakeCurrent(WMesaContext c, HWND hwnd)
{
    WMesaFramebuffer fb;

    /* Bail out early if already current */
    {
        GET_CURRENT_CONTEXT(ctx);
        WMesaContext cur = os2ctx(ctx);
        if (cur && c == cur && cur->hwnd == hwnd)
            return;
    }

    if (!c || hwnd == NULLHANDLE) {
        _mesa_make_current(NULL, NULL, NULL);
        return;
    }

    fb = os2mesa_lookup_framebuffer(hwnd);

    /* Lazy framebuffer creation on first MakeCurrent */
    if (!fb) {
        struct gl_config *visual = &c->gl_ctx.Visual;
        struct gl_renderbuffer *rb;
        GLuint w, h;

        get_window_size(hwnd, &w, &h);

        fb = os2mesa_new_framebuffer(hwnd, c->hps, c->hab, visual);
        if (!fb)
            return;

        if (visual->doubleBufferMode) {
            if (!os2mesa_create_back_buffer(fb, w, h)) {
                os2mesa_free_framebuffer(hwnd);
                return;
            }
            rb = os2mesa_new_renderbuffer();
            if (!rb) {
                os2mesa_free_framebuffer(hwnd);
                return;
            }
            _mesa_add_renderbuffer(&fb->Base, BUFFER_BACK_LEFT, rb);
            os2mesa_set_renderbuffer_funcs(rb, 1);
        }

        /* Front renderbuffer (for now shares the back store callbacks) */
        rb = os2mesa_new_renderbuffer();
        if (rb) {
            _mesa_add_renderbuffer(&fb->Base, BUFFER_FRONT_LEFT, rb);
            os2mesa_set_renderbuffer_funcs(rb, 0);
        }

        /* Let Mesa manage depth, stencil, and accum */
        _mesa_add_soft_renderbuffers(&fb->Base,
            GL_FALSE,
            visual->depthBits   > 0,
            visual->stencilBits > 0,
            visual->accumRedBits > 0,
            visual->alphaBits   > 0,
            GL_FALSE);
    }

    _mesa_make_current(&c->gl_ctx, &fb->Base, &fb->Base);
}


void
WMesaSwapBuffers(HWND hwnd)
{
    GET_CURRENT_CONTEXT(ctx);
    WMesaContext     c  = os2ctx(ctx);
    WMesaFramebuffer fb = os2mesa_lookup_framebuffer(hwnd);

    if (!fb) {
        _mesa_problem(NULL, "WMesaSwapBuffers: unknown HWND");
        return;
    }

    if (c && c->hwnd == hwnd)
        _mesa_notifySwapBuffers(ctx);

    os2mesa_blit(fb);
}


void
WMesaShareLists(WMesaContext src, WMesaContext dst)
{
    _mesa_share_state(&dst->gl_ctx, &src->gl_ctx);
}
