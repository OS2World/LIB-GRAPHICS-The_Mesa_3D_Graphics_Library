@echo off
rem ===================================================================
rem compile.cmd  --  Mesa 7.11.2 OS/2 (ArcaOS) static library build
rem
rem Run from the Mesa root directory (where this file lives):
rem   C:\Temporal\1.- OS2\Projects\LIBs\Mesa-7.11.2\compile.cmd
rem
rem Prerequisites (install via ANPM):
rem   gcc / g++ 9.x, make (GNU make), ar
rem   OS/2 Toolkit headers  (os2.h, pmwin.h, pm.h, ...)
rem
rem Outputs (relative to Mesa root):
rem   obj_os2\*.o    -- OMF object files
rem   lib\MesaGL7.a  -- static library
rem ===================================================================

rem --- GCC / WLINK environment ----------------------------------------
set EMXOMFLD_TYPE=WLINK
set EMXOMFLD_LINKER=wl.exe
set EMXOMFLD_PRELINK=0

rem --- OS/2 Toolkit include path --------------------------------------
set OS2TK=/usr/include

echo Mesa 7.11.2 OS/2 build  --  %DATE%  %TIME%
echo OS2TK: %OS2TK%
echo.

rem --- Create output directories if missing ---------------------------
if not exist obj_os2 md obj_os2
if not exist lib md lib

rem --- Launch GNU make, show output live and save to compile.log ------
make -f Makefile.os2 static OS2TK=%OS2TK% 2>&1 | tee compile.log

echo.
echo Full log: compile.log
