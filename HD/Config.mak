################################################################################
################################################################################
##
## Config.mak -- user specific development environment settings
##
##
## (C) Copyright 2012-2015  by Goke Microelectronics Co.,Ltd
##
## Copy this file intto Config.mak.<username> to protect your private settings
## from being overwritten the next time you get an update.
## The make environment will first check for file "Config.mak.<username>",
## it will use the file "Config.mak" only if the user specific configuration
## file does not exist. <username> should be the string reported by
## "echo %USERNAME%" if you are using the standard windows shell, Cygwin
## users should call "echo $USERNAME" instead.
##
################################################################################
################################################################################


################################################################################
#
# target/host/decoder/system settings
#
# mandatory setting
#
# none of these setting should be modified.
#
# Available values for DECODER:
#
# GK710X 
# GK710XS
#
################################################################################

  HOST    ?= linux

  TARGET  ?= arm11-realview

  DECODER ?= MB86H60

  SYSTEM  ?= linux

################################################################################
#
# linux specific [kernel/toolchain/clib] settings
#
# mandatory setting
#
# Available values for KERNEL_VER:
#
#  3.4.43     : 3.4.43 for EVB
#  3.4.43-f   : 3.4.43 for FPGA
#
# Available values for GCC_VER:
#
#  4.6.1
#
# Available values for C_LIBRARY:
#
#  glibc
#  uClibc
#
################################################################################

  KERNEL_VER ?= 3.4.43

  GCC_VER    ?= 4.6.1

  C_LIBRARY  ?= uClibc

################################################################################
#
# path settings
#
# mandatory setting
#
# SDK_TOP:
#  - Description: specify the absolute path directory where this file reside in.
#                 you must specify the value of this configuration before any
#                 'make' operation.
#  - Values     : MUST be current path directory.
#
# KERNEL_TOP:
#  - Description: specify the abolute path directory where kernel reside in.
#                 generally you don't need change this manually.
#  - Values     : decided by the $(KERNEL_VER). Don't change.
#
# UBOOT_TOP:
#  - Description: specify the abolute path directory where u-boot reside in.
#                 generally you don't need change this manually.
#  - Values     : decided by the $(SDK_TOP). Don't change.
#
################################################################################

  #SDK_TOP    ?= /home/gk/svn/solution/release/trunk/software 
  SDK_TOP    ?= /mnt/gm8135_share/work/GK710X_LinuxSDK_v2.0.0

  KERNEL_TOP ?= $(SDK_TOP)/linux/kernel/$(KERNEL_VER)

  UBOOT_TOP  ?= $(SDK_TOP)/boot/u-boot

################################################################################
#
# toolchain parent directroy settings (optional)
#
# This macro can be used to override the default directory where the toolchain
# reside in.
#
# By default the toolchain will be installed into /opt/goke/
# Note:
#   This config CAN NOT be assigned with $(PWD), you can use $(SDK_TOP) instead.
#
################################################################################

TOOLCHAIN_PARENT_DIRECTORY ?= /opt/goke

  SDKHOME-arm11-realview   ?= "$(ROOT)/c/PROGRA~1/ARM/RVCT/Programs/3.1/569/win_32-pentium"
  SDKHOME-arm11-rvheader   ?= "$(ROOT)/c/PROGRA~1/ARM/RVCT/Data/3.1/569/include/windows"

################################################################################
#
# rootfs parent directroy settings (optional)
#
# This macro can be used to override the default directory where the rootfs
# reside in.
#
# By default the rootfs will be installed into /opt/goke/
# Note:
#   This config CAN NOT be assigned with $(PWD), you can use $(SDK_TOP) instead.
#
################################################################################

#ROOTFS_PARENT_DIRECTORY ?= /opt/goke
ROOTFS_PARENT_DIRECTORY ?= /nfs_root/final_fs/rootfs_gk7102s


################################################################################
#
# ISP3A library settings (optional)
#
# This macro can be used to override the default ISP3A library settings
#
# Note: if you change the ISP3A_LIBRARY setting, you need cd into subsystem/isp3a
#       then execute 'make clean' & 'make' to compile and install the selected lib.
#       Also you need to rebuild the application(like ctlserver) to make it effect.
#
# Available values:
#   goke        : using goke ISP3A library for application
#
################################################################################

  ISP3A_LIBRARY ?= goke


################################################################################
#
# Target memory definitions
#
#
# Available values:
#
#       DDR_MEMORY_512M  config the system with 512M bits memory
#
#
#       DDR_MEMORY_1G   config the system with 1G bits memory
#              Note: on FPGA board, this configuration support only 720P
#
################################################################################

   #DDR_MEMORY_SIZE ?= DDR_MEMORY_1G
   DDR_MEMORY_SIZE ?= DDR_MEMORY_512M


################################################################################
#
# Install and Release Configuration (optional)
#
# Here you can specific your private installation and release directories.
# The macros $(RELEASE_MAJOR) and $(RELEASE_MINOR) can be used to create
# release specific sub directories.
#
################################################################################

  INSTALL_DIR   ?= $(TOPDIR)/install


################################################################################
#
# Global make arguments (optional)
#
# Here you can specific your private make arguments to be passed to every
# make call, such as:
#   REPORT      = 1           : to enable command line reporting
#
################################################################################

  REPORT      ?= 0


################################################################################
#
# Development Config (GOKE Internal Only)
#
################################################################################
-include $(SDK_TOP)/Config.mak.dev

