all: shopping_main clear

shopping_main: date.o shopping.o shopping_main.o
	gcc shopping_main.o shopping.o date.o -o shopping_main

date.o: ../../libspmatrix/date.c
	gcc -c ../../libspmatrix/date.c -o date.o

shopping.o: ../../libspmatrix/shopping.c
	gcc -c ../../libspmatrix/shopping.c -o shopping.o

shopping_main.o: shopping_main.c
	gcc -c shopping_main.c -o shopping_main.o

clear:
	rm *.o
#	del *.o
