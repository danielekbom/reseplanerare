#include "graphlib.h"

struct graph{
  struct node* nodes[1024];
};

struct node{
  char* nodeName;
  int edgesCount;
  struct edge* edges[20];
};

struct edge{
  struct node end;
  unsigned short travel_time;
  unsigned short bus_line;
};

void testFunction(){
  puts("TEST");
}

struct graph* createGraphFromFile(){
  FILE* file = fopen("data/nätverk.txt", "r");
  
  fclose(file);
  return NULL;
}


struct graph* createGraph(){
  struct graph* newGraph = malloc(sizeof(struct graph));
  return newGraph;
}

struct node* createNode(){
  
  return NULL;
}



void printFile(){
  FILE* fileToRead;
  fileToRead = fopen("data/nätverk.txt", "r");

  char str[100];

  while(fgets(str, 100, fileToRead) != NULL){
    puts(str);
  }
  fclose(fileToRead);

}
