all: shoppingList_main clear

shoppingList_main: date.o shopping.o shoppingList.o shoppingList_main.o
	gcc shoppingList_main.o date.o shopping.o shoppingList.o -o shoppingList_main

date.o: ../../libspmatrix/date.c
	gcc -c ../../libspmatrix/date.c -o date.o

shopping.o: ../../libspmatrix/shopping.c
	gcc -c ../../libspmatrix/shopping.c -o shopping.o

shoppingList.o: ../../libspmatrix/shoppingList.c
	gcc -c ../../libspmatrix/shoppingList.c -o shoppingList.o


shoppingList_main.o: shoppingList_main.c
	gcc -c shoppingList_main.c -o shoppingList_main.o

clear:
	rm *.o
