################################################################################
################################################################################
##
## Makefile -- Makefile for ADI library
##
## (C) Copyright 2012-2015 by Goke Microelectronics Co.,Ltd
##
## Version: $Id$
##
## Mandatory settings:
##
## o TOPDIR      = the toplevel directory (using slashes as path separator)
## o TARGET      = the machine qualifier to generate code for
##
################################################################################
################################################################################


TOPDIR = ../..
SUBDIR = rtos/stub

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# project specific settings
################################################################################

  NODEBUG = 1

  SOURCES += rtos_kernel.c
  SOURCES += stub_init.c
  
  HEADERS += rtos_kernel.h

  LIBRARY = librtosstub
  HEADER_SUBDIR = rtos

################################################################################
# define user targets
################################################################################

default: all

clean: clean-objects clean-library

build: headers build-objects build-library

headers: install-headers

install: build install-library

all: clean build install


include $(TOPDIR)/env/make/Makefile.rules

