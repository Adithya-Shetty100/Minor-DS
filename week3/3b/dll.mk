a.out:dllimp.o dllmain.o
	gcc dllimp.o dllmain.o
dllmain.o:dllmain.c dll.mk
	gcc -c dllmain.c
dllimp.o:dllimp.c dll.mk
	gcc -c dllimp.c

	
