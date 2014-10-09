CC=gcc
FLAGS=-Wall -ggdb -std=c99

main: main.o travelPlannerClient.o busNetworkImporter.o graphlib.o customVoidList.o
	$(CC) $(FLAGS) -o main main.o travelPlannerClient.o busNetworkImporter.o graphlib.o customVoidList.o

main.o: main.c travelPlannerClient.h
	$(CC) $(FLAGS) -c main.c

travelPlannerClient.o: travelPlannerClient.c travelPlannerClient.h graphlib.h busNetworkImporter.h
	$(CC) $(FLAGS) -c travelPlannerClient.c

busNetworkImporter.o: busNetworkImporter.c busNetworkImporter.h graphlib.h
	$(CC) $(FLAGS) -c busNetworkImporter.c

graphlib.o: graphlib.c graphlib.h customVoidList.h
	$(CC) $(FLAGS) -c graphlib.c

customVoidList.o: customVoidList.c customVoidList.h
	$(CC) $(FLAGS) -c customVoidList.c
