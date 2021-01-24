a.out:bstimp.o bstmain.o
	gcc bstimp.o bstmain.o
bstimp.o:bstimp.c bst.mk
	gcc -c bstimp.c
bstmain.o:bstmain.c bst.mk
	gcc -c bstmain.c
