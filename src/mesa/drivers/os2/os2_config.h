/*
 * OS/2 build configuration for Mesa 7.11.2
 *
 * Include this before any GL header on OS/2.  It pulls in os2.h and
 * stubs out the Windows-style calling-convention markers that Mesa's
 * public headers reference.
 */
#ifndef _OS2_CONFIG_H_
#define _OS2_CONFIG_H_

/* GCC 9+ does not pre-define the 16-bit OS/2 compatibility keywords that
 * os2def16.h and bsedos16.h use.  Define them as empty before pulling in
 * os2.h so the system headers parse cleanly in 32-bit flat-model code.
 * (EMX used to inject these; the ANPM GCC 9 toolchain does not.)
 */
#ifndef FAR
# define FAR
#endif
#ifndef NEAR
# define NEAR
#endif
#ifndef PASCAL
# define PASCAL
#endif
/* bsedos16.h uses the underscore forms as well */
#ifndef _far
# define _far
#endif
#ifndef _near
# define _near
#endif
#ifndef _pascal
# define _pascal
#endif
/* malloc.h uses _huge (huge-pointer model, meaningless in 32-bit flat) */
#ifndef _huge
# define _huge
#endif
/* Calling conventions: GCC 9 on ArcaOS pre-defines _System as
 * __attribute__((__system__)) (native OS/2 linkage) and os2def.h defines
 * APIENTRY/EXPENTRY in terms of it.  Do NOT override _System/EXPENTRY:
 * a stdcall override makes the compiler reference decorated names such as
 * _GpiBitBlt@24, which exist in no import library.
 * _Builtin has no GCC equivalent and stays empty. */
#undef  _Builtin
#define _Builtin

/* Use targeted PM sub-includes rather than INCL_PM.
 * INCL_PM is a super-include that also pulls in INCL_SPL (pmspl.h) and
 * INCL_WINSTDDIALOGS — both of which use the EXPENTRY calling-convention
 * macro that GCC 9 on ArcaOS does not pre-define.  We only need:
 *   INCL_WIN  — HAB, HWND, HPS handles and WinGetPS / WinReleasePS
 *   INCL_GPI  — GPI drawing: GpiCreatePS, GpiBitBlt, GpiCreateBitmap …
 *   INCL_DEV  — DevOpenDC, DevQueryCaps, DevCloseDC
 *   INCL_DOS  — DosAllocMem, threading primitives
 */
#define INCL_WIN
#define INCL_GPI
#define INCL_DEV
#define INCL_DOS
#define INCL_DOSERRORS
#include <os2.h>

/* Neutralise Windows-style markers used inside GL/gl.h */
#ifndef WINGDIAPI
# define WINGDIAPI
#endif
#ifndef WINAPI
# define WINAPI
#endif
#ifndef CALLBACK
# define CALLBACK
#endif
#ifndef APIENTRY
# define APIENTRY
#endif

/* BOOL32 is an EMX extension not present in Open Watcom's os2.h */
#ifndef BOOL32
typedef ULONG BOOL32;
#endif

/* NULLHANDLE is defined by EMX but absent from the ArcaOS GCC toolkit headers */
#ifndef NULLHANDLE
# define NULLHANDLE ((LHANDLE)NULL)
#endif

/* OS/2 GPI coordinate convention: Y=0 is at the BOTTOM of the window,
 * which matches OpenGL's convention — no Y-flip is needed in span
 * routines when BRA_BOTTOMUP is used in the bitmap header.
 */
#define MESA_OS2_BOTTOMUP 1

#endif /* _OS2_CONFIG_H_ */
