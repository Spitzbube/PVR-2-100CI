execute.exe -smartmpeg-e -nosplash -OK -DLL=smartmpeg.dll -port=USB1:3000000:SYSFREQ=130500000 -sdram=2x256MBit@32,2048 -initsdram -wait=halt eraser.out

execute.exe -smartmpeg-e -nosplash -OK -DLL=smartmpeg.dll -port=USB1:3000000:SYSFREQ=130500000 -verbose -sdram=2x256MBit@32,2048 -initsdram -flash=application -flasher=flasher_E@0x00008000.out -flashbase=0x0E000000 -flashtype=16bit@32 -wait=halt -flasher=flasher_E@0x003C0000.out booter.out

execute.exe -smartmpeg-e -nosplash -OK -DLL=smartmpeg.dll -port=USB1:3000000:SYSFREQ=130500000 -verbose -sdram=2x256MBit@32,2048 -initsdram -flash=application -flasher=flasher_E@0x00008000.out -flashbase=0x0E000000 -flashtype=16bit@32 -wait=halt -flash=image -flashoffset=0x00030000 smartgo.img

pause