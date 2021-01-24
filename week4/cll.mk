a.out:cllmain.o cllimp.o
	gcc cllmain.o cllimp.o
cllmain.o:cllmain.c cll.mk
	gcc -c cllmain.c
cllimp.o:cllimp.c cll.mk
	gcc -c cllimp.c
	

