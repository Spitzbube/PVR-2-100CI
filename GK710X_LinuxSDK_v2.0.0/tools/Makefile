################################################################################
################################################################################
##
## Makefile -- makefile for env
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

  TOPDIR = ..
  SUBDIR = tools

include $(TOPDIR)/env/make/Makefile.config


################################################################################
# define user targets
################################################################################

default:

clean:

build:

install:

headers:

all:

################################################################################
# include internal definitions and rules
################################################################################

  RELEASE_SUBDIR = $(SUBDIR)
  RELEASE_FILES += Makefile
  RELEASE_FILES += toolchain/arm-linux/goke-arm1176-linux3.4.43-gcc4.6.1-glibc.tar.bz2
  RELEASE_FILES += toolchain/arm-linux/goke-arm1176-linux3.4.43-gcc4.6.1-uClibc.tar.bz2 

release: release-files $(DIRECTORIES:%=subdir-release-%)


include $(TOPDIR)/env/make/Makefile.rules

-include $(TOPDIR)/env/make/Makfile.dep

