@echo off
rem rebuild_gl.cmd -- incremental: recompile changed Mesa/GLUT sources, relink all DLLs
rem Log: rebuild_gl.log
set EMXOMFLD_TYPE=WLINK
set EMXOMFLD_LINKER=wl.exe
set EMXOMFLD_PRELINK=0
set OS2TK=/usr/include
echo Incremental rebuild -- %DATE% %TIME% > rebuild_gl.log
make -f Makefile.os2 static OS2TK=%OS2TK% 2>&1 | tee -a rebuild_gl.log
make -f Makefile.os2glu static 2>&1 | tee -a rebuild_gl.log
make -f Makefile.os2glut static 2>&1 | tee -a rebuild_gl.log
call link_dlls.cmd
type link_dlls.log >> rebuild_gl.log
copy dll\*.dll demos\glutcube\ >> rebuild_gl.log
echo Done >> rebuild_gl.log