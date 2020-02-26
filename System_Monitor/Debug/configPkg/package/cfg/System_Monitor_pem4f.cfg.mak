# invoke SourceDir generated makefile for System_Monitor.pem4f
System_Monitor.pem4f: .libraries,System_Monitor.pem4f
.libraries,System_Monitor.pem4f: package/cfg/System_Monitor_pem4f.xdl
	$(MAKE) -f C:\Users\ArieZaleski\projects\ti_rtos\System_Monitor/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\ArieZaleski\projects\ti_rtos\System_Monitor/src/makefile.libs clean

