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

struct array2d{
  int array[16][32];
};

//Temporary function used for testing during development
void testFunction(){

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

void connectEdgeByNodeName(Graph srcGraph, char* nodeName, Edge edgeToConnect){
  connectEdge(getNodeByNameElseAddNode(srcGraph, nodeName), edgeToConnect);
}

char* getNodeNameFromGraph(Graph srcGraph, Ushort nodeIndex){
  char* nodeName = malloc(sizeof(srcGraph->nodes[nodeIndex]->nodeName));
  strcpy(nodeName, srcGraph->nodes[nodeIndex]->nodeName);
  return nodeName;
}

Node getNodeByNameElseAddNode(Graph srcGraph, char* nodeName){
  int index = 0;
  Node tmpNode;
  if(srcGraph->nodes[0] != NULL){
    while(strcmp(srcGraph->nodes[index]->nodeName, nodeName)){
      ++index;
      if(srcGraph->nodes[index] == NULL){
	break;
      }
    }
  }
  if(srcGraph->nodes[index] == NULL){
    tmpNode = createNode(nodeName);
    addNodeToGraph(srcGraph, tmpNode);
    return tmpNode;
  }
  return srcGraph->nodes[index];
}

Ushort getDepartureBusLine(Graph srcGraph, Ushort nodeIndex, Ushort departureIndex){
  return srcGraph->nodes[nodeIndex]->departures[departureIndex]->busLine;
}

Ushort getDepartureTime(Graph srcGraph, Ushort nodeIndex, Ushort departureIndex){
  return srcGraph->nodes[nodeIndex]->departures[departureIndex]->departureTime;
}

void printPossiblePaths(Graph srcGraph, char* fromNodeName, char* toNodeName){
  Node fromNode = getNodeByNameElseAddNode(srcGraph, fromNodeName);
  Node toNode = getNodeByNameElseAddNode(srcGraph, toNodeName);
  Array2d edgePatterns = getPossiblePaths(fromNode, toNode);
  printEdgePatterns(fromNode, edgePatterns);
}

Array2d getPossiblePaths(Node fromNode, Node toNode){
  Array2d edgePatterns = malloc(sizeof(array2d));
  memset(edgePatterns->array, -1, sizeof(array2d));
  Ushort busLine;
  Ushort prevBusLine;
  Node nextNode;
  int index = 0;
  int innerIndex = 0;
  int temp = 0;
  while(fromNode->edges[index] != NULL){
    prevBusLine = fromNode->edges[index]->busLine;
    nextNode = fromNode->edges[index]->endNode;
    edgePatterns->array[index][temp] = index;
    if(!strcmp(fromNode->edges[index]->endNode->nodeName, toNode->nodeName)){
      continue;
    }
    if(nextNode->edges[innerIndex] == NULL){
      edgePatterns->array[index][0] = -1;
      continue;
    }
    temp++;
    while(nextNode->edges[innerIndex] != NULL){
      busLine = nextNode->edges[innerIndex]->busLine;
      if(!strcmp(nextNode->edges[innerIndex]->endNode->nodeName, toNode->nodeName) && busLine == prevBusLine){
	edgePatterns->array[index][temp] = innerIndex;
	nextNode = nextNode->edges[innerIndex]->endNode;
	break;
      }
      if(busLine == prevBusLine){
	edgePatterns->array[index][temp] = innerIndex;
	nextNode = nextNode->edges[innerIndex]->endNode;
	innerIndex = 0;
	temp++;
	continue;
      }
      if(nextNode->edges[0] == NULL || busLine != prevBusLine){
	if(nextNode->edges[0] == NULL){
	  edgePatterns->array[index][0] = -1;
	  break;
	}
	innerIndex++;
	continue;
      }
      innerIndex++;
    }
    if(strcmp(nextNode->nodeName, toNode->nodeName)){
	edgePatterns->array[index][0] = -1;
    }
    innerIndex = 0;
    temp = 0;
    index++;
  }

  return edgePatterns;
}

void printEdgePatterns(Node fromNode, Array2d edgePatterns){
  Node tmpNode = fromNode;
  int index = 0;
  int innerIndex = 0;
  Ushort time = 0;
  Ushort totalTravelTime = 0;
  while(index < 16){
    if(edgePatterns->array[index][0] != -1){
      printf("Möjlig resväg med busslinje %u:\n", fromNode->edges[index]->busLine);
      printf("%s", tmpNode->nodeName);
      while(edgePatterns->array[index][innerIndex] != -1){
	if(tmpNode->edges[edgePatterns->array[index][innerIndex]] != NULL){
	  time = tmpNode->edges[edgePatterns->array[index][innerIndex]]->travelTime;
	  tmpNode = tmpNode->edges[edgePatterns->array[index][innerIndex]]->endNode;
	  printf(" -> Restid: %u min -> %s", time, tmpNode->nodeName);
	  totalTravelTime += time;
	}
	innerIndex++;
      }
      printf("\nTotal restid: %u min\n", totalTravelTime); 
      innerIndex = 0;
      totalTravelTime = 0;
      tmpNode = fromNode;
      puts("");
    }
    index++;
  }
}

void printDepartures(Node srcNode){
  int departureTime;
  int index = 0;
  int timeFirstPart = 0;
  int timeSecondPart = 0;

  while(srcNode->departures[index] != NULL){
    departureTime = srcNode->departures[index]->departureTime;
    if(departureTime < 1000){
      timeFirstPart = departureTime;
      while(timeFirstPart >= 10){
	timeFirstPart /= 10;
      }
    } else {
      timeFirstPart = departureTime;
      while(timeFirstPart >= 100){
	timeFirstPart /= 10;
      }
    }
    timeSecondPart = departureTime;
    timeSecondPart %= 100;
    printf("%u\t%d:%d\n", srcNode->departures[index]->busLine, timeFirstPart, timeSecondPart);
    index++;
  }
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
