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
  SUBDIR = subsystems/compression/libz

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# project specific settings
################################################################################


  SOURCES        += src/inflate.c
  SOURCES        += src/adler32.c
  SOURCES        += src/crc32.c
  SOURCES        += src/inffast.c
  SOURCES        += src/inftrees.c
  SOURCES        += src/zutil.c

# used for compression of data
  SOURCES        += src/compress.c
  SOURCES        += src/deflate.c
  SOURCES        += src/trees.c
# used for unzip functionality
  SOURCES        += src/uncompr.c

  HEADERS        += src/zconf.h
  HEADERS        += src/zlib.h
  HEADERS        += src/zutil.h

  HEADER_SUBDIR   = compression

  LIBRARY         = libz

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
  RELEASE_FILES += $(wildcard src/*)
  RELEASE_FILES += Makefile
  RELEASE_FILES += readme.txt

release: doc release-files

doc:

include $(TOPDIR)/env/make/Makefile.rules

################################################################################
# include optional dependencies
################################################################################

-include $(DEPENDENCY_FILENAME)
