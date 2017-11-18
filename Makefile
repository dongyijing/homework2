#
CC = gcc
OBJ = main.o jacobi.o jacobicircle.o matrixa.o uswap.o vectorf.o
solution: $(OBJ)
	$(CC) -o solution $(OBJ) -lm

main.o: main.c
	gcc -c -g main.c
jacobi.o: jacobi.c
	gcc -c -g jacobi.c
jacobicircle.o: jacobicircle.c
	gcc -c -g jacobicircle.c
matrixa.o : matrixa.c
	gcc -c -g matrixa.c
vectorf.o: vectorf.c
	gcc -c -g vectorf.c
uswap.o: uswap.c
	gcc -c -g uswap.c
clean:
	rm -f *.o
