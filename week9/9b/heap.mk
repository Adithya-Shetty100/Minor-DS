a.out:heapimp.o heapmain.o
	gcc heapimp.o heapmain.o
heapimp.o:heapimp.c heap.mk
	gcc -c heapimp.c
heapmain.o:heapmain.c heap.mk
	gcc -c heapmain.c
