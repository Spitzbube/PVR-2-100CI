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

  TOPDIR = ../..
  SUBDIR = middleware/pvr

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# project specific settings
################################################################################


  SOURCES       = src/pvr.c
#  SOURCES      += src/pvr_priv.c
#  SOURCES      += src/pvr_record.c
#  SOURCES      += src/pvr_play.c
#  SOURCES      += src/pvr_play_feed.c

  HEADERS       = src/pvr.h

  LIBRARY       = libpvr
  HEADER_SUBDIR = pvr

  # NOTE: This is a workaround for MB86H60 necessary for avoiding
  #       TSD recoveries during PVR playback.
  CCFLAGS_USER += -DPVR_PLAY_PERIODIC_FEED

################################################################################
# define user targets
################################################################################

default: build

clean: clean-objects clean-library

build: build-objects build-library

headers: install-headers

install: build headers install-library

all: clean build install

doc:

################################################################################
# include internal definitions and rules
################################################################################

  RELEASE_SUBDIR = $(SUBDIR)
  RELEASE_FILES += $(HEADERS)
  RELEASE_FILES += $(wildcard src/pvr_*.h)
  RELEASE_FILES += $(SOURCES)
  RELEASE_FILES += Makefile

release: doc release-files

include $(TOPDIR)/env/make/Makefile.rules

################################################################################
# include optional dependencies
################################################################################

-include $(DEPENDENCY_FILENAME)
