#
# (C) Copyright 2013 
# Kewell Liu, Gofortune Software Engineering, liujingke@gofortune-semi.com
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
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston,
# MA 02111-1307 USA
#

CONFIG_NAND_SPL	= y

include $(TOPDIR)/config.mk
include $(TOPDIR)/nand_spl/board/$(BOARDDIR)/config.mk

nandobj	:= $(OBJTREE)/nand_spl/

LDSCRIPT= $(TOPDIR)/nand_spl/board/$(BOARDDIR)/u-boot.lds
LDFLAGS := -T $(nandobj)u-boot.lds -Ttext $(CONFIG_SYS_TEXT_BASE) $(LDFLAGS) \
		$(LDFLAGS_FINAL) -gc-sections -L/opt/crosstool_4.7.2/usr/lib/gcc/arm-goke-linux-gnueabi/4.7.2 -lgcc 
AFLAGS	+= -DCONFIG_NAND_SPL
CFLAGS	+= -DCONFIG_NAND_SPL -ffunction-sections

SOBJS	= start.o lowlevel_init.o
COBJS	= gk6202_spinand.o spinand_spl.o gk6202_spinand_spl.o 

SRCS	:= $(addprefix $(obj),$(SOBJS:.o=.S) $(COBJS:.o=.c))
OBJS	:= $(addprefix $(obj),$(SOBJS) $(COBJS))
__OBJS	:= $(SOBJS) $(COBJS)
LNDIR	:= $(nandobj)board/$(BOARDDIR)

ALL	= $(nandobj)u-boot-spl $(nandobj)u-boot-spl.bin $(nandobj)u-boot-spl-16k.bin

all:	$(obj).depend $(ALL)

$(nandobj)u-boot-spl-16k.bin: $(nandobj)u-boot-spl
	$(OBJCOPY) ${OBJCFLAGS} --pad-to=$(PAD_TO) -O binary $< $@

$(nandobj)u-boot-spl.bin:	$(nandobj)u-boot-spl
	$(OBJCOPY) ${OBJCFLAGS} -O binary $< $@

$(nandobj)u-boot-spl:	$(OBJS) $(nandobj)u-boot.lds
	cd $(LNDIR) && $(LD) $(LDFLAGS) $(__OBJS) \
		-Map $(nandobj)u-boot-spl.map \
		-o $(nandobj)u-boot-spl

$(nandobj)u-boot.lds: $(LDSCRIPT)
	$(CPP) $(CPPFLAGS) $(LDPPFLAGS) -ansi -D__ASSEMBLY__ -P - <$^ >$@

# create symbolic links for common files

# from cpu directory
$(obj)start.S:
	@rm -f $@
	@ln -s $(TOPDIR)/arch/arm/cpu/arm1176/start.S $@

# from board directory
$(obj)lowlevel_init.S:
	@rm -f $@
	@ln -s $(TOPDIR)/board/$(BOARDDIR)/lowlevel_init.S $@

# from drivers/mtd/spinand directory
$(obj)gk6202_spinand.c:
	@rm -f $@
	@ln -s $(TOPDIR)/drivers/mtd/spinand/gk6202_spinand.c $@
	
$(obj)spinand_spl.c:
	@rm -f $@
	@ln -s $(TOPDIR)/drivers/mtd/spinand/spinand_spl.c $@

# from nand_spl directory
$(obj)gk6202_spinand_spl.c:
	@rm -f $@
	@ln -s $(TOPDIR)/nand_spl/board/$(BOARDDIR)/gk6202_spinand_spl.c $@

#########################################################################

$(obj)%.o:	$(obj)%.S
	$(CC) $(AFLAGS) -c -o $@ $<

$(obj)%.o:	$(obj)%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# defines $(obj).depend target
include $(SRCTREE)/rules.mk

sinclude $(obj).depend

#########################################################################
