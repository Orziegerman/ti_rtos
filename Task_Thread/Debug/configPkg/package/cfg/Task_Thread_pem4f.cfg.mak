# invoke SourceDir generated makefile for Task_Thread.pem4f
Task_Thread.pem4f: .libraries,Task_Thread.pem4f
.libraries,Task_Thread.pem4f: package/cfg/Task_Thread_pem4f.xdl
	$(MAKE) -f C:\Users\ArieZaleski\projects\ti_rtos\Task_Thread/src/makefile.libs

clean::
	$(MAKE) -f C:\Users\ArieZaleski\projects\ti_rtos\Task_Thread/src/makefile.libs clean

