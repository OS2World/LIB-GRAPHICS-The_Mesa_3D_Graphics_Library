@echo off
rem ===================================================================
rem compile_mesagl.cmd  --  Mesa 7.11.2 MesaGL DLL for ArcaOS
rem
rem Run from the Mesa root directory (where this file lives):
rem   C:\Temporal\1.- OS2\Projects\LIBs\Mesa-7.11.2\compile_mesagl.cmd
rem
rem IMPORTANT: Phase 1 does a clean first to force a fresh OMF compile.
rem If you already have up-to-date OMF objects you can skip Phase 1
rem and run only:
rem   make -f Makefile.os2 dll
rem from the Mesa root.
rem
rem Prerequisites: gcc/g++ 9.x, make (GNU make), ar, wl.exe (WLINK)
rem
rem Outputs (relative to Mesa root):
rem   obj_os2\*.o    -- OMF object files
rem   lib\MesaGL7.a  -- static library
rem   dll\MesaGL7.dll  -- OS/2 DLL
rem   dll\MesaGL7.map  -- link map
rem ===================================================================

rem --- GCC / WLINK environment ----------------------------------------
set EMXOMFLD_TYPE=WLINK
set EMXOMFLD_LINKER=wl.exe
set EMXOMFLD_PRELINK=0
set OS2TK=/usr/include

echo Mesa 7.11.2 MesaGL DLL build  --  %DATE%  %TIME%
echo.

rem --- Create output directories if missing ---------------------------
if not exist obj_os2 md obj_os2
if not exist lib md lib
if not exist dll md dll

rem --- Phase 1: clean old objects, compile + static lib ---------------
echo === Phase 1: clean + compile + static lib ===
make -f Makefile.os2 clean 2>&1 | tee compile_mesagl.log
make -f Makefile.os2 static OS2TK=%OS2TK% 2>&1 | tee -a compile_mesagl.log

rem --- Phase 2: link DLL via WLINK response file ----------------------
echo.
echo === Phase 2: link DLL ===
make -f Makefile.os2 dll 2>&1 | tee -a compile_mesagl.log

echo.
echo Full log: compile_mesagl.log
