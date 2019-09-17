all: shoppingList_main clear

shoppingList_main: shopping.o shoppingList.o shoppingList_main.o
	gcc shoppingList_main.o shopping.o shoppingList.o -o shoppingList_main

shopping.o: ../../libspmatrix/shopping.c
	gcc -c ../../libspmatrix/shopping.c -o shopping.o

shoppingList.o: ../../libspmatrix/shoppingList.c
	gcc -c ../../libspmatrix/shoppingList.c -o shoppingList.o


shoppingList_main.o: shoppingList_main.c
	gcc -c shoppingList_main.c -o shoppingList_main.o

clear:
	del *.o
