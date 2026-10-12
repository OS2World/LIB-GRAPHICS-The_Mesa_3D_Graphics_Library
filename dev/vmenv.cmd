@echo off
rem Developer helper (not needed to use the library): sets the build environment
rem for commands run over ssh on the dev VM.  Adjust the paths to your setup.
set UNIXROOT=C:
set PATH=C:\usr\bin;%PATH%
set C_INCLUDE_PATH=C:/usr/include;C:/usr/include/os2tk45
set LIBRARY_PATH=C:/usr/lib
D:
cd \Projects\LIBs\Mesa-7.11.2\demos\glutcube
%1 %2 %3 %4 %5 %6 %7 %8 %9
