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

  TOPDIR = ../../../../..
  SUBDIR = subsystems/paint/fontserver/engines/fbf

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# project specific settings
################################################################################

  SOURCES  = src/fontserver_engine_fbf.c
  HEADERS  = src/fontserver_engine_fbf.h

  LIBRARY = libfontserver_engine_fbf
  HEADER_SUBDIR = fontserver

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
  RELEASE_FILES += $(HEADERS)
  RELEASE_FILES += $(SOURCES)
  RELEASE_FILES += Makefile

release: doc release-files

doc:

include $(TOPDIR)/env/make/Makefile.rules

################################################################################
# include optional dependencies
################################################################################

-include $(DEPENDENCY_FILENAME)
