################################################################################
################################################################################
##
## Makefile -- project specific makefile to build an object library
##
## (C) Copyright 2006-2010 by Fujitsu Microelectronics Europe GmbH
## (C) Copyright 2010 by Fujitsu Semiconductor Europe GmbH
##
## Mandatory settings:
##
## o TOPDIR    = the toplevel directory (using slashes as path separator)
## o TARGET    = the machine qualifier to generate code for
## o SOURCES   = the list of source files to compile
## o STARTUP   = the name of the (assembler) startup file to use
## o HEADERS   = the list of local header files to install
## o PROGRAM   = the name of the executable to generate (without extension)
## o LIBRARIES = the list of library files to be linked
##
################################################################################
################################################################################

  TOPDIR = ../../..
  SUBDIR = boot/flash/booterlib

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# project specific settings
################################################################################


  SOURCES        += src/booterlib.c
  SOURCES        += src/z_lib/zlib121/inflate.c
  SOURCES        += src/z_lib/zlib121/adler32.c
  SOURCES        += src/z_lib/zlib121/crc32.c
  SOURCES        += src/z_lib/zlib121/inffast.c
  SOURCES        += src/z_lib/zlib121/inftrees.c
  SOURCES        += src/z_lib/zlib121/zutil.c
  HEADERS        += src/booterlib.h
  HEADERS        += src/z_lib/zlib121/zconf.h
  HEADERS        += src/z_lib/zlib121/zlib.h
  LIBRARY         = libbooter
  HEADER_SUBDIR   = boot
  LINTFLAGS_USER += -e923

################################################################################
# define user targets
################################################################################

default: build

clean: clean-objects clean-library

build: headers build-objects build-library

headers: install-headers

install: build install-library

all: clean build install

################################################################################
# include internal definitions and rules
################################################################################

  RELEASE_SUBDIR = $(SUBDIR)
  RELEASE_FILES += $(wildcard src/*.c)
  RELEASE_FILES += $(wildcard src/*.h)
  RELEASE_FILES += $(wildcard src/z_lib/zlib121/*.c)
  RELEASE_FILES += $(wildcard src/z_lib/zlib121/*.h)
  RELEASE_FILES += Makefile

release: doc release-files

doc:

include $(TOPDIR)/env/make/Makefile.rules

################################################################################
# include optional dependencies
################################################################################

-include $(DEPENDENCY_FILENAME)
