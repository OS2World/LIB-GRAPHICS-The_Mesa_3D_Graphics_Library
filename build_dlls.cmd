@echo off
rem build_dlls.cmd -- full rebuild of MesaGL7 / libGLU7 / libGLUT7 (kLIBC DLLs)
rem Phase 1 compiles all three libraries from scratch; phase 2 calls
rem link_dlls.cmd (gcc -Zdll + emximp from the *_imp.def files).
rem Run from the Mesa root directory.  Logs: build_dlls.log, link_dlls.log
set EMXOMFLD_TYPE=WLINK
set EMXOMFLD_LINKER=wl.exe
set EMXOMFLD_PRELINK=0
set OS2TK=/usr/include

echo Mesa DLL rebuild -- %DATE% %TIME% > build_dlls.log
if not exist obj_os2 md obj_os2
if not exist obj_glu md obj_glu
if not exist obj_glut md obj_glut
if not exist lib md lib
if not exist dll md dll

echo === MesaGL7: compile === >> build_dlls.log
make -f Makefile.os2 clean 2>&1 | tee -a build_dlls.log
make -f Makefile.os2 static OS2TK=%OS2TK% 2>&1 | tee -a build_dlls.log

echo === libGLU7: compile === >> build_dlls.log
make -f Makefile.os2glu clean 2>&1 | tee -a build_dlls.log
make -f Makefile.os2glu static 2>&1 | tee -a build_dlls.log

echo === libGLUT7: compile === >> build_dlls.log
make -f Makefile.os2glut clean 2>&1 | tee -a build_dlls.log
make -f Makefile.os2glut static 2>&1 | tee -a build_dlls.log

echo === link === >> build_dlls.log
call link_dlls.cmd
type link_dlls.log >> build_dlls.log

echo === Done === >> build_dlls.log
echo Log: build_dlls.log