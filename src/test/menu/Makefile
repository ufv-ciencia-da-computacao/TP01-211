all: menuTest clear

menuTest: date.o shopping.o shoppingList.o node.o spmatrix.o menu.o menu_main.o
	gcc date.o shopping.o shoppingList.o node.o spmatrix.o menu.o menu_main.o -o menuTest

menu_main.o: menu_main.c
	gcc -c menu_main.c -o menu_main.o

menu.o: ../../libinterface/menu.c
	gcc -c ../../libinterface/menu.c -o menu.o

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

clear:
	rm *.o
# del *.o
