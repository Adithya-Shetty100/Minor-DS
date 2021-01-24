a.out:tbtimp.o tbtmain.o
	gcc tbtimp.o tbtmain.o
tbtimp.o:tbtimp.c tbt.mk
	gcc -c tbtimp.c
tbtmain.o:tbtmain.c tbt.mk
	gcc -c tbtmain.c
