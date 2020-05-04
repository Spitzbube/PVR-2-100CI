#!/bin/sh

if ! [ -e bin ];then
    mkdir bin -p
fi

gcc -o mksensor mksensor.c -I../../adi/include -I../../image/image_lib/include
./mksensor
rm mksensor
if ! [ -e ${ROOTFS_TOP}/etc/sensors ];then
    mkdir ${ROOTFS_TOP}/etc/sensors -p
fi
cp bin/*.bin ${ROOTFS_TOP}/etc/sensors/ -f
#rm *.bin
