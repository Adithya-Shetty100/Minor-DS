a.out:main.o sllimp.o
	gcc  main.o sllimp.o
main.o:main.c sll.mk
	gcc -c main.c
sllimp.o:sllimp.c sll.mk
	gcc -c sllimp.c

