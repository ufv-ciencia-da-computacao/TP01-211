all: node clear

node: date.o shopping.o shoppingList.o node.o node_main.o
	gcc date.o shopping.o shoppingList.o node.o node_main.o -o node

date.o: ../../libspmatrix/date.c
	gcc -c ../../libspmatrix/date.c -o date.o

shopping.o: ../../libspmatrix/shopping.c
	gcc -c ../../libspmatrix/shopping.c -o shopping.o

shoppingList.o: ../../libspmatrix/shoppingList.c
	gcc -c ../../libspmatrix/shoppingList.c -o shoppingList.o

node.o: ../../libspmatrix/node.c
	gcc -c ../../libspmatrix/node.c -o node.o

node_main.o: node_main.c
	gcc -c node_main.c -o node_main.o

clear:
	del *.o
	