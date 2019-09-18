all: node clear

node: node.o node_main.o
	gcc node_main.o node.o -o node

node.o: ../../libspmatrix/node.c
	gcc -c ../../libspmatrix/node.c -o node.o

node_main.o: node_main.c
	gcc -c node_main.c -o node_main.o

clear:
	rm *.o
	