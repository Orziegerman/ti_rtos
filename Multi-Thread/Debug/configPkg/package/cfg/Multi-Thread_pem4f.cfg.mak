# invoke SourceDir generated makefile for Multi-Thread.pem4f
Multi-Thread.pem4f: .libraries,Multi-Thread.pem4f
.libraries,Multi-Thread.pem4f: package/cfg/Multi-Thread_pem4f.xdl
	$(MAKE) -f C:\Users\ArieZaleski\projects\ti_rtos\Multi-Thread/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\ArieZaleski\projects\ti_rtos\Multi-Thread/src/makefile.libs clean

