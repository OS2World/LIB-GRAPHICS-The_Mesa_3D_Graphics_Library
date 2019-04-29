# Makefile
# Created by IBM WorkFrame/2 MakeMake at 18:57:39 on 13 Dec 2002
#
# The actions included in this make file are:
#  Compile::C++ Compiler
#  Lib::Library Tool

.SUFFIXES:

.SUFFIXES: \
    .cpp .obj 

.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /I..\ /I..\X86 /I..\GL /Ss /Wlanobsordprorearettruund /Ti /O /Gm /G5 /Tm /Gf /Gi /Oi /C %s

{G:\EVGEN\MESA5\math}.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /I..\ /I..\X86 /I..\GL /Ss /Wlanobsordprorearettruund /Ti /O /Gm /G5 /Tm /Gf /Gi /Oi /C %s

all: \
    .\libMesaMath.lib

.\libMesaMath.lib: \
    .\m_vector.obj \
    .\m_translate.obj \
    .\m_xform.obj \
    .\m_eval.obj \
    .\m_matrix.obj
    @echo " Lib::Library Tool "
    ilib.exe  /nol /noi libMesaMath.lib @Makefile.rf;

.\m_vector.obj: \
    G:\EVGEN\MESA5\math\m_vector.cpp \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}m_matrix.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}GL/gl.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}math/m_vector.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}GL/os2_x11.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}Xthreads.h

.\m_translate.obj: \
    G:\EVGEN\MESA5\math\m_translate.cpp \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}m_matrix.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}m_translate.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}GL/gl.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}GL/os2_x11.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}m_trans_tmp.h

.\m_matrix.obj: \
    G:\EVGEN\MESA5\math\m_matrix.cpp \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}m_matrix.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}GL/gl.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}GL/os2_x11.h

.\m_eval.obj: \
    G:\EVGEN\MESA5\math\m_eval.cpp \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}m_eval.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}GL/gl.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}GL/os2_x11.h

.\m_xform.obj: \
    G:\EVGEN\MESA5\math\m_xform.cpp \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}m_eval.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}m_matrix.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}m_translate.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}m_xform.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}mathmod.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}m_debug.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}X86/common_x86_asm.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}m_xform_tmp.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}m_clip_tmp.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}m_norm_tmp.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}m_dotprod_tmp.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}m_copy_tmp.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}GL/gl.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}math/m_vector.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}common_x86_features.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}x86.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}3dnow.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}sse.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}GL/os2_x11.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\math;..\;..\X86;..\GL;$(INCLUDE);}Xthreads.h
