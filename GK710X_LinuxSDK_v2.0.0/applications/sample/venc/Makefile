################################################################################
################################################################################
##
## Makefile -- makefile for sample venc
##
## (C) Copyright 2012-2014 by Goke Microelectronics Co.,Ltd
##
## Mandatory settings:
##
## o TOPDIR      = the toplevel directory (using slashes as path separator)
## o TARGET      = the machine qualifier to generate code for
##
################################################################################
################################################################################

TOPDIR = ../../..
SUBDIR = applications/sample/venc

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# source files
################################################################################
SOURCES += sample_venc.c



################################################################################
# define define user cc flags
################################################################################
CCFLAGS_USER += -O3 -DDEBUG -g
CCFLAGS_USER += -I $(TOPDIR)/adi/include
CCFLAGS_USER += -I $(TOPDIR)/image/image_lib/include



################################################################################
# define define user ld flags
################################################################################



################################################################################
# define library used
################################################################################
LIBRARIES  = adi image



################################################################################
# define target name
################################################################################
PROGRAM = vencsample



################################################################################
# define user targets
################################################################################

default: install

clean: clean-objects clean-all

build:  build-objects build-program

install: build install-program install-bin 

headers:

all: clean build install

  RELEASE_SUBDIR = $(SUBDIR)
  RELEASE_FILES += Makefile
  RELEASE_FILES += $(SOURCES)

release: release-files $(DIRECTORIES:%=subdir-release-%) info

doc: $(DIRECTORIES:%=subdir-doc-%)

info: force
	@echo $(DIRECTORIES)


include $(TOPDIR)/env/make/Makefile.rules

-include $(TOPDIR)/env/make/Makfile.dep

