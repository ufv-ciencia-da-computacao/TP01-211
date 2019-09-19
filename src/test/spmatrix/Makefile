all: spmatrix clear

spmatrix: node.o spmatrix.o spmatrix_main.o
	gcc spmatrix_main.o node.o spmatrix.o -o spmatrix

node.o: ../../libspmatrix/node.c
	gcc -c ../../libspmatrix/node.c -o node.o

spmatrix.o: ../../libspmatrix/spmatrix.c
	gcc -c ../../libspmatrix/spmatrix.c -o spmatrix.o

spmatrix_main.o: spmatrix_main.c
	gcc -c spmatrix_main.c -o spmatrix_main.o

clear:
	rm *.o