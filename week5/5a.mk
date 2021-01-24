a.out:5aimp.o 5amain.o
	gcc 5aimp.o 5amain.o
5aimp.o:5aimp.c 5a.mk
	gcc -c 5aimp.c
5amain.o:5amain.c 5a.mk
	gcc -c 5amain.c
	


