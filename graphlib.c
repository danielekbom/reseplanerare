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

//Temporary function used for testing during development
void testFunction(){
  Node testNode = malloc(sizeof(node));
  testNode = createNode("Gränby");
  printf("%s\n", testNode->nodeName);

  Edge testEdge = malloc(sizeof(edge));
  testEdge = createEdge(testNode, 10, 53);
  printf("%s\t%d\t%d\n", testEdge->endNode->nodeName, testEdge->time, testEdge->busLine);

  Node testNodeFrom = malloc(sizeof(node));
  testNodeFrom = createNode("Pollacks");

  connectEdge(testNodeFrom, testEdge);
  printf("%s\t%d\t%s\n", testNodeFrom->nodeName, testNodeFrom->edges[0]->busLine, testNodeFrom->edges[0]->endNode->nodeName); 

  Graph testGraph = createGraph();
  collectNodesFromFile(testGraph);
  printf("%s\n", testGraph->nodes[2]->nodeName);
}




//Creates a mew empty graph and returns a pointer to it
Graph createGraph(){
  Graph newGraph = malloc(sizeof(graph));
  return newGraph;
}

//Adds the given node to the given graph
void addNodeToGraph(Graph targetGraph, Node nodeToAdd){
  int index = 0;
  while(targetGraph->nodes[index] != NULL){
    ++index;
  }
  targetGraph->nodes[index] = nodeToAdd;
}

//Creates a new empty node with name nodeName and returns a pointer to it
Node createNode(char* nodeName){
  Node newNode = malloc(sizeof(node));
  newNode->nodeName = nodeName;
  return newNode;
}

//Creates a new edge with the data from the incomming parameters and returns a pointer to it
Edge createEdge(Node endNode, Uint time, Ushort busLine){
  Edge newEdge = malloc(sizeof(edge));
  newEdge->endNode = endNode;
  newEdge->time = time;
  newEdge->busLine = busLine;
  return newEdge;
}

//Connects an edge to a node, - the node will hence be the startnode
void connectEdge(Node startNode, Edge edgeToConnect){
  int index = 0;
  while(startNode->edges[index] != NULL){
    ++index;
  }
  startNode->edges[index] = edgeToConnect;
}

void collectNodesFromFile(Graph nodeGraph){
  FILE* nodesFile = fopen("data/start.txt", "r");
  char* line = malloc(128);
  char* token = malloc(128);
  char* tmpToken = malloc(128);
  Node newNode;
  while(fgets(line, 128, nodesFile) != NULL){
    token = strtok(line, ",");
    token = strtok(NULL, ",");
    //if(token[0] == ' ') token++;
    if(strcmp(tmpToken, token)){
      printf("%s\n", token);
      newNode = createNode(token);
      addNodeToGraph(nodeGraph, newNode);
    }
    strcpy(tmpToken, token);
  }
  fclose(nodesFile);
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
