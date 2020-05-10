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

ifeq ($(TARGET),arm11-realview)
  SOURCES += src/arm1176_start.s
  SOURCES += src/arm1176_tcm.s
  SOURCES += src/arm1176_vfp_fast.s
  SOURCES += src/arm1176_mmu.s
  SOURCES += src/arm1176_retarget.c
  SOURCES += src/arm1176_stack_heap.c
endif

ifeq ($(TARGET),arm11-gnuarm)
  SOURCES += src/arm1176_start_gcc.s
  SOURCES += src/arm1176_tcm_gcc.s
  SOURCES += src/arm1176_mmu_gcc.s
  SOURCES += src/arm1176_retarget_gcc.c
endif

  SOURCES += src/cpu_polling.c
  
  CCFLAGS_USER += -DPROGRAM_HEAP_BYTES=0x00200000 
  CCFLAGS_USER += -DPROGRAM_STACK_BYTES=0x00010000

  HEADERS += src/cpu_polling.h
  HEADER_SUBDIR = boot
  
  LIBRARY = libstartup

################################################################################
# define user targets
################################################################################

default: install

clean: clean-objects clean-library

build: headers build-objects build-library

headers: install-headers

install: build install-library install-gnu-startup

all: clean build install

################################################################################
# include internal definitions and rules
################################################################################

include $(TOPDIR)/env/make/Makefile.rules

install-gnu-startup:

ifeq ($(TARGET),arm11-gnuarm)
install-gnu-startup:
	$(ATSIGN)$(COPY) $(COPYFLAGS) $(BUILD_OBJECT_SUBDIR)/src/arm1176_start_gcc$(OBJECT_EXT) $(INSTALL_LIBRARY_DIR)
	$(ATSIGN)$(COPY) $(COPYFLAGS) $(BUILD_OBJECT_SUBDIR)/src/arm1176_start_gcc$(OBJECT_DEBUG_EXT) $(INSTALL_LIBRARY_DIR)
endif

