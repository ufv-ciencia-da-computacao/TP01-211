all: date_main clear

date_main: date.o date_main.o
	gcc date_main.o date.o -o date_main

date.o: ../../libspmatrix/date.c
	gcc -c ../../libspmatrix/date.c -o date.o

date_main.o: date_main.c
	gcc -c date_main.c -o date_main.o

clear:
	del *.o
