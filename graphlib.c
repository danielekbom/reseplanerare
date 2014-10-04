#include "graphlib.h"

struct graph{
  Node nodes[1024];
};

struct node{
  char* nodeName;
  int edgesCount;
  Edge edges[20];
};

struct edge{
  Node endNode;
  Ushort time;
  Ushort busLine;
};

void testFunction(){
  Node testNode = malloc(sizeof(node));
  testNode = createNode("Gränby");
  printf("%s\n", testNode->nodeName);

  Edge testEdge = malloc(sizeof(edge));
  testEdge = createEdge(testNode, 10, 53);
  printf("%s\t%d\t%d\n", testEdge->endNode->nodeName, testEdge->time, testEdge->busLine);
}





Graph createGraph(){
  Graph newGraph = malloc(sizeof(graph));
  return newGraph;
}

Node createNode(char nodeName[]){
  Node newNode = malloc(sizeof(node));
  newNode->nodeName = nodeName;
  return newNode;
}

Edge createEdge(Node endNode, Uint time, Ushort busLine){
  Edge newEdge = malloc(sizeof(edge));
  newEdge->endNode = endNode;
  newEdge->time = time;
  newEdge->busLine = busLine;
  return newEdge;
}

void connectEdge(Node startNode, Edge edgeToConnect){

}







Graph createGraphFromFile(){
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
