#include "graphlib.h"

struct graph{
  struct node* nodes[1024];
};

struct node{
  char* nodeName;
  struct edgedata* edges[20];
};

struct edgedata{
  struct node end;
  unsigned short travel_time;
  unsigned short bus_line;
};

void testFunction(){
  puts("TEST");
}

struct graph* createGraphFromFile(){
  FILE* file = fopen("data/nätverk.txt", "r");
  

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
