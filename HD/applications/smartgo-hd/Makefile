################################################################################
################################################################################
##
## Makefile -- makefile for smartgo-hd
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

TOPDIR = ../..
SUBDIR = applications/smartgo-hd

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# source files
################################################################################

SOURCES += sys.c
SOURCES += app_ref/src/app_main.c
SOURCES += sys/src/main.c
SOURCES += sys/src/event_queue.c
SOURCES += sys/src/input.c

SOURCES += test.c

HEADERS += sys/src/event_queue.h


################################################################################
# define define user cc flags
################################################################################



################################################################################
# define define user ld flags
################################################################################



################################################################################
# define library used
################################################################################

LIBRARIES  = fapi famos

################################################################################
# define target name
################################################################################

PROGRAM = smartgo-hd

################################################################################
# define user targets
################################################################################

default: install

clean: clean-objects clean-all

build: headers build-objects build-program build-elfdump-program

install: build install-program

headers: install-headers

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

