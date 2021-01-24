a.out:queueimp.o queuemain.o
	gcc queueimp.o queuemain.o
queueimp.o:queueimp.c queue.mk
	gcc -c queueimp.c
queuemain.o:queuemain.c queue.mk
	gcc -c queuemain.c
