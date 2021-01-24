a.out:seq_search.o seq_search_imp.o
	gcc seq_search.o seq_search_imp.o
seq_search.o:seq_search.c seq.mk
	gcc -c seq_search.c 
seq_search_imp.o:seq_search_imp.c seq.mk
	gcc -c seq_search_imp.c 
