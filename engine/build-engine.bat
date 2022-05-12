@echo off
setlocal EnableDelayedExpansion

set includes=-Icode -I%VULKAN_SDK%/include
set libs=-L%VULKAN_SDK%/lib
set cflags=-g -shared -Wvarargs -Wall -Werror %includes%
set lflags=-luser32 -lvulkan-1 %libs% -Xlinker /SUBSYSTEM:WINDOWS
set defines=-D_DEBUG -DCSEXPORT -D_CRT_SECURE_NO_WARNINGS
set target=cs-engine
set cfiles=
for /R %%f in (*.c) do (
    set cfiles=!cfiles! %%f && echo %%f
)

echo start building %target%
clang %cfiles% %cflags% -o bin/%target%.dll %defines% %lflags%