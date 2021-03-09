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
  SUBDIR = subsystems/audio/libfirmware

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# project specific settings
################################################################################

  HEADERS       = src/firmware_audio.h
  SOURCES       = src/firmware_audio.c
  LIBRARY       = libfirmwareaudio
  HEADER_SUBDIR = firmware
  NOMISRA       = 1

ifeq ($(AAC),1)
  AAC_EXT += _aac
endif

ifeq ($(AC3),1)
  AC3_EXT += _ac3
endif

ifeq ($(DDP71),1)
  DDP71_EXT += _ddp71
endif

ifeq ($(DDPDCV),1)
  DDPDCV_EXT += _ddpdcv
endif

ifeq ($(HEAAC),1)
  HEAAC_EXT += _heaac
endif

ifeq ($(WMA),1)
  WMA_EXT += _wma
endif

AUDIO_EXTENSIONS = $(AAC_EXT)$(AC3_EXT)$(DDP71_EXT)$(DDPDCV_EXT)$(HEAAC_EXT)$(WMA_EXT)

################################################################################
# define user targets
################################################################################

default: build

clean: clean-objects clean-library

build: build-objects build-library

headers: install-headers

install: headers install-library

all: clean build install

################################################################################
# include specific makefile available at FME only
################################################################################

  FW_BINFILE_AUDIO_DECODER_CODE = ../firmware/build/$(DECODER)/firmware/audio_decoder$(AUDIO_EXTENSIONS).s3hex
  FW_VERSION_AUDIO_DECODER_CODE = $(RELEASE_AUDIO_DECODER_VERSION)
  FW_VARNAME_AUDIO_DECODER_CODE = FIRMWARE_audio_decoder_code
  FW_BINSPEC_AUDIO_DECODER_CODE = -s3hex=$(FW_BINFILE_AUDIO_DECODER_CODE)@ARC,,,EXEC,,,$(FW_VERSION_AUDIO_DECODER_CODE)
  FW_CSOURCE_AUDIO_DECODER_CODE = src/$(FW_VARNAME_AUDIO_DECODER_CODE).c

  SOURCES += $(FW_CSOURCE_AUDIO_DECODER_CODE)

################################################################################
# include internal definitions and rules
################################################################################

  RELEASE_SUBDIR = $(SUBDIR)
  RELEASE_FILES += $(SOURCES)
  RELEASE_FILES += $(HEADERS)
  RELEASE_FILES += Makefile

release: release-files

doc:

include $(TOPDIR)/env/make/Makefile.rules

