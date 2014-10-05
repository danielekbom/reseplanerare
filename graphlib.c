#include "graphlib.h"

struct graph{
  Node nodes[1024];
};

struct node{
  char* nodeName;
  int edgesCount;
  Departure departures[512];
  Edge edges[20];
};

struct departure{
  Ushort busLine;
  Ushort clockTime;
};

struct edge{
  Node endNode;
  Ushort travelTime;
  Ushort busLine;
};

//Temporary function used for testing during development
void testFunction(){
  Node testNode = createNode("Gränby");
  printf("%s\n", testNode->nodeName);

  Edge testEdge = createEdge(testNode, 10, 53);
  printf("%s\t%d\t%d\n", testEdge->endNode->nodeName, testEdge->travelTime, testEdge->busLine);

  Graph testGraph = createGraph();
  collectNodesFromFile(testGraph);
  printf("%s\n", testGraph->nodes[5]->nodeName);

  //Ushort hej = convertClockTimeToInt("13:37");
  //printf("%u\n", hej);

  destroyGraph(testGraph);

  free(testNode);
  free(testEdge);
}

//Creates a mew empty graph and returns a pointer to it
Graph createGraph(){
  Graph newGraph = calloc(sizeof(graph), 1);
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

//Creates a new departure with the data from the parameters and returns a pointer to it
Departure createDeparture(Ushort busLine, Ushort clockTime){
  Departure newDeparture = malloc(sizeof(departure));
  newDeparture->busLine = busLine;
  newDeparture->clockTime = clockTime;
  return newDeparture;
}

//Connects a departure to a node
void connectDeparture(Node nodeToExpand, Departure departureToConnect){
  int index = 0;
  while(nodeToExpand->departures[index] != NULL){
    ++index;
  }
  nodeToExpand->departures[index] = departureToConnect;
}

//Creates a new edge with the data from the parameters and returns a pointer to it
Edge createEdge(Node endNode, Uint travelTime, Ushort busLine){
  Edge newEdge = malloc(sizeof(edge));
  newEdge->endNode = endNode;
  newEdge->travelTime = travelTime;
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

//Unique data are fetched from file, converted to nodes, and then added to the graph parameter
void collectNodesFromFile(Graph nodeGraph){
  FILE* nodesFile = fopen("data/start.txt", "r");
  char* line = malloc(128);
  char* token;
  char* tmpToken = calloc(128, 1);
  char* nodeName;
  Node newNode;
  Ushort busLine;
  Ushort clockTime;
  while(fgets(line, 128, nodesFile) != NULL){
    token = strtok(line, ",");
    busLine = (unsigned short)atoi(token);
    // printf("%u\t", busLine);

    token = strtok(NULL, ",");
    if(token[0] == ' ') token++;
    if(strcmp(tmpToken, token)){
      nodeName = malloc(128);
      strcpy(nodeName, token);
      newNode = createNode(nodeName);
      addNodeToGraph(nodeGraph, newNode);
    }

    //token = strtok(NULL, "\n");
    //printf("%s\n", token);

    strcpy(tmpToken, token);
  }
  free(line);
  free(tmpToken);
  fclose(nodesFile);
}

//Converts a string in the format xx:xx to an Ushort xxxx
Ushort convertClockTimeToInt(char* clockTime){
  char tmpString[5];
  int clockTimeIndex = 0;
  int tmpStringIndex = 0;
  while(clockTimeIndex<5){
    if(clockTime[clockTimeIndex] != ':'){
      tmpString[tmpStringIndex] = clockTime[clockTimeIndex];
      ++tmpStringIndex;
    }
    ++clockTimeIndex;
  }
  return (unsigned short)atoi(tmpString);
}

//Function to free mallocated memory by a graph
void destroyGraph(Graph graphToDestroy){
  int nodeIndex = 0;
  int edgeIndex = 0;
  while(graphToDestroy->nodes[nodeIndex] != NULL){
    free(graphToDestroy->nodes[nodeIndex]->nodeName);
    while(graphToDestroy->nodes[nodeIndex]->edges[edgeIndex] != NULL){
      free(graphToDestroy->nodes[nodeIndex]->edges[edgeIndex]);
      ++edgeIndex;
    }
    free(graphToDestroy->nodes[nodeIndex]);
    edgeIndex = 0;
    ++nodeIndex;
  }
  free(graphToDestroy);
}
