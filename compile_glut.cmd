@echo off
rem ===================================================================
rem compile_glut.cmd  --  Mesa 7.11.2 GLUT for ArcaOS
rem
rem Run from the Mesa root directory:
rem   C:\Temporal\1.- OS2\Projects\LIBs\Mesa-7.11.2\compile_glut.cmd
rem
rem Prerequisites: gcc 9.x, make (GNU make), ar, wl.exe (WLINK)
rem
rem Outputs (relative to Mesa root):
rem   obj_glut\*.o       -- OMF object files
rem   lib\libGLUT7.a     -- static library
rem   dll\libGLUT7.dll   -- OS/2 DLL
rem   dll\libGLUT7.map   -- link map
rem ===================================================================

rem --- GCC / WLINK environment ----------------------------------------
set EMXOMFLD_TYPE=WLINK
set EMXOMFLD_LINKER=wl.exe
set EMXOMFLD_PRELINK=0

echo Mesa 7.11.2 GLUT build  --  %DATE%  %TIME%
echo.

rem --- Create output directories if missing ---------------------------
if not exist obj_glut md obj_glut
if not exist lib     md lib
if not exist dll     md dll

rem --- Phase 1: clean old objects, compile + static lib ---------------
echo === Phase 1: clean + compile + static lib ===
make -f Makefile.os2glut clean 2>&1 | tee compile_glut.log
make -f Makefile.os2glut static 2>&1 | tee -a compile_glut.log

rem --- Phase 2: link DLL via WLINK response file ----------------------
echo.
echo === Phase 2: link DLL ===
make -f Makefile.os2glut dll 2>&1 | tee -a compile_glut.log

echo.
echo Full log: compile_glut.log
