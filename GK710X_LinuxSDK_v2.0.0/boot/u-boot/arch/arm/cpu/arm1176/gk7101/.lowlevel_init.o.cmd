cmd_arch/arm/cpu/arm1176/gk7101/lowlevel_init.o := /opt/crosstool_4.7.2/usr/bin/arm-goke-linux-gnueabi-gcc -Wp,-MD,arch/arm/cpu/arm1176/gk7101/.lowlevel_init.o.d  -nostdinc -isystem /opt/crosstool_4.7.2/usr/lib/gcc/arm-goke-linux-gnueabi/4.7.2/include -Iinclude  -I/home/user/ipc/u-boot-2014.07/arch/arm/include -D__KERNEL__ -DCONFIG_SYS_TEXT_BASE=0xC4000000  -D__ASSEMBLY__ -g      -DCONFIG_ARM -D__ARM__ -marm -mno-thumb-interwork  -mabi=aapcs-linux  -mword-relocations -march=armv5t  -ffunction-sections -fdata-sections -fno-common -ffixed-r9  -msoft-float  -pipe     -c -o arch/arm/cpu/arm1176/gk7101/lowlevel_init.o arch/arm/cpu/arm1176/gk7101/lowlevel_init.S

source_arch/arm/cpu/arm1176/gk7101/lowlevel_init.o := arch/arm/cpu/arm1176/gk7101/lowlevel_init.S

deps_arch/arm/cpu/arm1176/gk7101/lowlevel_init.o := \

arch/arm/cpu/arm1176/gk7101/lowlevel_init.o: $(deps_arch/arm/cpu/arm1176/gk7101/lowlevel_init.o)

$(deps_arch/arm/cpu/arm1176/gk7101/lowlevel_init.o):
