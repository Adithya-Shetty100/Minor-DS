a.out:6bimp.o 6bmain.o
	gcc 6bimp.o 6bmain.o
6bimp.o:6bimp.c 6b.mk
	gcc -c 6bimp.c
6bmain.o:6bmain.c 6b.mk
	gcc -c 6bmain.c
