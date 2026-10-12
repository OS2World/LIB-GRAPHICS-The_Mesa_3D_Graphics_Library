/*
 * glutint.h -- OS/2 PM internal GLUT header (Mesa 7.11.2)
 *
 * Force-included (-include flag) before every TU in the GLUT build.
 *
 * CRITICAL: Do NOT include <GL/glut.h> here.
 *   Font-data files (glut_8x13.c, glut_roman.c, …) do:
 *     #define glutBitmap8By13 XXX
 *     #include "glutbitmap.h"   // → <GL/glut.h>
 *     #undef  glutBitmap8By13
 *   That trick redirects the "GLUTAPI void *glutBitmap8By13" declaration
 *   in glut.h to the dummy name XXX, avoiding a type conflict when the
 *   file later defines "const BitmapFontRec glutBitmap8By13".
 *   Pre-including glut.h here (before the #define trick) would declare
 *   the real name and cause "conflicting type qualifiers" errors.
 *
 * Do NOT define symbols that glut.h also defines (GLUTAPI, GLUTproc,
 * GLUTbitmapFont, GLUT_INDEX, …).  Duplicate definitions with different
 * token values generate macro-redefinition warnings that halt the build
 * in strict mode.
 *
 * Minimum needed by the portable glx/ files:
 *   • <GL/gl.h>  + <GL/glu.h>   (GL types, gluErrorString)
 *   • GLUTAPIENTRY / GLUTCALLBACK  (empty macros for GCC/OS2)
 *   • GLUTXxxCB typedefs          (used by os2_glut.c callbacks)
 *   • __glut* extern declarations (used by glut_util.c, glut_shapes.c)
 */
#ifndef __glutint_h__
#define __glutint_h__

/* Tell glut.h we are the library (affects Win32 dllexport path only, but
   safe to define here so os2_glut.c's explicit #include <GL/glut.h>
   also sees it). */
#define GLUT_BUILDING_LIB

#include <GL/gl.h>          /* GL types, GL_UNPACK_*, glGetIntegerv, …  */
#include <GL/glu.h>         /* gluErrorString (called by glut_util.c)    */
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

/* ------------------------------------------------------------------ */
/* GLUTAPIENTRY / GLUTCALLBACK                                          */
/* These must be defined here so glut_util.c, glut_bitmap.c, etc. can  */
/* use them in function signatures before any glut.h inclusion.         */
/* They are defined as empty under GCC on OS/2, matching what glut.h    */
/* would produce.  Use identical token sequences to avoid redefinition  */
/* warnings when glut.h is later included by a font-data file.          */
/* ------------------------------------------------------------------ */
#ifndef GLUTAPIENTRY
#  define GLUTAPIENTRY
#endif
#ifndef GLUTAPIENTRYV
#  define GLUTAPIENTRYV
#endif
#ifndef GLUTCALLBACK
#  define GLUTCALLBACK
#endif

/* ------------------------------------------------------------------ */
/* Callback typedefs (internal to GLUT, not in glut.h)                 */
/* ------------------------------------------------------------------ */
typedef void (GLUTCALLBACK *GLUTdisplayCB)(void);
typedef void (GLUTCALLBACK *GLUTreshapeCB)(int, int);
typedef void (GLUTCALLBACK *GLUTkeyboardCB)(unsigned char, int, int);
typedef void (GLUTCALLBACK *GLUTmouseCB)(int, int, int, int);
typedef void (GLUTCALLBACK *GLUTmotionCB)(int, int);
typedef void (GLUTCALLBACK *GLUTpassiveCB)(int, int);
typedef void (GLUTCALLBACK *GLUTentryCB)(int);
typedef void (GLUTCALLBACK *GLUTvisibilityCB)(int);
typedef void (GLUTCALLBACK *GLUTwindowStatusCB)(int);
typedef void (GLUTCALLBACK *GLUTidleCB)(void);
typedef void (GLUTCALLBACK *GLUTtimerCB)(int);
typedef void (GLUTCALLBACK *GLUTmenuStateCB)(int);
typedef void (GLUTCALLBACK *GLUTmenuStatusCB)(int, int, int);
typedef void (GLUTCALLBACK *GLUTselectCB)(int);
typedef void (GLUTCALLBACK *GLUTspecialCB)(int, int, int);
typedef void (GLUTCALLBACK *GLUTspaceMotionCB)(int, int, int);
typedef void (GLUTCALLBACK *GLUTspaceRotateCB)(int, int, int);
typedef void (GLUTCALLBACK *GLUTspaceButtonCB)(int, int);
typedef void (GLUTCALLBACK *GLUTdialsCB)(int, int);
typedef void (GLUTCALLBACK *GLUTbuttonBoxCB)(int, int);
typedef void (GLUTCALLBACK *GLUTtabletMotionCB)(int, int);
typedef void (GLUTCALLBACK *GLUTtabletButtonCB)(int, int, int, int);
typedef void (GLUTCALLBACK *GLUTjoystickCB)(unsigned int, int, int, int);

/* ------------------------------------------------------------------ */
/* Globals defined in os2_glut.c                                        */
/* ------------------------------------------------------------------ */
extern char *__glutProgramName;
extern void (*__glutExitFunc)(int);

/* ------------------------------------------------------------------ */
/* Functions defined in glut_util.c                                    */
/* ------------------------------------------------------------------ */
extern void  __glutFatalError(char *format, ...);
extern void  __glutFatalUsage(char *format, ...);
extern void  __glutWarning(char *format, ...);
extern char *__glutStrdup(const char *string);

/* ------------------------------------------------------------------ */
/* Variables / functions defined in glut_mesa.c                        */
/* ------------------------------------------------------------------ */
extern int  __glutMesaSwapHackSupport;
extern void __glutDetermineMesaSwapHackSupport(void);

/* ------------------------------------------------------------------ */
/* timeval helpers (kept for completeness; not used by portable files)  */
/* ------------------------------------------------------------------ */
#define GETTIMEOFDAY(_x) gettimeofday(_x, NULL)

#define IS_AFTER(t1, t2) \
  (((t2).tv_sec > (t1).tv_sec) || \
  (((t2).tv_sec == (t1).tv_sec) && ((t2).tv_usec > (t1).tv_usec)))

#define IS_AT_OR_AFTER(t1, t2) \
  (((t2).tv_sec > (t1).tv_sec) || \
  (((t2).tv_sec == (t1).tv_sec) && ((t2).tv_usec >= (t1).tv_usec)))

#define IGNORE_IN_GAME_MODE() do {} while (0)

#endif /* __glutint_h__ */
