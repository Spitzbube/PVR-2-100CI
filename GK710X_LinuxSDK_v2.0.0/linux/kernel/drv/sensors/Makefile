################################################################################
################################################################################
##
## Makefile -- makefile for sensor drivers.
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
  SUBDIR = linux/kernel/drv/sensors

include $(TOPDIR)/env/make/Makefile.config

################################################################################
# project specific settings
################################################################################
ifeq ($(sensor), )
#    DIRECTORIES += ov2710 imx222 ov9710 ar0330 jxh42 bg0701 ar0130 ar0331 sc1035
#    DIRECTORIES += sc1045 ps1210 ar0230 tw9912 gc1024 ar0237 imx323 jxh61 mis1002
#    DIRECTORIES += sc1135 sc1145 sc2035 sc2045 sc2135
    DIRECTORIES += sensor
    DIRECTORIES += sc1135_ex
else
  ifeq ($(sensor), ov2710)
    DIRECTORIES += ov2710
  endif
  ifeq ($(sensor), imx222)
    DIRECTORIES += imx222
  endif
  ifeq ($(sensor), ov9710)
    DIRECTORIES += ov9710
  endif
  ifeq ($(sensor), ar0330)
    DIRECTORIES += ar0330
  endif
  ifeq ($(sensor), jxh42)
    DIRECTORIES += jxh42
  endif
  ifeq ($(sensor), bg0701)
    DIRECTORIES += bg0701
  endif
  ifeq ($(sensor), ar0130)
    DIRECTORIES += ar0130
  endif
  ifeq ($(sensor), ar0331)
    DIRECTORIES += ar0331
  endif
  ifeq ($(sensor), sc1035)
    DIRECTORIES += sc1035
  endif
  ifeq ($(sensor), sc1045)
    DIRECTORIES += sc1045
  endif
  ifeq ($(sensor), ps1210)
    DIRECTORIES += ps1210
  endif
  ifeq ($(sensor), ar0230)
    DIRECTORIES += ar0230
  endif
  ifeq ($(sensor), tw9912)
    DIRECTORIES += tw9912
  endif
  ifeq ($(sensor), gc1024)
    DIRECTORIES += gc1024
  endif
  ifeq ($(sensor), ar0237)
    DIRECTORIES += ar0237
  endif
  ifeq ($(sensor), imx323)
    DIRECTORIES += imx323
  endif
  ifeq ($(sensor), jxh61)
    DIRECTORIES += jxh61
  endif
  ifeq ($(sensor), mis1002)
    DIRECTORIES += mis1002
  endif
  ifeq ($(sensor), sc1135)
    DIRECTORIES += sc1135
  endif
  ifeq ($(sensor), sc1145)
    DIRECTORIES += sc1145
  endif
  ifeq ($(sensor), sc2035)
    DIRECTORIES += sc2035
  endif
  ifeq ($(sensor), sc2045)
    DIRECTORIES += sc2045
  endif
  ifeq ($(sensor), sc2135)
    DIRECTORIES += sc2135
  endif
endif

################################################################################
# include library specific targets ( if available )
################################################################################


################################################################################
# define user targets
################################################################################

default: all

clean: $(DIRECTORIES:%=subdir-clean-%)

build: $(DIRECTORIES:%=subdir-build-%)

headers: $(DIRECTORIES:%=subdir-headers-%)

install: $(DIRECTORIES:%=subdir-install-%)

depend: $(DIRECTORIES:%=subdir-depend-%)

all: build install

################################################################################
# include internal definitions and rules
################################################################################

  RELEASE_SUBDIR = $(SUBDIR)
  RELEASE_FILES += $(wildcard Makefile)

release: release-files $(DIRECTORIES:%=subdir-release-%) info

doc: $(DIRECTORIES:%=subdir-doc-%)

info: force
	@echo $(DIRECTORIES)

include $(TOPDIR)/env/make/Makefile.rules

################################################################################
# local directory specific rules
################################################################################

subdir-clean-%:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Submaking clean [$(SUBDIR)/$(@:subdir-clean-%=%)] for target [$(TARGET)]
	@$(SUBMAKE) -C $(@:subdir-clean-%=%) clean TARGET=$(TARGET)

subdir-depend-%:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Submaking depend [$(SUBDIR)/$(@:subdir-depend-%=%)] for target [$(TARGET)]
	@$(SUBMAKE) -C $(@:subdir-depend-%=%) depend TARGET=$(TARGET)

subdir-headers-%:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Submaking headers [$(SUBDIR)/$(@:subdir-headers-%=%)] for target [$(TARGET)]
	@$(SUBMAKE) -C $(@:subdir-headers-%=%) headers TARGET=$(TARGET)

subdir-build-%:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Submaking build [$(SUBDIR)/$(@:subdir-build-%=%)] for target [$(TARGET)]
	@$(SUBMAKE) -C $(@:subdir-build-%=%) build TARGET=$(TARGET)

subdir-install-%:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Submaking install [$(SUBDIR)/$(@:subdir-install-%=%)] for target [$(TARGET)]
	@$(SUBMAKE) -C $(@:subdir-install-%=%) install TARGET=$(TARGET)

subdir-release-%:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Submaking release [$(SUBDIR)/$(@:subdir-release-%=%)] for target [$(TARGET)]
	@$(SUBMAKE) -C $(@:subdir-release-%=%) release TARGET=$(TARGET)

subdir-doc-%:
	@$(NEWLINE)
	@$(ECHO) $(ECHOPREFIX) Submaking doc [$(SUBDIR)/$(@:subdir-doc-%=%)] for target [$(TARGET)]
	@$(SUBMAKE) -C $(@:subdir-doc-%=%) doc TARGET=$(TARGET)


