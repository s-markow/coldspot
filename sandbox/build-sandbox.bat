@echo off
setlocal EnableDelayedExpansion

set target=sandbox
set cflags=-g
set includes=-Icode -I../engine/code/
set lflags=-L../engine/bin/ -lcs-engine.lib
set defines=-D_DEBUG -DCSIMPORT

set cfiles=
for /R %%f in (*.c) do (
    set cfiles=!cfiles! %%f && echo %%f
)

echo start building %target%
clang %cfiles% %cflags% -o bin/%target%.exe %defines% %includes% %lflags%