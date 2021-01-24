a.out:dfsimp.o dfsmain.o
	gcc dfsimp.o dfsmain.o
dfsimp.o:dfsimp.c dfs.mk
	gcc -c dfsimp.c
dfsmain.o:dfsmain.c dfs.mk
	gcc -c dfsmain.c
