a.out:6aimp.o 6amain.o
	gcc 6aimp.o 6amain.o
6aimp.o:6aimp.c 6a.mk
	gcc -c 6aimp.c
6amain.o:6amain.c 6a.mk
	gcc -c 6amain.c
