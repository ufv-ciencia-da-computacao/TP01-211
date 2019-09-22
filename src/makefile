all: main clear

main: date.o shopping.o shoppingList.o node.o spmatrix.o menu.o main.o
	gcc main.o date.o shopping.o shoppingList.o node.o spmatrix.o menu.o -o main

date.o: libspmatrix/date.c
	gcc -c libspmatrix/date.c -o date.o

shopping.o: libspmatrix/shopping.c
	gcc -c libspmatrix/shopping.c -o shopping.o

shoppingList.o: libspmatrix/shoppingList.c
	gcc -c libspmatrix/shoppingList.c -o shoppingList.o

node.o: libspmatrix/node.c
	gcc -c libspmatrix/node.c -o node.o

spmatrix.o: libspmatrix/spmatrix.c
	gcc -c libspmatrix/spmatrix.c -o spmatrix.o

menu.o: libinterface/menu.c
	gcc -c libinterface/menu.c -o menu.o

main.o: main.c
	gcc -c main.c -o main.o

clear:
	del *.o
