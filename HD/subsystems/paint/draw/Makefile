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
  SUBDIR = subsystems/paint/draw

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# Use ASM optimized routines [ YES / NO ]
################################################################################

  DRAW_USE_ASM_ROUTINES = NO

################################################################################
# project specific settings
################################################################################


  HEADERS  = src/draw.h
  SOURCES  = src/draw.c
  SOURCES += src/draw_scale.c

  LIBRARY = libdraw
  HEADER_SUBDIR = draw

ifeq ($(DRAW_USE_ASM_ROUTINES), YES)
  CCFLAGS_USER += -DDRAW_USE_ASM_ROUTINES=1
else
  CCFLAGS_USER += -DDRAW_USE_ASM_ROUTINES=0
endif

################################################################################
# ARM1176 RealView settings
################################################################################

ifeq ($(DRAW_USE_ASM_ROUTINES), YES)
ifeq ($(TARGET),arm11-realview)
  SOURCES += src/arm1176_draw.s
endif
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
  RELEASE_FILES += $(wildcard src/*.c)
  RELEASE_FILES += $(wildcard src/*.h)
  RELEASE_FILES += src/arm1176_draw.s
  RELEASE_FILES += Makefile
  RELEASE_FILES += draw_scale_readme.txt

release: doc release-files

doc:

include $(TOPDIR)/env/make/Makefile.rules

################################################################################
# include optional dependencies
################################################################################

-include $(DEPENDENCY_FILENAME)
