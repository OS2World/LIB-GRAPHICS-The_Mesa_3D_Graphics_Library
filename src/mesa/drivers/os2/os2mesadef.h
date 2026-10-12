/*
 * OS/2 Mesa context and framebuffer struct definitions for Mesa 7.11.2
 *
 * Modelled on src/mesa/drivers/windows/gdi/wmesadef.h.
 * The gl_context and gl_framebuffer base structs MUST be the first
 * members so that the driver structs can be cast to/from their Mesa
 * base types.
 */
#ifndef _OS2MESADEF_H_
#define _OS2MESADEF_H_

#include "os2_config.h"
#include "main/mtypes.h"

/* -----------------------------------------------------------------------
 * Pixel format identifiers (same values as the Windows GDI driver uses
 * so that shared colour-math macros work unchanged)
 * --------------------------------------------------------------------- */
#define PF_BADFORMAT 0
#define PF_INDEX8    1   /* 8-bit palette index                          */
#define PF_5R6G5B    2   /* 16-bit 5-6-5 RGB                             */
#define PF_8R8G8B    3   /* 24-bit or 32-bit BGR                         */
#define PF_8A8R8G8B  4   /* 32-bit BGRA (rare on OS/2)                   */

/* -----------------------------------------------------------------------
 * Colour packing / unpacking — OS/2 stores pixels as BGR(A) in memory
 * (same byte order as Windows DIBs so we reuse the same macros).
 * --------------------------------------------------------------------- */
#define BGR8(r,g,b)   ((BYTE)(((BYTE)(b) & 0xE0) | (((BYTE)(g) & 0xE0)>>3) | ((BYTE)(r)>>6)))
#define BGR16(r,g,b)  ((WORD) ((((WORD)(r)>>3)<<11) | (((WORD)(g)>>2)<<5) | ((WORD)(b)>>3)))
#define BGR32(r,g,b)  ((ULONG)(((ULONG)(b)) | (((ULONG)(g))<<8) | (((ULONG)(r))<<16)))

/* -----------------------------------------------------------------------
 * OS2MesaFramebuffer
 *
 * One instance per PM client window.  Kept in a singly-linked list so
 * WMesaMakeCurrent / WMesaSwapBuffers can look up by HWND.
 * --------------------------------------------------------------------- */
struct os2mesa_framebuffer {
    struct gl_framebuffer Base;     /* MUST be first — Mesa casts this   */

    HWND    hwnd;                   /* client window handle               */
    HDC     hdc;                    /* screen device context              */
    HPS     hps;                    /* screen presentation space          */
    HAB     hab;                    /* anchor block                       */

    /* Back-buffer pixel store (malloc'd; NULL for single-buffer) */
    PBYTE   pbPixels;
    ULONG   ScanWidth;              /* bytes per row (aligned to 4 bytes) */

    /* GPI memory DC + PS used for the blit */
    HDC         hdcMem;
    HPS         hpsMem;
    HBITMAP     hbm;                /* current GPI bitmap object          */
    BITMAPINFOHEADER2 bmi;          /* describes the back buffer          */

    UINT    cColorBits;             /* bits per pixel (16, 24, or 32)     */
    UINT    pixelformat;            /* PF_* value chosen at creation      */

    struct os2mesa_framebuffer *next;
};

typedef struct os2mesa_framebuffer *WMesaFramebuffer;

/* -----------------------------------------------------------------------
 * OS2MesaContext
 *
 * One instance per GL rendering context.  The embedded gl_context must
 * be the first member.
 * --------------------------------------------------------------------- */
struct os2mesa_context {
    struct gl_context gl_ctx;       /* MUST be first — Mesa casts this   */

    HWND    hwnd;                   /* window this context was created on */
    HDC     hdc;
    HPS     hps;
    HAB     hab;

    ULONG   clearColor;             /* packed BGR clear colour            */
};

typedef struct os2mesa_context *WMesaContext;

#endif /* _OS2MESADEF_H_ */
