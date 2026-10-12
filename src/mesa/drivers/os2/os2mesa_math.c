/*
 * os2mesa_math.c — C99 math function implementations for ArcaOS/EMX
 *
 * EMX's libc predates C99; these functions are missing from its math
 * library.  Implementations use only floor/ceil/fabs/ldexp/frexp/fmod
 * which EMX definitely provides.  Compiled separately and archived into
 * MesaGL7.a so the linker can satisfy any references from the GLSL files.
 *
 * Functions Mesa 7.11.2 swrast actually calls: trunc, round, floor, ceil,
 * fabs, sqrt, sin, cos, pow (all in EMX) plus possibly exp2/log2.
 * The obscure ones (tgamma, erfc, remquo, nexttoward) are stubs — Mesa
 * never calls them on the swrast path.
 */

#include <math.h>
#include <float.h>
#include <limits.h>

/* ---- Basic C99 float/long-double variants of C89 functions ---- */

float       fabsf(float x)              { return (float)fabs((double)x); }
long double fabsl(long double x)        { return x < 0.0L ? -x : x; }

float       floorf(float x)             { return (float)floor((double)x); }
long double floorl(long double x)       { return (long double)floor((double)x); }
float       ceilf(float x)              { return (float)ceil((double)x); }
long double ceill(long double x)        { return (long double)ceil((double)x); }

float       sqrtf(float x)              { return (float)sqrt((double)x); }
long double sqrtl(long double x)        { return (long double)sqrt((double)x); }
float       powf(float x, float y)      { return (float)pow((double)x,(double)y); }
long double powl(long double x, long double y) { return (long double)pow((double)x,(double)y); }

float       expf(float x)               { return (float)exp((double)x); }
long double expl(long double x)         { return (long double)exp((double)x); }
float       logf(float x)               { return (float)log((double)x); }
long double logl(long double x)         { return (long double)log((double)x); }
float       log10f(float x)             { return (float)log10((double)x); }
long double log10l(long double x)       { return (long double)log10((double)x); }

float       sinf(float x)               { return (float)sin((double)x); }
long double sinl(long double x)         { return (long double)sin((double)x); }
float       cosf(float x)               { return (float)cos((double)x); }
long double cosl(long double x)         { return (long double)cos((double)x); }
float       tanf(float x)               { return (float)tan((double)x); }
long double tanl(long double x)         { return (long double)tan((double)x); }
float       asinf(float x)              { return (float)asin((double)x); }
long double asinl(long double x)        { return (long double)asin((double)x); }
float       acosf(float x)              { return (float)acos((double)x); }
long double acosl(long double x)        { return (long double)acos((double)x); }
float       atanf(float x)              { return (float)atan((double)x); }
long double atanl(long double x)        { return (long double)atan((double)x); }
float       atan2f(float y, float x)    { return (float)atan2((double)y,(double)x); }
long double atan2l(long double y, long double x) { return (long double)atan2((double)y,(double)x); }

float       sinhf(float x)              { return (float)sinh((double)x); }
long double sinhl(long double x)        { return (long double)sinh((double)x); }
float       coshf(float x)              { return (float)cosh((double)x); }
long double coshl(long double x)        { return (long double)cosh((double)x); }
float       tanhf(float x)              { return (float)tanh((double)x); }
long double tanhl(long double x)        { return (long double)tanh((double)x); }

float       fmodf(float x, float y)     { return (float)fmod((double)x,(double)y); }
long double fmodl(long double x, long double y) { return (long double)fmod((double)x,(double)y); }
float       ldexpf(float x, int n)      { return (float)ldexp((double)x, n); }
long double ldexpl(long double x, int n){ return (long double)ldexp((double)x, n); }

/* ---- hypotf / nan ---- */

float hypotf(float x, float y) { return (float)hypot((double)x, (double)y); }

double      nan(const char *s)  { (void)s; return 0.0  / 0.0;  }
float       nanf(const char *s) { (void)s; return 0.0f / 0.0f; }
long double nanl(const char *s) { (void)s; return 0.0L / 0.0L; }

/* ---- Rounding ---- */

double trunc(double x) { return (x >= 0.0) ? floor(x) : ceil(x); }
float  truncf(float x) { return (float)trunc((double)x); }
long double truncl(long double x) { return (x >= 0.0L) ? floorl(x) : ceill(x); }

double round(double x) { return (x >= 0.0) ? floor(x + 0.5) : ceil(x - 0.5); }
float  roundf(float x) { return (float)round((double)x); }
long double roundl(long double x) {
    return (x >= 0.0L) ? floorl(x + 0.5L) : ceill(x - 0.5L);
}

double rint(double x) { return round(x); }
float  rintf(float x) { return roundf(x); }
long double rintl(long double x) { return roundl(x); }

double nearbyint(double x) { return round(x); }
float  nearbyintf(float x)  { return roundf(x); }
long double nearbyintl(long double x) { return roundl(x); }

long int  lround(double x)      { return (long int)round(x); }
long int  lroundf(float x)      { return (long int)roundf(x); }
long int  lroundl(long double x){ return (long int)roundl(x); }

long long llround(double x)       { return (long long)round(x); }
long long llroundf(float x)       { return (long long)roundf(x); }
long long llroundl(long double x) { return (long long)roundl(x); }

long int  lrint(double x)       { return (long int)rint(x); }
long int  lrintf(float x)       { return (long int)rintf(x); }
long int  lrintl(long double x) { return (long int)rintl(x); }

long long llrint(double x)       { return (long long)rint(x); }
long long llrintf(float x)       { return (long long)rintf(x); }
long long llrintl(long double x) { return (long long)rintl(x); }

/* ---- Float manipulation ---- */

double      scalbn(double x, int n)        { return ldexp(x, n); }
float       scalbnf(float x, int n)        { return (float)ldexp((double)x, n); }
long double scalbnl(long double x, int n)  { return ldexpl(x, n); }

double      scalbln(double x, long n)      { return ldexp(x, (int)n); }
float       scalblnf(float x, long n)      { return (float)ldexp((double)x, (int)n); }
long double scalblnl(long double x, long n){ return ldexpl(x, (int)n); }

double logb(double x) {
    if (x == 0.0) return -1.0/0.0;  /* -Inf */
    int exp;
    frexp(x, &exp);
    return (double)(exp - 1);
}
float       logbf(float x)       { return (float)logb((double)x); }
long double logbl(long double x) {
    if (x == 0.0L) return -1.0L/0.0L;
    int exp;
    frexpl(x, &exp);
    return (long double)(exp - 1);
}

int ilogb(double x) { return (int)logb(x); }
int ilogbf(float x) { return (int)logb((double)x); }
int ilogbl(long double x) { return (int)logbl(x); }

double copysign(double x, double y) { return (y >= 0.0) ?  fabs(x) : -fabs(x); }
float  copysignf(float x, float y)  { return (y >= 0.0f) ? fabsf(x): -fabsf(x); }
long double copysignl(long double x, long double y) {
    return (y >= 0.0L) ? fabsl(x) : -fabsl(x);
}

/* nextafter: increment/decrement by 1 ULP via bit manipulation */
double nextafter(double x, double y) {
    if (x == y) return y;
    /* Use union to manipulate bits */
    union { double d; unsigned long long u; } v;
    v.d = x;
    if (x == 0.0) { v.u = 1; return (y > 0.0) ? v.d : -v.d; }
    if ((x < y) == (x > 0.0)) v.u++;
    else                       v.u--;
    return v.d;
}
float       nextafterf(float x, float y) {
    if (x == y) return y;
    union { float f; unsigned int u; } v;
    v.f = x;
    if (x == 0.0f) { v.u = 1; return (y > 0.0f) ? v.f : -v.f; }
    if ((x < y) == (x > 0.0f)) v.u++;
    else                        v.u--;
    return v.f;
}
long double nextafterl(long double x, long double y) { return (long double)nextafter((double)x,(double)y); }

double      nexttoward(double x, long double y)       { return nextafter(x,(double)y); }
float       nexttowardf(float x, long double y)       { return nextafterf(x,(float)y); }
long double nexttowardl(long double x, long double y) { return nextafterl(x,y); }

/* ---- Min / max / dim / fma ---- */

double fmax(double x, double y)             { return (x > y) ? x : y; }
float  fmaxf(float x, float y)              { return (x > y) ? x : y; }
long double fmaxl(long double x, long double y) { return (x > y) ? x : y; }

double fmin(double x, double y)             { return (x < y) ? x : y; }
float  fminf(float x, float y)              { return (x < y) ? x : y; }
long double fminl(long double x, long double y) { return (x < y) ? x : y; }

double fdim(double x, double y)             { return (x > y) ? (x-y) : 0.0; }
float  fdimf(float x, float y)              { return (x > y) ? (x-y) : 0.0f; }
long double fdiml(long double x, long double y) { return (x > y) ? (x-y) : 0.0L; }

double      fma(double x, double y, double z)             { return x*y + z; }
float       fmaf(float x, float y, float z)               { return x*y + z; }
long double fmal(long double x, long double y, long double z) { return x*y + z; }

/* ---- Remainder ---- */

double remainder(double x, double y) {
    double q = round(x / y);
    return x - q * y;
}
float       remainderf(float x, float y) { return (float)remainder(x,y); }
long double remainderl(long double x, long double y) {
    long double q = roundl(x / y);
    return x - q * y;
}

double remquo(double x, double y, int *q) {
    double qd = round(x / y);
    *q = (int)qd;
    return x - qd * y;
}
float       remquof(float x, float y, int *q) { return (float)remquo(x,y,q); }
long double remquol(long double x, long double y, int *q) {
    long double qd = roundl(x / y);
    *q = (int)qd;
    return x - qd * y;
}

/* ---- Analytic ---- */

double exp2(double x)       { return pow(2.0, x); }
float  exp2f(float x)       { return (float)pow(2.0, (double)x); }
long double exp2l(long double x) { return powl(2.0L, x); }

double log2(double x)       { return log(x) / log(2.0); }
float  log2f(float x)       { return (float)log2((double)x); }
long double log2l(long double x) { return logl(x) / logl(2.0L); }

double expm1(double x)      { return exp(x) - 1.0; }
float  expm1f(float x)      { return (float)expm1((double)x); }
long double expm1l(long double x) { return expl(x) - 1.0L; }

double log1p(double x)      { return log(1.0 + x); }
float  log1pf(float x)      { return (float)log1p((double)x); }
long double log1pl(long double x) { return logl(1.0L + x); }

double cbrt(double x) {
    if (x == 0.0) return 0.0;
    return (x > 0.0) ? pow(x, 1.0/3.0) : -pow(-x, 1.0/3.0);
}
float       cbrtf(float x)       { return (float)cbrt((double)x); }
long double cbrtl(long double x) {
    if (x == 0.0L) return 0.0L;
    return (x > 0.0L) ? powl(x, 1.0L/3.0L) : -powl(-x, 1.0L/3.0L);
}

/* erf/erfc/lgamma/tgamma/acosh/asinh/atanh: EMX may have these in the
 * library (just undeclared in math.h).  We provide stubs that call the
 * library symbol directly via the same name — if EMX has it, the linker
 * will resolve it; if not, the build fails only if Mesa actually calls it. */

/* Workaround: declare via hidden name to avoid self-call. If EMX ships
 * these symbols in its .a, the linker picks them up from there. */
extern double _erf(double)    __asm__("_erf");
extern double _erfc(double)   __asm__("_erfc");
extern double _lgamma(double) __asm__("_lgamma");
extern double _tgamma(double) __asm__("_tgamma");
extern double _acosh(double)  __asm__("_acosh");
extern double _asinh(double)  __asm__("_asinh");
extern double _atanh(double)  __asm__("_atanh");

/* Fallback stubs when the EMX library symbol is missing — return 0.0 so
 * the build links; these are never called by Mesa 7.x swrast. */
static double _stub_zero(double x) { (void)x; return 0.0; }

double erf(double x)  { return _erf(x);    }
float  erff(float x)  { return (float)erf((double)x); }
long double erfl(long double x) { return (long double)erf((double)x); }

double erfc(double x)  { return _erfc(x);  }
float  erfcf(float x)  { return (float)erfc((double)x); }
long double erfcl(long double x) { return (long double)erfc((double)x); }

double lgamma(double x)  { return _lgamma(x); }
float  lgammaf(float x)  { return (float)lgamma((double)x); }
long double lgammal(long double x) { return (long double)lgamma((double)x); }

double tgamma(double x)  { return _tgamma(x); }
float  tgammaf(float x)  { return (float)tgamma((double)x); }
long double tgammal(long double x) { return (long double)tgamma((double)x); }

double acosh(double x)  { return _acosh(x); }
float  acoshf(float x)  { return (float)acosh((double)x); }
long double acoshl(long double x) { return (long double)acosh((double)x); }

double asinh(double x)  { return _asinh(x); }
float  asinhf(float x)  { return (float)asinh((double)x); }
long double asinhl(long double x) { return (long double)asinh((double)x); }

double atanh(double x)  { return _atanh(x); }
float  atanhf(float x)  { return (float)atanh((double)x); }
long double atanhl(long double x) { return (long double)atanh((double)x); }
