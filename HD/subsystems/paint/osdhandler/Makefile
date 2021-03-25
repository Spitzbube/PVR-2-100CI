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
  SUBDIR = subsystems/paint/osdhandler

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# Use virtual layer system [ YES / NO ]
################################################################################

  OSDHANDLER_USE_VIRTUAL_LAYERS = NO

################################################################################
# project specific settings
################################################################################

  SOURCES  = src/osdhandler.c
#  SOURCES += src/osdhandler_fb.c
  HEADERS  = src/osdhandler.h
#  HEADERS += src/osdhandler_fb.h

ifeq ($(OSDHANDLER_USE_VIRTUAL_LAYERS), YES)
  SOURCES += src/osdhandler_virtual.c
  HEADERS += src/osdhandler_virtual.h
endif

  LIBRARY = libosdhandler
  HEADER_SUBDIR = osdhandler

ifeq ($(OSDHANDLER_USE_VIRTUAL_LAYERS), YES)
  CCFLAGS_USER += -DOSDHANDLER_USE_VIRTUAL_LAYERS=1
else
  CCFLAGS_USER += -DOSDHANDLER_USE_VIRTUAL_LAYERS=0
endif

################################################################################
# ARM1176 RealView settings
################################################################################

ifeq ($(TARGET),arm11-realview)
  SOURCES += src/arm1176_osd.s
endif

################################################################################
# ARM1176 GNUARM settings
################################################################################

ifeq ($(TARGET),arm11-gnuarm)
  SOURCES += src/arm1176_osd.gcc.s
endif

################################################################################
# ARM1176 Amotec settings
################################################################################

ifeq ($(TARGET),arm11-amotec)
  SOURCES += src/arm1176_osd.gcc.s
endif

################################################################################
# ARM1176 YAGARTO settings
################################################################################

ifeq ($(TARGET),arm11-yagarto)
  SOURCES += src/arm1176_osd.gcc.s
endif

################################################################################
# ARM1176 CodeSourcery settings
################################################################################

ifeq ($(TARGET),arm11-sourcery)
  SOURCES += src/arm1176_osd.gcc.s
endif

################################################################################
# define user targets
################################################################################

default: build

clean: clean-objects clean-library

build: build-objects build-library

headers: install-headers

install: install-library

all: clean headers build install

################################################################################
# include internal definitions and rules
################################################################################

  RELEASE_SUBDIR = $(SUBDIR)
  RELEASE_FILES += src/osdhandler.h
  RELEASE_FILES += src/osdhandler_priv.h
  RELEASE_FILES += src/osdhandler_fb.h
  RELEASE_FILES += src/osdhandler_asm.h
  RELEASE_FILES += src/osdhandler.c
  RELEASE_FILES += src/osdhandler_fb.c
  RELEASE_FILES += src/arm1176_osd.s
  RELEASE_FILES += src/arm1176_osd.gcc.s

ifeq ($(OSDHANDLER_USE_VIRTUAL_LAYERS), YES)
  RELEASE_FILES += src/osdhandler_virtual.h
  RELEASE_FILES += src/osdhandler_virtual.c
endif

  RELEASE_FILES += Makefile

release: doc release-files

doc:

include $(TOPDIR)/env/make/Makefile.rules

################################################################################
# include specific makefile available at FME only
################################################################################

-include ./fme/Makefile.fme

################################################################################
# include optional dependencies
################################################################################

-include $(DEPENDENCY_FILENAME)
