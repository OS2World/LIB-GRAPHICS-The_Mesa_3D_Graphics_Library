/*
 * Public OS/2 Presentation Manager Mesa API — Mesa 7.11.2
 *
 * This is the WarpMesaGL context API that OS/2 applications link against.
 * The interface mirrors the Windows wmesa.h (WMesaCreateContext etc.) so
 * that GLUT and WGL shim code needs only small OS/2-specific changes.
 */
#ifndef _OS2MESA_H_
#define _OS2MESA_H_

#include "os2_config.h"

/* Forward-declare the opaque types */
typedef struct os2mesa_context     *WMesaContext;
typedef struct os2mesa_framebuffer *WMesaFramebuffer;

#include "GL/gl.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
 * WMesaCreateContext
 *
 * Create a new Mesa GL rendering context attached to a PM window.
 *
 *   hwnd      — client HWND (WinCreateWindow / WC_FRAME client)
 *   hps       — presentation space for the window (WinGetPS or cached)
 *   hab       — anchor block (WinInitialize result)
 *   db_flag   — GL_TRUE for double-buffered rendering
 *   alpha_flag— GL_TRUE to allocate an alpha channel in the visual
 *
 * Returns NULL on failure.
 */
WMesaContext WMesaCreateContext(HWND hwnd, HPS hps, HAB hab,
                                GLboolean db_flag, GLboolean alpha_flag);

/*
 * WMesaDestroyContext
 *
 * Destroy a context created by WMesaCreateContext.  If this context is
 * current it is unbound first.
 */
void WMesaDestroyContext(WMesaContext ctx);

/*
 * WMesaMakeCurrent
 *
 * Bind ctx as the current GL context for the thread, targeting hwnd.
 * Pass ctx=NULL to unbind.
 */
void WMesaMakeCurrent(WMesaContext ctx, HWND hwnd);

/*
 * WMesaSwapBuffers
 *
 * Blit the back buffer to the screen (no-op for single-buffered contexts).
 * hwnd identifies which framebuffer to swap.
 */
void WMesaSwapBuffers(HWND hwnd);

/*
 * WMesaShareLists
 *
 * Share display lists between two contexts (equivalent to wglShareLists).
 */
void WMesaShareLists(WMesaContext src, WMesaContext dst);

#ifdef __cplusplus
}
#endif

#endif /* _OS2MESA_H_ */
