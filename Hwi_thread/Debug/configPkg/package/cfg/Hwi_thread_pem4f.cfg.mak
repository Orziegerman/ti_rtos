# invoke SourceDir generated makefile for Hwi_thread.pem4f
Hwi_thread.pem4f: .libraries,Hwi_thread.pem4f
.libraries,Hwi_thread.pem4f: package/cfg/Hwi_thread_pem4f.xdl
	$(MAKE) -f C:\Users\ArieZaleski\projects\ti_rtos\Hwi_thread/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\ArieZaleski\projects\ti_rtos\Hwi_thread/src/makefile.libs clean

