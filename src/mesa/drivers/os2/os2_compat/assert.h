/* os2_compat/assert.h — fix EMX assert.h linkage in C++ context
 *
 * EMX's /usr/include/assert.h declares _assert() without extern "C".
 * In a C++ TU that gives it C++ linkage.  When assert.h is included a
 * second time (from a different include chain), GCC's include-fixed or
 * the same EMX header re-declares _assert() with C linkage — conflict.
 *
 * Fix: include EMX's assert.h first inside extern "C" (sets the guard
 * and establishes C linkage for _assert), then #include_next.
 * Also replace the assert() macro with one that uses __builtin_trap()
 * so the const-char* → void* cast issue (in EMX's _assert prototype)
 * is avoided in C++ code.
 */

#ifndef _OS2_COMPAT_ASSERT_H_SEEN
#define _OS2_COMPAT_ASSERT_H_SEEN

#ifdef __cplusplus
extern "C" {
#include "/@unixroot/usr/include/assert.h"
}
#include_next <assert.h>
#else
#include_next <assert.h>
#endif

/* Replace assert() so it does not call EMX's _assert(void*,void*,uint)
 * with a const char* argument (C++ linkage / const mismatch issue). */
#undef assert
#ifdef NDEBUG
# define assert(expr)  ((void)0)
#else
# define assert(expr)  ((expr) ? (void)0 : __builtin_trap())
#endif

#endif /* _OS2_COMPAT_ASSERT_H_SEEN */
