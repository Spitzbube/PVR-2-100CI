################################################################################
################################################################################
##
## Makefile -- project specific makefile to build an object library
##
## (C) Copyright 2006-2010 by Fujitsu Microelectronics Europe GmbH
## (C) Copyright 2010 by Fujitsu Semiconductor Europe GmbH
##
## Mandatory settings:
##
## o TOPDIR    = the toplevel directory (using slashes as path separator)
## o TARGET    = the machine qualifier to generate code for
## o SOURCES   = the list of source files to compile
## o STARTUP   = the name of the (assembler) startup file to use
## o HEADERS   = the list of local header files to install
## o PROGRAM   = the name of the executable to generate (without extension)
## o LIBRARIES = the list of library files to be linked
##
################################################################################
################################################################################

  TOPDIR = ../../..
  SUBDIR = subsystems/paint/fontserver

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# project specific settings
################################################################################


  SOURCES  = src/fontserver.c
  HEADERS  = src/fontserver.h
  HEADERS += src/fontserver_shared.h
  HEADERS += src/fontserver_engine.h
#  HEADERS += src/fontserver_engine_ft.h

  LIBRARY = libfontserver
  HEADER_SUBDIR = fontserver

  DIRECTORIES = engines

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
  RELEASE_FILES += $(HEADERS)
  RELEASE_FILES += $(SOURCES)
  RELEASE_FILES += Makefile

release: doc release-files $(DIRECTORIES:%=subdir-release-%)

doc: $(DIRECTORIES:%=subdir-doc-%)

include $(TOPDIR)/env/make/Makefile.rules

################################################################################
# include optional dependencies
################################################################################

-include $(DEPENDENCY_FILENAME)

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
