a.out:hashimp.o hashmain.o
	gcc hashimp.o hashmain.o
hashimp.o:hashimp.c hash.mk
	gcc -c hashimp.c
hashmain.o:hashmain.c hash.mk
	gcc -c hashmain.c
