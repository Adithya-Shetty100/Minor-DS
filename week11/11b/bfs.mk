a.out:bfsimp.o bfsmain.o
	gcc bfsimp.o bfsmain.o
bfsimp.o:bfsimp.c bfs.mk
	gcc -c bfsimp.c
bfsmain.o:bfsmain.c bfs.mk
	gcc -c bfsmain.c
