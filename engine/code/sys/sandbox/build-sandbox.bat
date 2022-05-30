@echo off
setlocal EnableDelayedExpansion

set target=sandbox
set cflags=-g
set includes=-Icode -I../engine/code/
set lflags=-L../engine/bin/ -lcs-engine.lib
set defines=-D_DEBUG

set cfiles=
for /R %%f in (*.c) do (
    set cfiles=!cfiles! %%f && echo %%f
)

:: no error dialog about missing dll showing up when running from PowerShell, notify here..
if not exist "bin\cs-engine.dll" (
    echo [35mcs-engine.dll not found, copy the file into sandbox\bin folder before running sandbox[0m
)
if not exist "bin\vulkan-1.dll" (
    echo [35mvulkan-1.dll not found, copy the file into sandbox\bin folder before running sandbox[0m
)

echo start building %target%
clang %cfiles% %cflags% -o bin/%target%.exe %defines% %includes% %lflags%