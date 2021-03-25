################################################################################
################################################################################
##
## Makefile -- project specific makefile to build the Freetype2 library
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
  SUBDIR = subsystems/paint/freetype2

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# project specific settings
################################################################################

  SOURCES      += src/autofit.c
  SOURCES      += src/ftapi.c
  SOURCES      += src/ftbase.c
  SOURCES      += src/ftbbox.c
  SOURCES      += src/ftbdf.c
  SOURCES      += src/ftbitmap.c
  SOURCES      += src/ftdebug.c
  SOURCES      += src/ftgasp.c
  SOURCES      += src/ftglyph.c
  SOURCES      += src/ftgxval.c
  SOURCES      += src/ftinit.c
  SOURCES      += src/ftlcdfil.c
  SOURCES      += src/ftmm.c
  SOURCES      += src/ftotval.c
  SOURCES      += src/ftpatent.c
  SOURCES      += src/ftpfr.c
  SOURCES      += src/ftstroke.c
  SOURCES      += src/ftsynth.c
  SOURCES      += src/ftsystem.c
  SOURCES      += src/fttype1.c
  SOURCES      += src/ftwinfnt.c
  SOURCES      += src/ftxf86.c
  SOURCES      += src/ftcache.c
  SOURCES      += src/psaux.c
  SOURCES      += src/pshinter.c
  SOURCES      += src/psnames.c
  SOURCES      += src/raster.c
  SOURCES      += src/sfnt.c
  SOURCES      += src/smooth.c
  SOURCES      += src/truetype.c
  
  LIBRARY       = libfreetype2
  
#  HEADERS      += src/ftraster.h
#  HEADERS       = $(wildcard *.h)
  HEADERS       = $(wildcard include/*.h)
  HEADERS      += $(wildcard include/config)
  HEADERS      += $(wildcard include/internal)
  HEADER_SUBDIR = freetype

################################################################################
# Special compilation settings
################################################################################

  NOMISRA          = 1
  LINTFLAGS_USER  += -e923
  CCFLAGS_USER    += -W
  CCFLAGS_USER    += -DFT2_BUILD_LIBRARY
  CCFLAGS_USER    += -DFT_OPTION_AUTOFIT2

  CCFLAGS_USER    += -Iinclude

################################################################################
# define user targets
################################################################################

default: all

clean: clean-objects clean-library

build: build-objects build-library

headers: install-headers

install: install-library

all: clean headers build install

################################################################################
# include internal definitions and rules
################################################################################

  RELEASE_SUBDIR = $(SUBDIR)
  RELEASE_FILES += $(wildcard src/autofit/*.c)
  RELEASE_FILES += $(wildcard src/autofit/*.h)
  RELEASE_FILES += $(wildcard src/base/*.c)
  RELEASE_FILES += $(wildcard src/base/*.h)
  RELEASE_FILES += $(wildcard src/cache/*.c)
  RELEASE_FILES += $(wildcard src/cache/*.h)
  RELEASE_FILES += $(wildcard src/psaux/*.c)
  RELEASE_FILES += $(wildcard src/psaux/*.h)
  RELEASE_FILES += $(wildcard src/pshinter/*.c)
  RELEASE_FILES += $(wildcard src/pshinter/*.h)
  RELEASE_FILES += $(wildcard src/psnames/*.c)
  RELEASE_FILES += $(wildcard src/psnames/*.h)
  RELEASE_FILES += $(wildcard src/raster/*.c)
  RELEASE_FILES += $(wildcard src/raster/*.h)
  RELEASE_FILES += $(wildcard src/sfnt/*.c)
  RELEASE_FILES += $(wildcard src/sfnt/*.h)
  RELEASE_FILES += $(wildcard src/smooth/*.c)
  RELEASE_FILES += $(wildcard src/smooth/*.h)
  RELEASE_FILES += $(wildcard src/truetype/*.c)
  RELEASE_FILES += $(wildcard src/truetype/*.h)
  RELEASE_FILES += $(wildcard include/*.h)
  RELEASE_FILES += $(wildcard include/freetype/*.h)
  RELEASE_FILES += $(wildcard include/freetype/config/*.h)
  RELEASE_FILES += $(wildcard include/freetype/internal/*.h)
  RELEASE_FILES += $(wildcard include/freetype/internal/services/*.h)
  RELEASE_FILES += $(wildcard docs/reference/*)
  RELEASE_FILES += $(wildcard docs/*.dox)
  RELEASE_FILES += Makefile
  RELEASE_FILES += readme.txt

doc: force
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Copy documentation [$(TOPDIR)/docs/online/$(DECODER)/general/freetype/]
	$(ATSIGN)$(MKDIR) $(MKDIRFLAGS) $(TOPDIR)/docs/online/$(DECODER)/general/freetype/
	$(ATSIGN)$(COPY) -r $(COPYFLAGS) docs/reference/* $(TOPDIR)/docs/online/$(DECODER)/general/freetype/

release: doc release-files

include $(TOPDIR)/env/make/Makefile.rules

################################################################################
# include optional dependencies
################################################################################

-include $(DEPENDENCY_FILENAME)


