#include "graphlib.h"

struct graph{
  Node nodes[2048];
};

struct node{
  char* nodeName;
  int edgesCount;
  Edge edges[20];
  Departure departures[512];
};

struct departure{
  Ushort busLine;
  Ushort departureTime;
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
  for(int i = 0; i < 20; ++i){
    newNode->edges[i] = NULL;
  }
  for(int i = 0; i < 512; ++i){
    newNode->departures[i] = NULL;
  }
  newNode->nodeName = nodeName;
  return newNode;
}

//Creates a new departure with the data from the parameters and returns a pointer to it
Departure createDeparture(Ushort busLine, Ushort departureTime){
  Departure newDeparture = malloc(sizeof(departure));
  newDeparture->busLine = busLine;
  newDeparture->departureTime = departureTime;
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

char* getNodeNameFromGraph(Graph srcGraph, Ushort nodeIndex){
  char* nodeName = malloc(sizeof(srcGraph->nodes[nodeIndex]->nodeName));
  strcpy(nodeName, srcGraph->nodes[nodeIndex]->nodeName);
  return nodeName;
}

Ushort getDepartureBusLine(Graph srcGraph, Ushort nodeIndex, Ushort departureIndex){
  return srcGraph->nodes[nodeIndex]->departures[departureIndex]->busLine;
}

Ushort getDepartureTime(Graph srcGraph, Ushort nodeIndex, Ushort departureIndex){
  return srcGraph->nodes[nodeIndex]->departures[departureIndex]->departureTime;
}

//Function to free mallocated memory by a graph
void destroyGraph(Graph graphToDestroy){
  assert(graphToDestroy != NULL);
  int nodeIndex = 0;
  int edgeIndex = 0;
  int departureIndex = 0;
  while(graphToDestroy->nodes[nodeIndex] != NULL){
    free(graphToDestroy->nodes[nodeIndex]->nodeName);
    while(graphToDestroy->nodes[nodeIndex]->edges[edgeIndex] != NULL){
      free(graphToDestroy->nodes[nodeIndex]->edges[edgeIndex]);
      ++edgeIndex;
    }
    while(graphToDestroy->nodes[nodeIndex]->departures[departureIndex] != NULL){
      free(graphToDestroy->nodes[nodeIndex]->departures[departureIndex]);
      ++departureIndex;
    }
    free(graphToDestroy->nodes[nodeIndex]);
    edgeIndex = 0;
    departureIndex = 0;
    ++nodeIndex;
  }
  free(graphToDestroy);
}
