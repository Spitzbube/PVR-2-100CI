################################################################################
################################################################################
##
## Makefile -- makefile for operation system
##
## (C) Copyright 2012-2015 by Goke Microelectronics Co.,Ltd
##
## Version: $Id$
##
## Mandatory settings:
##
## o TOPDIR      = the toplevel directory (using slashes as path separator)
## o TARGET      = the machine qualifier to generate code for
## o DIRECTORIES = the list of sub directories to build
##
################################################################################
################################################################################

  TOPDIR = ../..
  SUBDIR = linux/kernel

include $(TOPDIR)/env/make/Makefile.config

DEVMODE = $(shell [ -f Makefile.dev ] && echo y)

ifeq ($(DEVMODE), y)
  include Makefile.dev
else
  include Makefile.rel
endif


################################################################################
# local directory specific rules
################################################################################


