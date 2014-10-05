CC=gcc
FLAGS=-Wall -ggdb -std=c99


main: main.o graphlib.o
	$(CC) $(FLAGS) -o main main.o graphlib.o

main.o: main.c graphlib.h
	$(CC) $(FLAGS) -c main.c

graphlib.o: graphlib.c graphlib.h
	$(CC) $(FLAGS) -c graphlib.c
