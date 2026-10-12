/* os2_compat/string.h — fix EMX string.h linkage in C++ context
 *
 * EMX's /usr/include/string.h declares all string functions without
 * extern "C" guards.  In a C++ TU those get C++ linkage.  GCC's
 * include-fixed/string.h later re-declares them with C linkage,
 * producing "conflicting declaration" hard errors.
 *
 * Fix: include EMX's string.h first inside extern "C" to establish C
 * linkage for every function it declares (also sets the include guard
 * so subsequent inclusions are no-ops).  Then #include_next finds
 * c++/9/string.h or include-fixed/string.h; their re-declarations
 * all match C linkage — no conflict.
 */

#ifndef _OS2_COMPAT_STRING_H_SEEN
#define _OS2_COMPAT_STRING_H_SEEN

#ifdef __cplusplus
extern "C" {
#include "/@unixroot/usr/include/string.h"
}
#include_next <string.h>
#else
#include_next <string.h>
#endif

#endif /* _OS2_COMPAT_STRING_H_SEEN */
