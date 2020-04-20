.\sys\execute.exe  -verbose -flash -flashtype=32bit@32 -flashbase=0 -flashoffset=0x0 -flashinfo=0x23FFFF00 -dll=.\sys\usbdbgport.dll -port=USB0:DEBUGPORT_ONLY:SYSFREQ=324000000:STARTBAUD=38400:BAUDRATE=1382400:RAMBASE=0x02004000 -bin=.\bin\total1.bin@RAW,0x40000000,,LOAD -elf=.\sys\flasher.axf -reg=.\sys\ddr_init.rvs -wait=polling -rblmsg

pause