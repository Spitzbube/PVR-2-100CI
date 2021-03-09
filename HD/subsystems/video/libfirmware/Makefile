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
  SUBDIR = subsystems/video/libfirmware

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# project specific settings
################################################################################

  HEADERS       = src/firmware_video.h
  SOURCES       = src/firmware_video.c
  LIBRARY       = libfirmwarevideo
  HEADER_SUBDIR = firmware
  NOMISRA       = 1

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

  FW_BINFILE_VIDEO_MPEG_JUMP = ../firmware/build/$(DECODER)/firmware/fta_mpeg0.bin
  FW_BINFILE_VIDEO_MPEG_CODE = ../firmware/build/$(DECODER)/firmware/fta_mpeg1.bin
  FW_BINFILE_VIDEO_MPEG_CTRL = ../firmware/build/$(DECODER)/firmware/fta_mpeg2.bin
  FW_BINFILE_VIDEO_H264_JUMP = ../firmware/build/$(DECODER)/firmware/dec_h2640.bin
  FW_BINFILE_VIDEO_H264_CODE = ../firmware/build/$(DECODER)/firmware/dec_h2641.bin
  FW_BINFILE_VIDEO_H264_CTRL = ../firmware/build/$(DECODER)/firmware/dec_h2642.bin

  FW_VERSION_VIDEO_MPEG_JUMP = $(RELEASE_VIDEC_MPEG_0_VERSION)
  FW_VERSION_VIDEO_MPEG_CODE = $(RELEASE_VIDEC_MPEG_1_VERSION)
  FW_VERSION_VIDEO_MPEG_CTRL = $(RELEASE_VIDEC_MPEG_2_VERSION)
  FW_VERSION_VIDEO_H264_JUMP = $(RELEASE_VIDEC_H264_0_VERSION)
  FW_VERSION_VIDEO_H264_CODE = $(RELEASE_VIDEC_H264_1_VERSION)
  FW_VERSION_VIDEO_H264_CTRL = $(RELEASE_VIDEC_H264_2_VERSION)

  FW_VARNAME_VIDEO_MPEG_JUMP = FIRMWARE_video_mpeg_jump
  FW_VARNAME_VIDEO_MPEG_CODE = FIRMWARE_video_mpeg_code
  FW_VARNAME_VIDEO_MPEG_CTRL = FIRMWARE_video_mpeg_ctrl
  FW_VARNAME_VIDEO_H264_JUMP = FIRMWARE_video_h264_jump
  FW_VARNAME_VIDEO_H264_CODE = FIRMWARE_video_h264_code
  FW_VARNAME_VIDEO_H264_CTRL = FIRMWARE_video_h264_ctrl

  FW_ADDRESS_VIDEO_MPEG_JUMP = 0x60040c80
  FW_ADDRESS_VIDEO_MPEG_CODE = 0x60080000
  FW_ADDRESS_VIDEO_MPEG_CTRL = 0x60097c00
  FW_ADDRESS_VIDEO_H264_JUMP = 0x60040000
  FW_ADDRESS_VIDEO_H264_CODE = 0x60080000
  FW_ADDRESS_VIDEO_H264_CTRL = 0x60097c00

  FW_BINSPEC_VIDEO_MPEG_JUMP = -bin=$(FW_BINFILE_VIDEO_MPEG_JUMP)@RAW,$(FW_ADDRESS_VIDEO_MPEG_JUMP),,NONE,SWAP,,$(FW_VERSION_VIDEO_MPEG_JUMP)
  FW_BINSPEC_VIDEO_MPEG_CODE = -bin=$(FW_BINFILE_VIDEO_MPEG_CODE)@RAW,$(FW_ADDRESS_VIDEO_MPEG_CODE),,NONE,SWAP,,$(FW_VERSION_VIDEO_MPEG_CODE)
  FW_BINSPEC_VIDEO_MPEG_CTRL = -bin=$(FW_BINFILE_VIDEO_MPEG_CTRL)@RAW,$(FW_ADDRESS_VIDEO_MPEG_CTRL),,NONE,SWAP,,$(FW_VERSION_VIDEO_MPEG_CTRL)
  FW_BINSPEC_VIDEO_H264_JUMP = -bin=$(FW_BINFILE_VIDEO_H264_JUMP)@RAW,$(FW_ADDRESS_VIDEO_H264_JUMP),,NONE,SWAP,,$(FW_VERSION_VIDEO_H264_JUMP)
  FW_BINSPEC_VIDEO_H264_CODE = -bin=$(FW_BINFILE_VIDEO_H264_CODE)@RAW,$(FW_ADDRESS_VIDEO_H264_CODE),,NONE,SWAP,,$(FW_VERSION_VIDEO_H264_CODE)
  FW_BINSPEC_VIDEO_H264_CTRL = -bin=$(FW_BINFILE_VIDEO_H264_CTRL)@RAW,$(FW_ADDRESS_VIDEO_H264_CTRL),,NONE,SWAP,,$(FW_VERSION_VIDEO_H264_CTRL)

  FW_CSOURCE_VIDEO_MPEG_JUMP = src/$(FW_VARNAME_VIDEO_MPEG_JUMP).c
  FW_CSOURCE_VIDEO_MPEG_CODE = src/$(FW_VARNAME_VIDEO_MPEG_CODE).c
  FW_CSOURCE_VIDEO_MPEG_CTRL = src/$(FW_VARNAME_VIDEO_MPEG_CTRL).c
  FW_CSOURCE_VIDEO_H264_JUMP = src/$(FW_VARNAME_VIDEO_H264_JUMP).c
  FW_CSOURCE_VIDEO_H264_CODE = src/$(FW_VARNAME_VIDEO_H264_CODE).c
  FW_CSOURCE_VIDEO_H264_CTRL = src/$(FW_VARNAME_VIDEO_H264_CTRL).c

  SOURCES += $(FW_CSOURCE_VIDEO_MPEG_JUMP)
  SOURCES += $(FW_CSOURCE_VIDEO_MPEG_CODE)
  SOURCES += $(FW_CSOURCE_VIDEO_MPEG_CTRL)
  SOURCES += $(FW_CSOURCE_VIDEO_H264_JUMP)
  SOURCES += $(FW_CSOURCE_VIDEO_H264_CODE)
  SOURCES += $(FW_CSOURCE_VIDEO_H264_CTRL)

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

