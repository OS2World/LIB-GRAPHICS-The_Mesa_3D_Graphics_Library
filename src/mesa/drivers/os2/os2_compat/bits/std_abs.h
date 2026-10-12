/*
 * os2_compat/bits/std_abs.h — passthrough to real bits/std_abs.h
 *
 * The original shim blocked stdlib.h to prevent a C-vs-C++ linkage
 * conflict: EMX math.h declared abs with C++ linkage; include-fixed/
 * stdlib.h redeclared it with C linkage.  That conflict is now resolved
 * by os2_compat/math.h wrapping EMX's math.h in extern "C", so both
 * declarations carry C linkage and agree.
 *
 * Pass through to GCC's real bits/std_abs.h, which includes <stdlib.h>
 * (giving ::abs its declaration) then does namespace std { using ::abs; }.
 */
#ifndef _OS2_COMPAT_STD_ABS_H
#define _OS2_COMPAT_STD_ABS_H 1
#include_next <bits/std_abs.h>
#endif
