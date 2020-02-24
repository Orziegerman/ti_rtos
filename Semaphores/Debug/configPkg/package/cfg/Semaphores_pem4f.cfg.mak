# invoke SourceDir generated makefile for Semaphores.pem4f
Semaphores.pem4f: .libraries,Semaphores.pem4f
.libraries,Semaphores.pem4f: package/cfg/Semaphores_pem4f.xdl
	$(MAKE) -f C:\Users\ArieZaleski\projects\ti_rtos\Semaphores/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\ArieZaleski\projects\ti_rtos\Semaphores/src/makefile.libs clean

