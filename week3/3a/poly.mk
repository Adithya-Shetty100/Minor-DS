a.out:polymain.o polyimp.o
	gcc polymain.o polyimp.o
ploymain.o:polymain.c poly.mk
	gcc -c polymain.c
ployimp.o:polyimp.c poly.mk
	gcc -c polyimp.c
	
	

