a.out:etimp.o etmain.o
	gcc etimp.o etmain.o
etimp.o:etimp.c et.mk
	gcc -c etimp.c
etmain.o:etmain.c et.mk
	gcc -c etmain.c
