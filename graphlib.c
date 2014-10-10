#include "graphlib.h"

struct graph{
  CustomVoidList nodes;
};

struct node{
  char* nodeName;
  int edgesCount;
  Edge edges[20];
  CustomVoidList departures;
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
void testFunction(Graph testGraph){
  Graph testGraphh = createGraph();

  Node testNode = createNode("hej");
  addNodeToGraph(testGraphh, testNode);

  Node testNode2 = createNode("hejj");
  addNodeToGraph(testGraphh, testNode2);

  int i = getNodeIndex(testGraphh, testNode);
  printf("%d\n", i);
  removeNode(testGraphh, testNode);

  i = getNodeIndex(testGraphh, testNode);
  printf("%d\n", i);
}

//Creates a mew empty graph and returns a pointer to it
Graph createGraph(){
  Graph newGraph = calloc(sizeof(Graph), 1);
  newGraph->nodes = createNewList();
  return newGraph;
}

//Adds the given node to the given graph
void addNodeToGraph(Graph targetGraph, Node nodeToAdd){
  addToList(targetGraph->nodes, nodeToAdd);
}

//Creates a new empty node with name nodeName and returns a pointer to it
Node createNode(char* nodeName){
  Node newNode = malloc(sizeof(node));
  for(int i = 0; i < 20; ++i){
    newNode->edges[i] = NULL;
  }
  newNode->departures = createNewList();
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
  addToList(nodeToExpand->departures, departureToConnect);
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

int getNodeIndex(Graph srcGraph, Node nodeToFind){
  int index = 0;
  Listnode first = getFirst(srcGraph->nodes);
  Node tmpNode;
  while(first != NULL){
    tmpNode = getData(first);
    if(!strcmp(tmpNode->nodeName, nodeToFind->nodeName)){
      return index;
    }
    first = getNext(first);
    index++;
  }
  return -1;
}

Node getNodeByNameElseAddNode(Graph srcGraph, char* nodeName){
  Listnode tmpListnode = getFirst(srcGraph->nodes);
  char* nodeNameFromGraph;
  Node tmpNode;
  while(tmpListnode != NULL){
    nodeNameFromGraph = ((Node)getData(tmpListnode))->nodeName;
    if(!strcmp(nodeNameFromGraph, nodeName)){
      return (Node)getData(tmpListnode);
    }
    tmpListnode = getNext(tmpListnode);
  }
  if(tmpListnode == NULL){
    tmpNode = createNode(nodeName);
    addNodeToGraph(srcGraph, tmpNode);
    return tmpNode;
  }
  return NULL;
}

void printPossiblePaths(Graph srcGraph, char* fromNodeName, char* toNodeName){
  Node fromNode = getNodeByNameElseAddNode(srcGraph, fromNodeName);
  Node toNode = getNodeByNameElseAddNode(srcGraph, toNodeName);
  Array2d edgePatterns = getPossiblePaths(fromNode, toNode);
  printEdgePatterns(fromNode, edgePatterns);
  free(edgePatterns);
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
      printf("Mojlig resvag med busslinje %u:\n", fromNode->edges[index]->busLine);
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

void printDeparturesInClockFormat(Node srcNode){
  int index = 0;
  Listnode departureNode = getFirst(srcNode->departures);
  Departure currentDeparture;
  char* departureTime;

  while(departureNode != NULL){
    currentDeparture = getData(departureNode);
    departureTime = convertDepartureTimeToString(currentDeparture->departureTime);
    printf("%u\t%s\n", currentDeparture->busLine, departureTime);
    departureNode = getNext(departureNode);
    free(departureTime);
    index++;
  }
}

char* convertDepartureTimeToString(int departureTime){
  char* departureTimeString = malloc(sizeof(char)*6);
  char tmpDepartureTimeString[5];
  sprintf(tmpDepartureTimeString, "%u", departureTime);
  if(departureTime < 1000){
    departureTimeString[0] = tmpDepartureTimeString[0];
    departureTimeString[1] = ':';
    departureTimeString[2] = tmpDepartureTimeString[1];
    departureTimeString[3] = tmpDepartureTimeString[2];
    departureTimeString[4] = '\0';
  } else {
    departureTimeString[0] = tmpDepartureTimeString[0];
    departureTimeString[1] = tmpDepartureTimeString[1];
    departureTimeString[2] = ':';
    departureTimeString[3] = tmpDepartureTimeString[2];
    departureTimeString[4] = tmpDepartureTimeString[3];
    departureTimeString[5] = '\0';
  }
  return departureTimeString;
}

void removeNode(Graph srcGraph, Node nodeToRemove){
  int nodeIndex = getNodeIndex(srcGraph, nodeToRemove);
  removeNodeAtIndex(srcGraph->nodes, nodeIndex);
  
  /* Listnode listNode = getFirst(srcGraph->nodes);
  while(getData(listNode) != nodeToRemove){
    listNode = getNext(listNode);
  }
  Listnode prevNode = listNode - 1;
  Listnode nextNode = listNode + 1;
  Listnode tmpNode = getNext(prevNode);
  tmpNode = nextNode;
  free(listNode);*/
}

//Function to free mallocated memory by a graph
void destroyGraph(Graph graphToDestroy){
  assert(graphToDestroy != NULL);
  Listnode tmpListnode = getFirst(graphToDestroy->nodes);
  Node tmpNode;
  int edgeIndex = 0;
  while(tmpListnode != NULL){
    tmpNode = getData(tmpListnode);
    while(tmpNode->edges[edgeIndex] != NULL && edgeIndex < 20){
      free(tmpNode->edges[edgeIndex]);
      edgeIndex++;
    }
    edgeIndex = 0;
    destroyList(tmpNode->departures);
    free(tmpNode->nodeName);
    tmpListnode = getNext(tmpListnode);
  }
  destroyList(graphToDestroy->nodes);
  free(graphToDestroy);
}
