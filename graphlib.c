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
  struct node* endNode;
  unsigned short time;
  unsigned short busLine;
};

void testFunction(){
  struct node* testNode = malloc(sizeof(struct node));
  testNode = createNode("Gränby");
  printf("%s\n", testNode->nodeName);

  struct edge* testEdge = malloc(sizeof(struct edge));
  testEdge = createEdge(testNode, 10, 53);
  printf("%s\t%d\t%d\n", testEdge->endNode->nodeName, testEdge->time, testEdge->busLine);
}

struct graph* createGraph(){
  struct graph* newGraph = malloc(sizeof(struct graph));
  return newGraph;
}

struct node* createNode(char nodeName[]){
  struct node* newNode = malloc(sizeof(struct node));
  newNode->nodeName = nodeName;
  return newNode;
}

struct edge* createEdge(struct node* endNode, unsigned int time, unsigned short busLine){
  struct edge* newEdge = malloc(sizeof(struct edge));
  newEdge->endNode = endNode;
  newEdge->time = time;
  newEdge->busLine = busLine;
  return newEdge;
}

struct graph* createGraphFromFile(){
  FILE* file = fopen("data/nätverk.txt", "r");
  
  fclose(file);
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
