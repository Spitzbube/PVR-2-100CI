################################################################################
################################################################################
##
## Makefile -- makefile for modules.
##
## (C) Copyright 2012-2015 by Goke Microelectronics Co.,Ltd
##
## Mandatory settings:
##
## o TOPDIR      = the toplevel directory (using slashes as path separator)
## o TARGET      = the machine qualifier to generate code for
##
################################################################################
################################################################################

  TOPDIR = ../..
  SUBDIR = boot/startup

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# source files
################################################################################

  SOURCES += src/arm1176_start.s
  SOURCES += src/arm1176_tcm.s
  SOURCES += src/arm1176_vfp_fast.s
  SOURCES += src/arm1176_mmu.s
  
  LIBRARY = libstartup

################################################################################
# define user targets
################################################################################

default: install

clean: clean-objects clean-library

build: headers build-objects build-library

headers: 

install: build install-library

all: clean build install

################################################################################
# include internal definitions and rules
################################################################################

include $(TOPDIR)/env/make/Makefile.rules
