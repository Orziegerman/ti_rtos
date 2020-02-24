# invoke SourceDir generated makefile for Swi_thread.pem4f
Swi_thread.pem4f: .libraries,Swi_thread.pem4f
.libraries,Swi_thread.pem4f: package/cfg/Swi_thread_pem4f.xdl
	$(MAKE) -f C:\Users\ArieZaleski\projects\ti_rtos\Swi_thread/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\ArieZaleski\projects\ti_rtos\Swi_thread/src/makefile.libs clean

