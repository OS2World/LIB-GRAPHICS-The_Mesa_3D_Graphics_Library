# makefile
# Created by IBM WorkFrame/2 MakeMake at 14:42:53 on 19 Dec 2002
#
# The actions included in this make file are:
#  Compile::C++ Compiler
#  Link::Linker
#  Lib::Import Lib

.SUFFIXES:

.SUFFIXES: \
    .DLL .LIB .cpp .obj 

.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /IGL /Iswrast /Itnl /Ss /Wpro /Tx /Fi /Si /O /Gm /Ge- /G5 /Gf /Gi /Oi /Gu /C %s

{G:\EVGEN\MESA5\MesaDLL}.cpp.obj:
    @echo " Compile::C++ Compiler "
    icc.exe /IGL /Iswrast /Itnl /Ss /Wpro /Tx /Fi /Si /O /Gm /Ge- /G5 /Gf /Gi /Oi /Gu /C %s

.DLL.LIB:
    @echo " Lib::Import Lib "
    implib.exe %|dpfF.LIB %s

{G:\EVGEN\MESA5\MesaDLL}.DLL.LIB:
    @echo " Lib::Import Lib "
    implib.exe %|dpfF.LIB %s

all: \
    .\MesaGL2.LIB

.\MesaGL2.DLL: \
    .\vtxfmt.obj \
    .\WarpWin.obj \
    .\accum.obj \
    .\api_arrayelt.obj \
    .\api_eval.obj \
    .\api_loopback.obj \
    .\api_noop.obj \
    .\api_validate.obj \
    .\attrib.obj \
    .\a_debug.obj \
    .\blend.obj \
    .\buffers.obj \
    .\clip.obj \
    .\colortab.obj \
    .\context.obj \
    .\convolve.obj \
    .\debug.obj \
    .\depth.obj \
    .\dispatch.obj \
    .\dlist.obj \
    .\drawpix.obj \
    .\enable.obj \
    .\enums.obj \
    .\eval.obj \
    .\extensions.obj \
    .\feedback.obj \
    .\fog.obj \
    .\get.obj \
    .\glapi.obj \
    .\glthread.obj \
    .\glu.obj \
    .\glut_9x15.obj \
    .\glut_bitmap.obj \
    .\glut_cindex.obj \
    .\glut_cmap.obj \
    .\glut_event.obj \
    .\glut_gamemode.obj \
    .\glut_get.obj \
    .\glut_init.obj \
    .\glut_key.obj \
    .\glut_mesa.obj \
    .\glut_swap.obj \
    .\glut_util.obj \
    .\glut_win.obj \
    .\hash.obj \
    .\hint.obj \
    .\histogram.obj \
    .\image.obj \
    .\imports.obj \
    .\light.obj \
    .\lines.obj \
    .\matrix.obj \
    .\mmath.obj \
    .\os2mesa.obj \
    .\os2mesaDive.obj \
    .\os2wgl.obj \
    .\os2_glx.obj \
    .\os2_winproc.obj \
    .\pixel.obj \
    .\points.obj \
    .\polygon.obj \
    .\quadric.obj \
    .\rastpos.obj \
    .\snprintf.obj \
    .\state.obj \
    .\stencil.obj \
    .\texcompress.obj \
    .\texformat.obj \
    .\teximage.obj \
    .\texobj.obj \
    .\texstate.obj \
    .\texstore.obj \
    .\texutil.obj \
    .\varray.obj \
    .\vpexec.obj \
    .\vpparse.obj \
    .\vpstate.obj \
    ..\math\libMesaMath.lib \
    ..\swrast\SwRast.lib \
    ..\swrast_setup\SwRastSetup.lib \
    ..\array_cache\libMesaAC.lib \
    ..\tnl\libMesaTnl.lib \
    {$(LIB)}MMPM2.lib \
    {$(LIB)}MesaGL2.DEF
    @echo " Link::Linker "
    icc.exe @<<
     /B" /exepack:2 /st:200000 /pmtype:pm /packd /optfunc"
     /FeMesaGL2.DLL 
     ..\math\libMesaMath.lib 
     ..\swrast\SwRast.lib 
     ..\swrast_setup\SwRastSetup.lib 
     ..\array_cache\libMesaAC.lib 
     ..\tnl\libMesaTnl.lib 
     MMPM2.lib 
     MesaGL2.DEF
     .\vtxfmt.obj
     .\WarpWin.obj
     .\accum.obj
     .\api_arrayelt.obj
     .\api_eval.obj
     .\api_loopback.obj
     .\api_noop.obj
     .\api_validate.obj
     .\attrib.obj
     .\a_debug.obj
     .\blend.obj
     .\buffers.obj
     .\clip.obj
     .\colortab.obj
     .\context.obj
     .\convolve.obj
     .\debug.obj
     .\depth.obj
     .\dispatch.obj
     .\dlist.obj
     .\drawpix.obj
     .\enable.obj
     .\enums.obj
     .\eval.obj
     .\extensions.obj
     .\feedback.obj
     .\fog.obj
     .\get.obj
     .\glapi.obj
     .\glthread.obj
     .\glu.obj
     .\glut_9x15.obj
     .\glut_bitmap.obj
     .\glut_cindex.obj
     .\glut_cmap.obj
     .\glut_event.obj
     .\glut_gamemode.obj
     .\glut_get.obj
     .\glut_init.obj
     .\glut_key.obj
     .\glut_mesa.obj
     .\glut_swap.obj
     .\glut_util.obj
     .\glut_win.obj
     .\hash.obj
     .\hint.obj
     .\histogram.obj
     .\image.obj
     .\imports.obj
     .\light.obj
     .\lines.obj
     .\matrix.obj
     .\mmath.obj
     .\os2mesa.obj
     .\os2mesaDive.obj
     .\os2wgl.obj
     .\os2_glx.obj
     .\os2_winproc.obj
     .\pixel.obj
     .\points.obj
     .\polygon.obj
     .\quadric.obj
     .\rastpos.obj
     .\snprintf.obj
     .\state.obj
     .\stencil.obj
     .\texcompress.obj
     .\texformat.obj
     .\teximage.obj
     .\texobj.obj
     .\texstate.obj
     .\texstore.obj
     .\texutil.obj
     .\varray.obj
     .\vpexec.obj
     .\vpparse.obj
     .\vpstate.obj
<<

.\vtxfmt.obj: \
    G:\EVGEN\MESA5\MesaDLL\vtxfmt.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}state.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}api_loopback.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}vtxfmt.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}vtxfmt_tmp.h

.\vpstate.obj: \
    G:\EVGEN\MESA5\MesaDLL\vpstate.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}hash.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}vpstate.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}vpexec.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}vpparse.h

.\vpparse.obj: \
    G:\EVGEN\MESA5\MesaDLL\vpparse.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}hash.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}vpparse.h

.\vpexec.obj: \
    G:\EVGEN\MESA5\MesaDLL\vpexec.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}vpexec.h

.\varray.obj: \
    G:\EVGEN\MESA5\MesaDLL\varray.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}state.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}light.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enums.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texstate.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dlist.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}varray.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_translate.h

.\texutil.obj: \
    G:\EVGEN\MESA5\MesaDLL\texutil.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enums.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}image.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texformat.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texutil.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texutil_tmp.h

.\texstore.obj: \
    G:\EVGEN\MESA5\MesaDLL\texstore.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}image.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}teximage.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}convolve.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texcompress.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texformat.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texstore.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texutil.h

.\texstate.obj: \
    G:\EVGEN\MESA5\MesaDLL\texstate.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enums.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texobj.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texstate.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_xform.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_vector.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}extensions.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}teximage.h

.\texobj.obj: \
    G:\EVGEN\MESA5\MesaDLL\texobj.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enums.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texobj.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texstate.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colortab.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}hash.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}teximage.h

.\teximage.obj: \
    G:\EVGEN\MESA5\MesaDLL\teximage.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}state.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texstate.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}image.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}teximage.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}convolve.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texcompress.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texformat.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texstore.h

.\texformat.obj: \
    G:\EVGEN\MESA5\MesaDLL\texformat.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texstate.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}image.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}teximage.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texformat.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texformat_tmp.h

.\texcompress.obj: \
    G:\EVGEN\MESA5\MesaDLL\texcompress.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}image.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texcompress.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texformat.h

.\stencil.obj: \
    G:\EVGEN\MESA5\MesaDLL\stencil.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}depth.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}stencil.h

.\state.obj: \
    G:\EVGEN\MESA5\MesaDLL\state.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}accum.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}state.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}api_loopback.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}light.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}attrib.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}blend.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}buffers.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}depth.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}fog.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}hint.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}lines.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}points.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}polygon.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}stencil.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texobj.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texstate.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_xform.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_vector.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}clip.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colortab.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dlist.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}eval.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}get.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}teximage.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}varray.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}vpstate.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}convolve.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}feedback.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}histogram.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}pixel.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}drawpix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}rastpos.h

.\snprintf.obj: \
    G:\EVGEN\MESA5\MesaDLL\snprintf.cpp \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h

.\rastpos.obj: \
    G:\EVGEN\MESA5\MesaDLL\rastpos.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}state.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}light.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}simple_list.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_xform.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_vector.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}clip.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}feedback.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}rastpos.h

.\quadric.obj: \
    G:\EVGEN\MESA5\MesaDLL\quadric.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glu.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glu_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}all.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gluP.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}nurbs.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}tess.h

.\polygon.obj: \
    G:\EVGEN\MESA5\MesaDLL\polygon.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enums.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}polygon.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}image.h

.\points.obj: \
    G:\EVGEN\MESA5\MesaDLL\points.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}points.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texstate.h

.\pixel.obj: \
    G:\EVGEN\MESA5\MesaDLL\pixel.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}pixel.h

.\os2_winproc.obj: \
    G:\EVGEN\MESA5\MesaDLL\os2_winproc.cpp \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpWin.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpGL.h \
    GL\os2_x11.h \
    GL\gl.h \
    GL\glut.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glu.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glu_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutint.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutwin32.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_x11.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_glx.h \
    gl\os2mesa.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2mesadef.h

.\os2_glx.obj: \
    G:\EVGEN\MESA5\MesaDLL\os2_glx.cpp \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpWin.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpGL.h \
    GL\os2_x11.h \
    GL\gl.h \
    GL\glut.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glu.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glu_mangle.h \
    gl\os2mesa.h

.\os2wgl.obj: \
    G:\EVGEN\MESA5\MesaDLL\os2wgl.cpp \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpWin.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpGL.h \
    GL\os2_x11.h \
    GL\gl.h \
    GL\glut.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glu.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glu_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    gl\os2mesa.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2mesadef.h

.\os2mesaDive.obj: \
    G:\EVGEN\MESA5\MesaDLL\os2mesaDive.cpp \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpWin.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpGL.h \
    GL\os2_x11.h \
    GL\gl.h \
    GL\glut.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glu.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glu_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}depth.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutint.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutwin32.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_x11.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_glx.h \
    gl\os2mesa.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2mesadef.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}malloc.h

.\os2mesa.obj: \
    G:\EVGEN\MESA5\MesaDLL\os2mesa.cpp \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpWin.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpGL.h \
    GL\os2_x11.h \
    GL\gl.h \
    GL\glut.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glu.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glu_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_xform.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_vector.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}extensions.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutint.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutwin32.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_x11.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_glx.h \
    gl\os2mesa.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2mesadef.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colors.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texformat.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texstore.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}array_cache/acache.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}swrast_setup/swrast_setup.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}swrast/s_alphabuf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}tnl/tnl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}tnl/t_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}tnl/t_pipeline.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}swrast/swrast.h

.\mmath.obj: \
    G:\EVGEN\MESA5\MesaDLL\mmath.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h

.\matrix.obj: \
    G:\EVGEN\MESA5\MesaDLL\matrix.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}buffers.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enums.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}matrix.h

.\lines.obj: \
    G:\EVGEN\MESA5\MesaDLL\lines.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}depth.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}lines.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texstate.h

.\light.obj: \
    G:\EVGEN\MESA5\MesaDLL\light.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}light.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enums.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}simple_list.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_xform.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_vector.h

.\imports.obj: \
    G:\EVGEN\MESA5\MesaDLL\imports.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h

.\image.obj: \
    G:\EVGEN\MESA5\MesaDLL\image.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}image.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}histogram.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}pixel.h

.\histogram.obj: \
    G:\EVGEN\MESA5\MesaDLL\histogram.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}image.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}histogram.h

.\hint.obj: \
    G:\EVGEN\MESA5\MesaDLL\hint.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enums.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}hint.h

.\hash.obj: \
    G:\EVGEN\MESA5\MesaDLL\hash.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}hash.h

.\glut_win.obj: \
    G:\EVGEN\MESA5\MesaDLL\glut_win.cpp \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpWin.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpGL.h \
    GL\os2_x11.h \
    GL\gl.h \
    GL\glut.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glu.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glu_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutint.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutwin32.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_x11.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_glx.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutos2.h \
    gl\os2mesa.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL_TEST.h

.\glut_util.obj: \
    G:\EVGEN\MESA5\MesaDLL\glut_util.cpp \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpWin.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpGL.h \
    GL\os2_x11.h \
    GL\gl.h \
    GL\glut.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glu.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glu_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutint.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutwin32.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_x11.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_glx.h

.\glut_swap.obj: \
    G:\EVGEN\MESA5\MesaDLL\glut_swap.cpp \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpWin.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpGL.h \
    GL\os2_x11.h \
    GL\gl.h \
    GL\glut.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glu.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glu_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutint.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutwin32.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_x11.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_glx.h

.\glut_mesa.obj: \
    G:\EVGEN\MESA5\MesaDLL\glut_mesa.cpp \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpWin.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpGL.h \
    GL\os2_x11.h \
    GL\gl.h \
    GL\glut.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glu.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glu_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutint.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutwin32.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_x11.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_glx.h

.\glut_key.obj: \
    G:\EVGEN\MESA5\MesaDLL\glut_key.cpp \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpWin.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpGL.h \
    GL\os2_x11.h \
    GL\gl.h \
    GL\glut.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glu.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glu_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutint.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutwin32.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_x11.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_glx.h

.\glut_init.obj: \
    G:\EVGEN\MESA5\MesaDLL\glut_init.cpp \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpWin.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpGL.h \
    GL\os2_x11.h \
    GL\gl.h \
    GL\glut.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glu.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glu_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutint.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutwin32.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_x11.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_glx.h

.\glut_get.obj: \
    G:\EVGEN\MESA5\MesaDLL\glut_get.cpp \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpWin.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpGL.h \
    GL\os2_x11.h \
    GL\gl.h \
    GL\glut.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glu.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glu_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutint.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutwin32.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_x11.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_glx.h

.\glut_gamemode.obj: \
    G:\EVGEN\MESA5\MesaDLL\glut_gamemode.cpp \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpWin.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpGL.h \
    GL\os2_x11.h \
    GL\gl.h \
    GL\glut.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glu.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glu_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutint.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutwin32.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_x11.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_glx.h

.\glut_event.obj: \
    G:\EVGEN\MESA5\MesaDLL\glut_event.cpp \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpWin.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpGL.h \
    GL\os2_x11.h \
    GL\gl.h \
    GL\glut.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glu.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glu_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutint.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutwin32.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_x11.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_glx.h

.\glut_cmap.obj: \
    G:\EVGEN\MESA5\MesaDLL\glut_cmap.cpp \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpWin.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpGL.h \
    GL\os2_x11.h \
    GL\gl.h \
    GL\glut.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glu.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glu_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutint.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutwin32.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_x11.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_glx.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}layerutil.h

.\glut_cindex.obj: \
    G:\EVGEN\MESA5\MesaDLL\glut_cindex.cpp \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpWin.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpGL.h \
    GL\os2_x11.h \
    GL\gl.h \
    GL\glut.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glu.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glu_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutint.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutwin32.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_x11.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_glx.h

.\glut_bitmap.obj: \
    G:\EVGEN\MESA5\MesaDLL\glut_bitmap.cpp \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpWin.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpGL.h \
    GL\os2_x11.h \
    GL\gl.h \
    GL\glut.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glu.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glu_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutbitmap.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutint.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutwin32.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_x11.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}win32_glx.h

.\glut_9x15.obj: \
    G:\EVGEN\MESA5\MesaDLL\glut_9x15.cpp \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glutbitmap.h

.\glu.obj: \
    G:\EVGEN\MESA5\MesaDLL\glu.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glu.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glu_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}all.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gluP.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}nurbs.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}tess.h

.\glthread.obj: \
    G:\EVGEN\MESA5\MesaDLL\glthread.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h

.\glapi.obj: \
    G:\EVGEN\MESA5\MesaDLL\glapi.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitemp.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapioffsets.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glprocs.h

.\get.obj: \
    G:\EVGEN\MESA5\MesaDLL\get.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enums.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}extensions.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}get.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texcompress.h

.\fog.obj: \
    G:\EVGEN\MESA5\MesaDLL\fog.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}fog.h

.\feedback.obj: \
    G:\EVGEN\MESA5\MesaDLL\feedback.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enums.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}feedback.h

.\extensions.obj: \
    G:\EVGEN\MESA5\MesaDLL\extensions.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}simple_list.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}extensions.h

.\eval.obj: \
    G:\EVGEN\MESA5\MesaDLL\eval.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}eval.h

.\enums.obj: \
    G:\EVGEN\MESA5\MesaDLL\enums.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enums.h

.\enable.obj: \
    G:\EVGEN\MESA5\MesaDLL\enable.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}light.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enums.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}simple_list.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_xform.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_vector.h

.\drawpix.obj: \
    G:\EVGEN\MESA5\MesaDLL\drawpix.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}state.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}feedback.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}drawpix.h

.\dlist.obj: \
    G:\EVGEN\MESA5\MesaDLL\dlist.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}state.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}api_loopback.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}light.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}attrib.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}blend.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}buffers.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}depth.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enums.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}lines.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}points.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}polygon.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texobj.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texstate.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_xform.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_vector.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}clip.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colortab.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}image.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dlist.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}eval.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}extensions.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}get.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}hash.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}teximage.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}varray.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}vpstate.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}convolve.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}feedback.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}histogram.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}pixel.h

.\dispatch.obj: \
    G:\EVGEN\MESA5\MesaDLL\dispatch.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitemp.h

.\depth.obj: \
    G:\EVGEN\MESA5\MesaDLL\depth.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}depth.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enums.h

.\debug.obj: \
    G:\EVGEN\MESA5\MesaDLL\debug.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}debug.h

.\convolve.obj: \
    G:\EVGEN\MESA5\MesaDLL\convolve.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}state.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}image.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}convolve.h

.\context.obj: \
    G:\EVGEN\MESA5\MesaDLL\context.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}state.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}light.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}buffers.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enums.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}fog.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}simple_list.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texobj.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texstate.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_xform.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_vector.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}clip.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colortab.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dlist.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}eval.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}extensions.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}get.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}hash.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}teximage.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}varray.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}vpstate.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}vtxfmt.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_translate.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/mathmod.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_wrapper.h

.\colortab.obj: \
    G:\EVGEN\MESA5\MesaDLL\colortab.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}state.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colortab.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}image.h

.\clip.obj: \
    G:\EVGEN\MESA5\MesaDLL\clip.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_xform.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_vector.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}clip.h

.\buffers.obj: \
    G:\EVGEN\MESA5\MesaDLL\buffers.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}accum.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}state.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}buffers.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}depth.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enums.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}stencil.h

.\blend.obj: \
    G:\EVGEN\MESA5\MesaDLL\blend.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}blend.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enums.h

.\a_debug.obj: \
    G:\EVGEN\MESA5\MesaDLL\a_debug.cpp

.\attrib.obj: \
    G:\EVGEN\MESA5\MesaDLL\attrib.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}accum.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}light.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}attrib.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}blend.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}buffers.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}depth.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}enums.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}fog.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}hint.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}lines.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}points.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}polygon.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}simple_list.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}stencil.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texobj.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}texstate.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_xform.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_vector.h

.\api_validate.obj: \
    G:\EVGEN\MESA5\MesaDLL\api_validate.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}state.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}api_validate.h

.\api_noop.obj: \
    G:\EVGEN\MESA5\MesaDLL\api_noop.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}api_noop.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}api_validate.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}light.h

.\api_loopback.obj: \
    G:\EVGEN\MESA5\MesaDLL\api_loopback.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}colormac.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}api_loopback.h

.\api_eval.obj: \
    G:\EVGEN\MESA5\MesaDLL\api_eval.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}api_eval.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mmath.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_eval.h

.\api_arrayelt.obj: \
    G:\EVGEN\MESA5\MesaDLL\api_arrayelt.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}api_arrayelt.h

.\accum.obj: \
    G:\EVGEN\MESA5\MesaDLL\accum.cpp \
    GL\os2_x11.h \
    GL\gl.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glheader.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}accum.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}imports.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}macros.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}state.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}mtypes.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}conf.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glext.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapi.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glapitable.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glthread.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}math/m_matrix.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Trace/tr_context.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}dd.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}Xthreads.h

.\WarpWin.obj: \
    G:\EVGEN\MESA5\MesaDLL\WarpWin.cpp \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpWin.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}WarpGL.h \
    GL\os2_x11.h \
    GL\gl.h \
    GL\glut.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}os2_config.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}gl_mangle.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}GL/glu.h \
    {G:\EVGEN\MESA5\MesaDLL;GL;swrast;tnl;$(INCLUDE);}glu_mangle.h

.\MesaGL2.LIB: \
    .\MesaGL2.DLL
