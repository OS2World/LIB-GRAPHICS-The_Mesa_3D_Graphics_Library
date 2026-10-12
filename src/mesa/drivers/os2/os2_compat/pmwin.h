/*
 * os2_compat/pmwin.h  --  GCC 9 compatibility shim for pmwin.h
 *
 * Some header in the pm.h chain undefines EXPENTRY before pmwin.h is
 * included, leaving it bare.  GCC 9 on ArcaOS does not recognise EXPENTRY
 * as a built-in calling-convention keyword (it was an IBM VAC extension),
 * so function declarations at pmwin.h:2153+ fail to parse.
 *
 * This file is placed on the include path BEFORE /usr/include via
 * -I.../os2_compat in Makefile.os2.  When pm.h does #include <pmwin.h>,
 * GCC finds this shim first.  We nullify EXPENTRY (IBM VAC-only keyword
 * that GCC 9 rejects), then hand off to the real header via #include_next.
 * _System is left intact — GCC 9 on ArcaOS understands it as a calling
 * convention attribute (no underscore prefix in OMF), which is required so
 * PM/GPI/Dev exports resolve correctly against PMWIN.DLL / PMGRE.DLL.
 */
#undef  EXPENTRY
#define EXPENTRY
#undef  _Optlink
#define _Optlink

#include_next <pmwin.h>
