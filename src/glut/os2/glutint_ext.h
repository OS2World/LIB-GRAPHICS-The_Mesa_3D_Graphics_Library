/*
 * glutint_ext.h  --  force-include for glut_ext.c only
 *
 * glut_ext.c builds a table of GLUTproc pointers covering the entire
 * GLUT API.  It expects "glutint.h" to transitively provide:
 *   - GLUTproc typedef
 *   - every glutXxx function declaration
 * (The upstream X11 glutint.h includes <GL/glut.h> for exactly that.)
 *
 * Our OS/2 glutint.h deliberately omits <GL/glut.h> so that font-data
 * files (glut_8x13.c etc.) can use the #define XXX redirect trick before
 * their own glutbitmap.h inclusion.  For those files the absence of a
 * pre-declared name is essential; for glut_ext.c it is fatal.
 *
 * Solution: compile glut_ext.c with -include glutint_ext.h instead of
 * -include glutint.h.  This header adds the glut.h inclusion AFTER our
 * guard is set, so glut_ext.c's own #include "glutint.h" is harmlessly
 * skipped by the guard while GLUTproc and the API declarations arrive
 * from <GL/glut.h>.
 */
#include "glutint.h"    /* sets __glutint_h__ guard; gl.h, glu.h, CB types */
#include <GL/glut.h>    /* GLUTproc, all glutXxx declarations                */
