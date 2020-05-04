#!/bin/sh

if ! [ -e bin ];then
    mkdir bin -p
fi

gcc -o mklcd mklcd.c -I../../adi/include -I../../image/image_lib/include
./mklcd
rm mklcd
if ! [ -e ${ROOTFS_TOP}/etc/display ];then
    mkdir ${ROOTFS_TOP}/etc/display -p
fi
cp bin/*.bin ${ROOTFS_TOP}/etc/display/ -f
#rm *.bin
