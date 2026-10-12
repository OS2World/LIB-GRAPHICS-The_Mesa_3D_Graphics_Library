/* os2_compat/math.h — fix EMX math.h linkage in C++ context
 *
 * EMX's /usr/include/math.h declares abs/atof/labs/hypot without
 * extern "C" guards.  In a C++ translation unit those get C++ linkage.
 * GCC's include-fixed/stdlib.h later redeclares them with C linkage
 * (correct), which triggers a hard "conflicting declaration" error.
 *
 * Fix (C++ only):
 *   1. Include EMX's math.h directly inside extern "C" so every
 *      function it declares gets C linkage.
 *   2. EMX's own include guard (_MATH_H) is now set.
 *   3. #include_next <math.h> finds c++/9/math.h which sets up the
 *      C++ wrappers; its own #include_next <math.h> hits the guard
 *      and becomes a no-op, so no conflicting redeclarations occur.
 *
 * In plain C just pass through.
 */

#ifndef _OS2_COMPAT_MATH_H_SEEN
#define _OS2_COMPAT_MATH_H_SEEN

#ifdef __cplusplus
extern "C" {
#include "/@unixroot/usr/include/math.h"
}
/* Let GCC's C++ math.h wrapper (c++/9/math.h) run now.
 * Its eventual #include_next <math.h> finds EMX's math.h whose
 * guard (_MATH_H) is already set, so it is a no-op. */
#include_next <math.h>
#else
#include_next <math.h>
#endif

#endif /* _OS2_COMPAT_MATH_H_SEEN */
