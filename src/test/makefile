all: shopping clear

shopping: shopping.o shopping_main.o
	gcc shopping_main.o shopping.o -o shopping

shopping.o: ../libspmatrix/shopping.c
	gcc -c ../libspmatrix/shopping.c -o shopping.o

shopping_main.o: shopping_main.c
	gcc -c shopping_main.c -o shopping_main.o

clear:
	del *.o
