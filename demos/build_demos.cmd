@echo off
rem build_demos.cmd -- build the Mesa demos (gears, shapes, texture) against the
rem Mesa DLL import libraries.  Run from Mesa-7.11.2\demos\   Log: build_demos.log
rem Needs the DLLs and lib\*_imp.a from build_dlls.cmd / compile_glutcube.cmd.
set MESA_ROOT=..\
set EMXOMFLD_TYPE=WLINK
set EMXOMFLD_LINKER=wl.exe
set EMXOMFLD_PRELINK=0
set IMPLIBS=%MESA_ROOT%lib\libGLUT7_imp.a %MESA_ROOT%lib\MesaGL7_imp.a %MESA_ROOT%lib\libGLU7_imp.a

echo Mesa demos build -- %DATE% %TIME% > build_demos.log
echo === gears === >> build_demos.log
gcc -Wall -O2 -fno-builtin-sinf -fno-builtin-cosf -fno-builtin-sin -fno-builtin-cos -Zomf -c gears\gears.c -o gears\gears.o -I%MESA_ROOT%include 2>&1 | tee -a build_demos.log
gcc -Zomf -o gears\gears.exe gears\gears.def gears\gears.o %IMPLIBS% -lm 2>&1 | tee -a build_demos.log
if exist gears\gears.exe ( echo built: gears\gears.exe >> build_demos.log ) else ( echo FAILED: gears >> build_demos.log )
copy %MESA_ROOT%dll\*.dll gears\ > nul
echo === shapes === >> build_demos.log
gcc -Wall -O2 -fno-builtin-sinf -fno-builtin-cosf -fno-builtin-sin -fno-builtin-cos -Zomf -c shapes\shapes.c -o shapes\shapes.o -I%MESA_ROOT%include 2>&1 | tee -a build_demos.log
gcc -Zomf -o shapes\shapes.exe shapes\shapes.def shapes\shapes.o %IMPLIBS% -lm 2>&1 | tee -a build_demos.log
if exist shapes\shapes.exe ( echo built: shapes\shapes.exe >> build_demos.log ) else ( echo FAILED: shapes >> build_demos.log )
copy %MESA_ROOT%dll\*.dll shapes\ > nul
echo === texture === >> build_demos.log
gcc -Wall -O2 -fno-builtin-sinf -fno-builtin-cosf -fno-builtin-sin -fno-builtin-cos -Zomf -c texture\texture.c -o texture\texture.o -I%MESA_ROOT%include 2>&1 | tee -a build_demos.log
gcc -Zomf -o texture\texture.exe texture\texture.def texture\texture.o %IMPLIBS% -lm 2>&1 | tee -a build_demos.log
if exist texture\texture.exe ( echo built: texture\texture.exe >> build_demos.log ) else ( echo FAILED: texture >> build_demos.log )
copy %MESA_ROOT%dll\*.dll texture\ > nul
echo === osmesa === >> build_demos.log
gcc -Wall -O2 -fno-builtin-sinf -fno-builtin-cosf -fno-builtin-sin -fno-builtin-cos -Zomf -c osmesa\osmesa_test.c -o osmesa\osmesa_test.o -I%MESA_ROOT%include 2>&1 | tee -a build_demos.log
gcc -Zomf -o osmesa\osmesa_test.exe osmesa\osmesa_test.o %IMPLIBS% -lm 2>&1 | tee -a build_demos.log
if exist osmesa\osmesa_test.exe ( echo built: osmesa\osmesa_test.exe >> build_demos.log ) else ( echo FAILED: osmesa >> build_demos.log )
copy %MESA_ROOT%dll\*.dll osmesa\ > nul
echo === osdive === >> build_demos.log
gcc -Wall -O2 -fno-builtin-sinf -fno-builtin-cosf -fno-builtin-sin -fno-builtin-cos -Zomf -c osdive\osdive.c -o osdive\osdive.o -I%MESA_ROOT%include 2>&1 | tee -a build_demos.log
gcc -Zomf -o osdive\osdive.exe osdive\osdive.def osdive\osdive.o %IMPLIBS% -L%UNIXROOT%/os2tk45/lib -lmmpm2 -lm 2>&1 | tee -a build_demos.log
if exist osdive\osdive.exe ( echo built: osdive\osdive.exe >> build_demos.log ) else ( echo FAILED: osdive >> build_demos.log )
copy %MESA_ROOT%dll\*.dll osdive\ > nul
echo Done >> build_demos.log
echo Log: build_demos.log
