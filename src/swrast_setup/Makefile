# Makefile
# Created by IBM WorkFrame/2 MakeMake at 18:59:52 on 13 Dec 2002
#
# The actions included in this make file are:
#  Compile::C++ Compiler
#  Lib::Library Tool

.SUFFIXES:

.SUFFIXES: \
    .cpp .obj 

.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /I..\ /I..\X86 /I..\GL /I..\tnl /Ss /Wcmpcndcnscnvcpydcleffenuextgeninilanobsordparporprorearettrdtruunduni /Tx /O /Gm /G5 /Gf /Gi /Oi /C %s

{G:\EVGEN\MESA5\swrast_setup}.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /I..\ /I..\X86 /I..\GL /I..\tnl /Ss /Wcmpcndcnscnvcpydcleffenuextgeninilanobsordparporprorearettrdtruunduni /Tx /O /Gm /G5 /Gf /Gi /Oi /C %s

all: \
    .\SwRastSetup.lib

.\SwRastSetup.lib: \
    .\ss_triangle2.obj \
    .\ss_triangle1.obj \
    .\ss_vb.obj \
    .\ss_context.obj \
    .\ss_triangle.obj
    @echo " Lib::Library Tool "
    ilib.exe  /nol /noi SwRastSetup.lib @Makefile.rf;

.\ss_triangle2.obj: \
    G:\EVGEN\MESA5\swrast_setup\ss_triangle2.cpp \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}swrast/swrast.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}tnl/t_context.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}math/m_vector.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}ss_context.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}GL/gl.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}math/m_xform.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}swrast_setup.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}GL/os2_x11.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}ss_triangle.h

.\ss_triangle1.obj: \
    G:\EVGEN\MESA5\swrast_setup\ss_triangle1.cpp \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}swrast/swrast.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}tnl/t_context.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}math/m_vector.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}ss_context.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}GL/gl.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}math/m_xform.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}swrast_setup.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}GL/os2_x11.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}ss_triangle.h

.\ss_triangle.obj: \
    G:\EVGEN\MESA5\swrast_setup\ss_triangle.cpp \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}swrast/swrast.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}tnl/t_context.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}math/m_vector.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}ss_context.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}GL/gl.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}math/m_xform.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}swrast_setup.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}GL/os2_x11.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}ss_triangle.h

.\ss_context.obj: \
    G:\EVGEN\MESA5\swrast_setup\ss_context.cpp \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}swrast/swrast.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}tnl/t_context.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}math/m_vector.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}ss_context.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}ss_vb.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}GL/gl.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}math/m_xform.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}swrast_setup.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}GL/os2_x11.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}ss_triangle.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}tnl/tnl.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}tnl/t_pipeline.h

.\ss_vb.obj: \
    G:\EVGEN\MESA5\swrast_setup\ss_vb.cpp \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}swrast/swrast.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}tnl/t_context.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}math/m_vector.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}math/m_translate.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}ss_context.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}ss_vb.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}GL/gl.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}math/m_xform.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}swrast_setup.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}GL/os2_x11.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\swrast_setup;..\;..\X86;..\GL;..\tnl;$(INCLUDE);}Xthreads.h
