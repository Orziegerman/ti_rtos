# invoke SourceDir generated makefile for Clock.pem4f
Clock.pem4f: .libraries,Clock.pem4f
.libraries,Clock.pem4f: package/cfg/Clock_pem4f.xdl
	$(MAKE) -f C:\Users\ArieZaleski\projects\ti_rtos\Clock/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\ArieZaleski\projects\ti_rtos\Clock/src/makefile.libs clean

