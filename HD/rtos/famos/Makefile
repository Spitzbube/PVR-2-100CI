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
SUBDIR = rtos/famos

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# project specific settings
################################################################################

  NODEBUG = 1

  SOURCES += rtos.c
  SOURCES += famos.c
  SOURCES += famos_thread.c
  SOURCES += famos_semaphore.c
  SOURCES += famos_timer.c
  SOURCES += famos_mailbox.c
  SOURCES += famos_mailqueue.c
  SOURCES += famos_interrupt.c
  
ifeq ($(TARGET),arm11-gcc)
  SOURCES += famos_isr_arm1176.gcc.s
endif
  
  HEADERS += famos.h
  HEADERS += rtos.h
  
  LIBRARY = libfamos
  
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

