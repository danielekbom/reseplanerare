CC=gcc
FLAGS=-Wall -ggdb -std=c99

main: main.o travelPlannerClient.o graphlib.o
	$(CC) $(FLAGS) -o main main.o travelPlannerClient.o graphlib.o

main.o: main.c travelPlannerClient.h
	$(CC) $(FLAGS) -c main.c

travelPlannerClient.o: travelPlannerClient.c travelPlannerClient.h graphlib.h
	$(CC) $(FLAGS) -c travelPlannerClient.c

graphlib.o: graphlib.c graphlib.h
	$(CC) $(FLAGS) -c graphlib.c
