################################################################################
################################################################################
##
## Makefile -- makefile for firmware
##
## (C) Copyright 2012-2015 by Goke Microelectronics Co.,Ltd
##
## Mandatory settings:
##
## o TOPDIR      = the toplevel directory (using slashes as path separator)
## o TARGET      = the machine qualifier to generate code for
## o DIRECTORIES = the list of sub directories to build
##
################################################################################
################################################################################

  TOPDIR = ../../../..
  SUBDIR = linux/kernel/drv/firmware
  PWDDIR = $(shell pwd)

include $(TOPDIR)/env/make/Makefile.config


################################################################################
# project specific settings
################################################################################


################################################################################
# include library specific targets ( if available )
################################################################################

################################################################################
# define user targets
################################################################################

LOAD_GK710X = $(shell grep -o "\bCONFIG_ARCH_GK710X=y\b" ../../3.4.43/.config 2> /dev/null | wc -l)
LOAD_GK710XS = $(shell grep -o "\bCONFIG_ARCH_GK710XS=y\b" ../../3.4.43/.config 2> /dev/null | wc -l)

default: install

clean:

build:

headers:

install: force
	@mkdir $(ROOTFS_TOP)/lib/firmware -p
	@echo "install firmware for $(CHIP_ID) family --> $(ROOTFS_TOP)/lib/firmware"
ifeq ($(LOAD_GK710X),1)
	@echo "install firmware for GK710X"
	@cp ./gk_fw_710x.bin $(ROOTFS_TOP)/lib/firmware/gk_fw.bin
else
ifeq ($(LOAD_GK710XS),1)
	@echo "install firmware for GK710XS"
	@cp ./gk_fw_710xs.bin $(ROOTFS_TOP)/lib/firmware/gk_fw.bin
else
ifeq ($(CHIP_ID),GK710X)
	@echo "install firmware for GK710X"
	@cp ./gk_fw_710x.bin $(ROOTFS_TOP)/lib/firmware/gk_fw.bin
else
ifeq ($(CHIP_ID),GK710XS)
	@echo "install firmware for GK710XS"
	@cp ./gk_fw_710xs.bin $(ROOTFS_TOP)/lib/firmware/gk_fw.bin
endif
endif
endif
endif

depend: $(DIRECTORIES:%=subdir-depend-%)

all: clean headers build install

################################################################################
# include internal definitions and rules
################################################################################

  RELEASE_SUBDIR = $(SUBDIR)
  RELEASE_FILES += Makefile
  RELEASE_FILES += gk_fw_710x.bin
  RELEASE_FILES += gk_fw_710xs.bin

release: release-files $(DIRECTORIES:%=subdir-release-%)

doc: $(DIRECTORIES:%=subdir-doc-%)

include $(TOPDIR)/env/make/Makefile.rules
force:

################################################################################
# local directory specific rules
################################################################################



