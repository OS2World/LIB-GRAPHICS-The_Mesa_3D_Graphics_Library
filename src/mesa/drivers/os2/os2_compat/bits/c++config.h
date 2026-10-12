/*
 * os2_compat/bits/c++config.h — libstdc++ config shim for ArcaOS GCC 9
 *
 * GCC 9's <cmath> checks _GLIBCXX_USE_C99_MATH to decide whether to
 * import C99 math functions (trunc, round, remainder, ...) into std::.
 * The real <bits/c++config.h> unconditionally defines it to 1, but the
 * old EMX math library predates C99 and lacks those functions entirely.
 *
 * This shim (found first via -I$(OS2_COMPAT)) pulls in the real config
 * and then forces the C99 math gates off so <cmath> skips the missing
 * function declarations.
 */
#include_next <bits/c++config.h>

#undef  _GLIBCXX_USE_C99_MATH
#define _GLIBCXX_USE_C99_MATH 0

#undef  _GLIBCXX_USE_C99
#define _GLIBCXX_USE_C99 0

#undef  _GLIBCXX_USE_C99_MATH_TR1
#define _GLIBCXX_USE_C99_MATH_TR1 0

#undef  _GLIBCXX_USE_C99_COMPLEX
#define _GLIBCXX_USE_C99_COMPLEX 0

#undef  _GLIBCXX_USE_C99_COMPLEX_TR1
#define _GLIBCXX_USE_C99_COMPLEX_TR1 0
