#
# Copyright (C) 2013 Gofortune Semiconductor Corporation.
# Kewell Liu  <liujingke@gofortune-semi.com>
#
# See file CREDITS for list of people who contributed to this
# project.
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License as
# published by the Free Software Foundation; either version 2 of
# the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston,
# MA 02111-1307 USA
#

include $(TOPDIR)/config.mk

LIB	:= $(obj)libspinand.o

ifdef CONFIG_CMD_SPINAND
ifdef	CONFIG_SPL_BUILD
COBJS-y	+= spinand_spl.o
else
COBJS-y	+= spinand_uboot.o 
COBJS-y	+= spinand_base.o 
COBJS-y	+= spinand_bbt.o
COBJS-y	+= spinand_util.o
endif

COBJS-$(CONFIG_GK6202_SPINAND)	+= gk6202_spinand.o
COBJS-$(CONFIG_GK7101_SPINAND)	+= gk7101_spinand.o
endif

COBJS	:= $(COBJS-y)
SRCS	:= $(COBJS:.o=.c)
OBJS	:= $(addprefix $(obj),$(COBJS))

all:	$(LIB)

$(LIB): $(obj).depend $(OBJS)
	$(call cmd_link_o_target, $(OBJS))

#########################################################################

include $(SRCTREE)/rules.mk

sinclude $(obj).depend

#########################################################################
