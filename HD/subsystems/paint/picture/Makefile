################################################################################
################################################################################
##
## Makefile -- project specific makefile to run build on sub directories
##
## (C) Copyright 2006-2010 by Fujitsu Microelectronics Europe GmbH
## (C) Copyright 2010 by Fujitsu Semiconductor Europe GmbH
##
## Mandatory settings:
##
## o TOPDIR      = the toplevel directory (using slashes as path separator)
## o TARGET      = the machine qualifier to generate code for
## o DIRECTORIES = the list of sub directories to build
##
## The TARGET qualifier decides for which target platform code will be
## generated for. Available values are:
##
## o win32-mingw    = 80x86 based Win32 environment using MinGW GCC
## o cygwin32-gcc   = 80x86 based Cygwin environment using GNU GCC
## o arm11-winarm   = ARM11 based environment using WinARM SDK
## o arm11-amotec   = ARM11 based environment using Amotec ARM SDK
## o arm11-gnuarm   = ARM11 based environment using GNUARM GCC
## o arm11-realview = ARM11 based environment using ARM RealView
##
################################################################################
################################################################################

  TOPDIR = ../../..
  SUBDIR = subsystems/paint/picture

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# project specific settings
################################################################################

#  HEADERS  = src/picture.h
#  HEADERS += src/scaler.h
#  HEADERS += src/decoder.h

#  SOURCES  = src/picture.c
#  SOURCES += src/scaler.c

  LIBRARY = libpicture
  HEADER_SUBDIR = picture

#  DIRECTORIES  = decoders

################################################################################
# define user targets
################################################################################

default: all

clean: clean-objects clean-library $(DIRECTORIES:%=subdir-clean-%)

build: build-objects build-library $(DIRECTORIES:%=subdir-build-%)

headers: install-headers $(DIRECTORIES:%=subdir-headers-%)

install: install-library $(DIRECTORIES:%=subdir-install-%)

all: clean headers build install

################################################################################
# include internal definitions and rules
################################################################################

  RELEASE_SUBDIR = $(SUBDIR)
  RELEASE_FILES += $(wildcard src/*.c)
  RELEASE_FILES += $(wildcard src/*.h)
  RELEASE_FILES += Makefile

release: doc release-files $(DIRECTORIES:%=subdir-release-%)

doc: $(DIRECTORIES:%=subdir-doc-%)

include $(TOPDIR)/env/make/Makefile.rules

################################################################################
# local directory specific rules
################################################################################

subdir-clean-%:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Making [$(SUBDIR)/$(@:subdir-clean-%=%)] for target [$(TARGET)]
	@$(SUBMAKE) -C $(@:subdir-clean-%=%) clean TARGET=$(TARGET)

subdir-depend-%:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Making [$(SUBDIR)/$(@:subdir-depend-%=%)] for target [$(TARGET)]
	@$(SUBMAKE) -C $(@:subdir-depend-%=%) depend TARGET=$(TARGET)

subdir-headers-%:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Making [$(SUBDIR)/$(@:subdir-headers-%=%)] for target [$(TARGET)]
	@$(SUBMAKE) -C $(@:subdir-headers-%=%) headers TARGET=$(TARGET)

subdir-build-%:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Making [$(SUBDIR)/$(@:subdir-build-%=%)] for target [$(TARGET)]
	@$(SUBMAKE) -C $(@:subdir-build-%=%) build TARGET=$(TARGET)

subdir-install-%:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Making [$(SUBDIR)/$(@:subdir-install-%=%)] for target [$(TARGET)]
	@$(SUBMAKE) -C $(@:subdir-install-%=%) install TARGET=$(TARGET)

subdir-release-%:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Making [$(SUBDIR)/$(@:subdir-release-%=%)] for target [$(TARGET)]
	@$(SUBMAKE) -C $(@:subdir-release-%=%) release TARGET=$(TARGET)

subdir-doc-%:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Making [$(SUBDIR)/$(@:subdir-doc-%=%)] for target [$(TARGET)]
	@$(SUBMAKE) -C $(@:subdir-doc-%=%) doc TARGET=$(TARGET)
