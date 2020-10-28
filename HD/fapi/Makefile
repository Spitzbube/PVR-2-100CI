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


TOPDIR = ..
SUBDIR = fapi

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# project specific settings
################################################################################

  NODEBUG = 1

  SOURCES += drv/gpio/drv_gpio.c
  SOURCES += drv/gpreg/drv_gpreg.c
  SOURCES += drv/intr/drv_intr.c
  SOURCES += drv/mmu/bget.c
  SOURCES += drv/mmu/drv_mmu.c
  SOURCES += drv/mmu/drv_mmu_heap.c
  SOURCES += drv/timer/drv_timer.c
  SOURCES += drv/uart/drv_uart.c

  SOURCES += reg/$(DECODER)/reg_gpio.c
  SOURCES += reg/$(DECODER)/reg_irq_ctrl.c
  SOURCES += reg/$(DECODER)/reg_uart.c
  SOURCES += reg/$(DECODER)/reg_vic.c

  SOURCES += sys/sys_services.c

  CCFLAGS_USER += -DINLINE=__inline
  
  HEADERS = $(SOURCES:%.c=%.h)
  HEADERS += sys/sys_driver.h
  HEADERS += sys/sys_error.h

  LIBRARY = libfapi
  HEADER_SUBDIR = fapi

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

