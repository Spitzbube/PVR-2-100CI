################################################################################
################################################################################
##
## fs.mak -- rootfs definitions
##
## Version: $Id$
##
## (C) Copyright 2012-2014  by Goke Microelectronics Co.,Ltd
################################################################################
################################################################################

################################################################################
#
# Prebuild tools selection for rootfs (optional)
#
# 1: support 0: unsupport
################################################################################

	############################################################################
	# --gdb
	############################################################################
	GDB_7_5_1_SUPPORT := 0
	GDB_7_5_1_DEPEND := ZLIB_1_2_7_SUPPORT NCURSES_5_9_SUPPORT

	############################################################################
	# --gdb server
	############################################################################
	GDBSERVER_7_5_1_SUPPORT := 0

	############################################################################
	# --mtd-utils
	#
	# mtd utilities
	############################################################################
	MTD_UTILS_1_5_0_SUPPORT := 0

	############################################################################
	# --wireless_tools
	#
	# A collection of tools to configure wireless lan cards.
	############################################################################
	WIRELESS_TOOLS_29_SUPPORT := 0

	############################################################################
	# --wpa_supplicant
	#
	# WPA supplicant for secure wireless networks
	############################################################################
	WPA_SUPPLICANT_2_0_SUPPORT := 0

	############################################################################
	# --alsa-utils
	#
	# This package contains the command line utilities for the ALSA
	# project.
	############################################################################
	ALSA_UTILS_1_0_26_SUPPORT := 0
	ALSA_UTILS_1_0_26_DEPEND  := ALSA_LIB_1_0_26_SUPPORT

ifeq ($(C_LIBRARY), glibc)
	############################################################################
	# --alsa-utils
	#
	# This package contains the command line utilities for the ALSA
	# project.
	############################################################################
	WIFI_TOOLS_SUPPORT := 0
endif

################################################################################
#
# Prebuild libraries selection for rootfs (optional)
#
# 1: support 0: unsupport
################################################################################

	############################################################################
	# --zlib
	#
	# Standard (de)compression library.
	############################################################################
	ZLIB_1_2_7_SUPPORT := 0

	############################################################################
	# --libffi
	#
	# Library provides a portable, high level programming interface
	# to various calling conventions.
	############################################################################
	LIBFFI_3_0_13_SUPPORT := 0

	############################################################################
	# --expat
	#
	# The Expat XML Parser.
	############################################################################
	EXPAT_2_1_0_SUPPORT := 0

	############################################################################
	# --freetype
	#
	# A free, high-quality and portable font engine.
	############################################################################
	FREETYPE_2_4_11_SUPPORT := 0
	FREETYPE_2_4_11_DEPEND  := ZLIB_1_2_7_SUPPORT

	############################################################################
	# --openssl
	#
	# A collaborative effort to develop a robust, commercial-grade, fully
 	# featured, and Open Source toolkit implementing the Secure Sockets
 	# Layer (SSL v2/v3) and Transport Security (TLS v1) as well as a
 	# full-strength general-purpose cryptography library.
	############################################################################
	OPENSSL_1_0_1E_SUPPORT := 0
	OPENSSL_1_0_1E_DEPEND  := ZLIB_1_2_7_SUPPORT

	############################################################################
	# --libtool
	#
	# Library that hides the complexity of using shared/static libraries
	# on different platforms behind a consistent, portable interface.
	############################################################################
	LIBTOOL_2_2_10_SUPPORT := 0

	############################################################################
	# --glib
	#
	# Low-level core library that forms the basis of GTK+ and GNOME.
	############################################################################
	GLIB_2_30_3_SUPPORT := 0
	GLIB_2_30_3_DEPEND  := ZLIB_1_2_7_SUPPORT LIBFFI_3_0_13_SUPPORT

	############################################################################
	# --ncurses
	#
	# The Ncurses (new curses) library is a free software emulation of
	# curses in System V Release 4.0, and more.
	############################################################################
	NCURSES_5_9_SUPPORT := 0

	############################################################################
	# --alsa-lib
	#
	# The Advanced Linux Sound Architecture (ALSA) provides audio functionality
   	# to the Linux operating system.
	############################################################################
	ALSA_LIB_1_0_26_SUPPORT := 0

	############################################################################
	# --mxml
	#
	# Lightweight XML Library
	############################################################################
	MXML_2_7_SUPPORT := 0

	############################################################################
	# --libstdc++
	#
	# C++ standard library
	############################################################################
	LIBSTDC++_SUPPORT := 0


################################################################################
#
# RESOURCE SELECT
#
################################################################################

	################################################################################
	#
	# Fonts Library
	#
	# Options: 1,Vera.ttf 2,UnPen.ttf 3,Lucida.ttf 4,gbsn00lp.ttf 5,(not set)
	#
	################################################################################
	FONTS_LIBRARY := Vera.ttf

################################################################################
#
# Network Configuration
#
################################################################################

	############################################################################
	# Configuration for eth0
	#
	# Options: 1, static (IP) 2, dynamic (IP) 3,(not set)
	############################################################################
	ETH0_CONFIG :=

		########################################################################
		# Effective when static (IP)
		########################################################################
		ETH0_ADDRESS := 192.168.0.200
		ETH0_IP_MASK := 255.255.255.0
		ETH0_GW_ADDRESS := 192.168.0.1

################################################################################
#
# Filesystem Image Configuration
#
################################################################################

    ############################################################################
    # File System
    #
    # Options: 1, ubifs 2,jffs2 3,squashfs 4,yaffs2
    #
    #
    # NOTE:
    # Run On Nandflash: ubifs yaffs2 squashfs
    # Run On Norflash: ubifs jffs2 squashfs
    #
    ############################################################################
        FILE_SYSTEM := ubifs

	############################################################################
	#
	# Flash Type
	#
	# Options: 1, NAND 2,NOR
	#
	# Flash Name
	#
	# Nandflash Options: 1, W25N01GV
	#
	# Sflash Options: 1, MX25L12845
	#
	#
	############################################################################
	FLASH_TYPE := NOR
	FLASH_NAME := MX25L12845

ifeq ($(FLASH_NAME), W25N01GV)
	###UBIFS###
	UBI_MIN_IO_SIZE			 = -m 0x00800
	UBI_PEB_SIZE                     = -p 0x20000
	UBI_LEB_SIZE                     = -e 0x1F000
	UBI_SUB_PAGE_SIZE	         = -s 0x00800
	UBI_MAX_LEB_CNT                  = -c 2048
	###SQUASHFS###
	SQUASHFS_BLOCK_SIZE              = -b 128K
	###JFFS2###
	JFFS2_ERASE_BLOCK_SIZE           = -e 0x20000
	JFFS2_OPTIONS        		 = -p -l -n
	###YAFFS2###
	ECC_TYPE                         =  "wb"
endif

ifeq ($(FLASH_NAME), MX25L12845)
	###UBIFS###
	UBI_MIN_IO_SIZE                  = -m 0x1
	UBI_PEB_SIZE                     = -p 0x10000
	UBI_LEB_SIZE                     = -e 0xFF80
	UBI_SUB_PAGE_SIZE                = -s 0x1
	UBI_MAX_LEB_CNT                  = -c 2048
	###SQUASHFS###
	SQUASHFS_BLOCK_SIZE              = -b 64K
	###JFFS2###
	JFFS2_ERASE_BLOCK_SIZE           = -e 0x10000
	JFFS2_OPTIONS                    = -p -l
endif


