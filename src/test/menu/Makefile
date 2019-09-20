all: menuTest clear

menuTest: node.o spmatrix.o menu.o menu_main.o
	gcc node.o spmatrix.o menu.o menu_main.o -o menuTest

menu_main.o: menu_main.c
	gcc -c menu_main.c -o menu_main.o

menu.o: ../../libinterface/menu.c
	gcc -c ../../libinterface/menu.c -o menu.o

node.o: ../../libspmatrix/node.c
	gcc -c ../../libspmatrix/node.c -o node.o

spmatrix.o: ../../libspmatrix/spmatrix.c
	gcc -c ../../libspmatrix/spmatrix.c -o spmatrix.o

clear:
	rm *.o