a.out:trieimp.o triemain.o
	gcc trieimp.o triemain.o
trieimp.o:trieimp.c trie.mk
	gcc -c trieimp.c
triemain.o:triemain.c trie.mk
	gcc -c triemain.c
