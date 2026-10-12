@echo off
rem Developer helper (not needed to use the library): sets the build environment
rem for commands run over ssh on the dev VM.  Adjust the paths to your setup.
rem run.cmd <demo> -- start demos\<demo>\<demo>.exe detached (cwd = its directory)
D:
cd \Projects\LIBs\Mesa-7.11.2\demos\%1
detach %1.exe
