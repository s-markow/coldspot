BUILD_PATH = engine/bin

TARGET = cs-engine.dll
DEFINES = -D_DEBUG -DCSEXPORT -D_CRT_SECURE_NO_WARNINGS
IFLAGS = -Iengine\code -I$(VULKAN_SDK)\include
LFLAGS = -g -shared -luser32 -lvulkan-1 -Lobj\engine -L$(VULKAN_SDK)\lib

recursive_wildcard = $(wildcard $1$2) $(foreach d, $(wildcard $1*), $(call recursive_wildcard, $d/,$2))

SRC = $(call recursive_wildcard, $(TARGET)/, *.c )
DIR = \engine\src $(subst $(subst /,\,${CURDIR}),, $(shell dir \engine\src /S /AD /B | findstr /i src ) )