@echo off
rem link_dlls.cmd -- link-only step (objects already compiled by build_dlls.cmd)
rem Log: link_dlls.log
set EMXOMFLD_TYPE=WLINK
set EMXOMFLD_LINKER=wl.exe
set EMXOMFLD_PRELINK=0
echo DLL link -- %DATE% %TIME% > link_dlls.log
if not exist dll md dll

echo === MesaGL7 === >> link_dlls.log
gcc -Zomf -Zdll -Zmap=dll/MesaGL7 -o dll/MesaGL7.dll @mesagl.rsp MesaGL7.def -lstdc++ -los2 -lm 2>&1 | tee -a link_dlls.log
emximp -o lib/MesaGL7_imp.a MesaGL7_imp.def 2>&1 | tee -a link_dlls.log

echo === libGLU7 === >> link_dlls.log
gcc -Zomf -Zdll -Zmap=dll/libGLU7 -o dll/libGLU7.dll @glu.rsp libGLU7.def lib/MesaGL7_imp.a -lstdc++ -los2 -lm 2>&1 | tee -a link_dlls.log
emximp -o lib/libGLU7_imp.a libGLU7_imp.def 2>&1 | tee -a link_dlls.log

echo === libGLUT7 === >> link_dlls.log
gcc -Zomf -Zdll -Zmap=dll/libGLUT7 -o dll/libGLUT7.dll @glut.rsp libGLUT7.def lib/libGLU7_imp.a lib/MesaGL7_imp.a -lstdc++ -los2 -lm 2>&1 | tee -a link_dlls.log
emximp -o lib/libGLUT7_imp.a libGLUT7_imp.def 2>&1 | tee -a link_dlls.log

echo === Done === >> link_dlls.log
dir dll\*.dll >> link_dlls.log
echo Log: link_dlls.log