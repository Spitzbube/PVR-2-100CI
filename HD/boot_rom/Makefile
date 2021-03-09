################################################################################
################################################################################
##
## Makefile -- project specific makefile to build an executable program
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

  TOPDIR = ..
  SUBDIR = boot_rom
  
  include $(TOPDIR)/env/make/Makefile.config
  
#  TARGET := arm11-realview
  SOURCES =
  HEADERS += src/flash_header.h
  HEADERS += src/rom_symbols.h
#  HEADERS += src/cpu_control.h
  HEADERS += src/21cb40c8.h
  PROGRAM =
  HEADER_SUBDIR = boot

################################################################################
# define user targets
################################################################################

default:

clean:

build:

headers: install-headers

install: headers

all: headers

################################################################################
# include internal definitions and rules
################################################################################

  RELEASE_SUBDIR = $(SUBDIR)
  RELEASE_FILES += $(HEADERS)
  RELEASE_FILES += Makefile

doc:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Copying boot rom documentation [$(TOPDIR)/docs/online/$(DECODER)/doxygen/html/]
	$(ATSIGN)$(COPY) $(COPYFLAGS) $(wildcard docs/*.png) $(TOPDIR)/docs/online/$(DECODER)/doxygen/html/

release: doc release-files

################################################################################
# include internal definitions and rules
################################################################################

include $(TOPDIR)/env/make/Makefile.rules
