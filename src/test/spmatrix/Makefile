all: spmatrix clear

spmatrix: date.o shopping.o shoppingList.o node.o spmatrix.o spmatrix_main.o
	gcc spmatrix_main.o date.o shopping.o shoppingList.o node.o spmatrix.o -o spmatrix

date.o: ../../libspmatrix/date.c
	gcc -c ../../libspmatrix/date.c -o date.o

shopping.o: ../../libspmatrix/shopping.c
	gcc -c ../../libspmatrix/shopping.c -o shopping.o

shoppingList.o: ../../libspmatrix/shoppingList.c
	gcc -c ../../libspmatrix/shoppingList.c -o shoppingList.o

node.o: ../../libspmatrix/node.c
	gcc -c ../../libspmatrix/node.c -o node.o

spmatrix.o: ../../libspmatrix/spmatrix.c
	gcc -c ../../libspmatrix/spmatrix.c -o spmatrix.o

spmatrix_main.o: spmatrix_main.c
	gcc -c spmatrix_main.c -o spmatrix_main.o

clear:
	rm *.o
