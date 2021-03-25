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
  SUBDIR = subsystems/paint/PNG

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# project specific settings
################################################################################


  SOURCES        += src/png.c
  SOURCES        += src/pngerror.c
#  SOURCES        += src/pnggccrd.c
  SOURCES        += src/pngget.c
  SOURCES        += src/pngmem.c
#  SOURCES        += src/pngpread.c
  SOURCES        += src/pngread.c
  SOURCES        += src/pngrio.c
  SOURCES        += src/pngrtran.c
  SOURCES        += src/pngrutil.c
  SOURCES        += src/pngset.c
  SOURCES        += src/pngtrans.c
#  SOURCES        += src/pngvcrd.c
  SOURCES        += src/pngwio.c
  SOURCES        += src/pngwrite.c
  SOURCES        += src/pngwtran.c
  SOURCES        += src/pngwutil.c

  HEADERS        += src/png.h
  HEADERS        += src/pngconf.h

  HEADER_SUBDIR   = png
  LIBRARY         = libpng
  LINTFLAGS_USER += -e923

  CCFLAGS_USER   += -DPNG_NO_STDIO
  CCFLAGS_USER   += -DPNG_NO_CONSOLE_IO
  CCFLAGS_USER   += -DPNG_NO_MNG_FEATURES
  CCFLAGS_USER   += -DPNG_USER_MEM_SUPPORTED
  CCFLAGS_USER   += -DPNG_NO_WRITE_SUPPORTED
  CCFLAGS_USER   += -DPNG_NO_FLOATING_POINT_SUPPORTED


################################################################################
# define user targets
################################################################################

default: all

clean: clean-objects clean-library

build: build-objects build-library

headers: install-headers

install: install-library

all: clean headers build install

################################################################################
# include internal definitions and rules
################################################################################

  RELEASE_SUBDIR = $(SUBDIR)
  RELEASE_FILES += $(wildcard src/*)
  RELEASE_FILES += Makefile

release: doc release-files

doc:

include $(TOPDIR)/env/make/Makefile.rules

################################################################################
# include optional dependencies
################################################################################

-include $(DEPENDENCY_FILENAME)
