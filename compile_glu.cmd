@echo off
rem ===================================================================
rem compile_glu.cmd  --  Mesa 7.11.2 libGLU for ArcaOS
rem
rem Run from the Mesa root directory (where this file lives):
rem   C:\Temporal\1.- OS2\Projects\LIBs\Mesa-7.11.2\compile_glu.cmd
rem
rem Prerequisites: gcc/g++ 9.x, make (GNU make), ar, wl.exe (WLINK)
rem
rem Outputs (relative to Mesa root):
rem   obj_glu\*.o       -- OMF object files
rem   lib\libGLU7.a     -- static library
rem   dll\libGLU7.dll   -- OS/2 DLL
rem   dll\libGLU7.map   -- link map
rem ===================================================================

rem --- GCC / WLINK environment ----------------------------------------
set EMXOMFLD_TYPE=WLINK
set EMXOMFLD_LINKER=wl.exe
set EMXOMFLD_PRELINK=0

echo Mesa 7.11.2 libGLU build  --  %DATE%  %TIME%
echo.

rem --- Create output directories if missing ---------------------------
if not exist obj_glu md obj_glu
if not exist lib md lib
if not exist dll md dll

rem --- Phase 1: clean old objects, compile + static lib ---------------
echo === Phase 1: clean + compile + static lib ===
make -f Makefile.os2glu clean 2>&1 | tee compile_glu.log
make -f Makefile.os2glu static 2>&1 | tee -a compile_glu.log

rem --- Phase 2: link DLL via WLINK response file ----------------------
echo.
echo === Phase 2: link DLL ===
make -f Makefile.os2glu dll 2>&1 | tee -a compile_glu.log

echo.
echo Full log: compile_glu.log
