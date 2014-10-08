#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifndef _GRAPHLIB_H
#define _GRAPHLIB_H

typedef unsigned int Uint;
typedef unsigned short Ushort;

typedef struct graph graph;
typedef struct node node;
typedef struct departure departure;
typedef struct edge edge;
typedef graph* Graph;
typedef node* Node;
typedef departure* Departure;
typedef edge* Edge;

void testFunction();
Graph createGraph();
void addNodeToGraph(Graph targetGraph, Node nodeToAdd);
Node createNode(char* nodeName);
Departure createDeparture(Ushort busLine, Ushort clockTime);
void connectDeparture(Node nodeToExpand, Departure departureToConnect);
Edge createEdge(Node endNode, unsigned int time, unsigned short busLine);
void connectEdge(Node startNode, Edge edgeToConnect);
void connectEdgeByNodeName(Graph srcGraph, char* nodeName, Edge edgeToConnect);

char* getNodeNameFromGraph(Graph srcGraph, Ushort nodeIndex);
Node getNodeByNameElseAddNode(Graph srcGraph, char* nodeName);
Ushort getDepartureBusLine(Graph srcGraph, Ushort nodeIndex, Ushort departureIndex);
Ushort getDepartureTime(Graph srcGraph, Ushort nodeIndex, Ushort departureIndex);

void printPossiblePaths(Graph srcGraph, char* fromNodeName, char* toNodeName);
struct array2d* getPossiblePaths(Node fromNode, Node toNode);
void printEdgePatterns(Node fromNode, struct array2d*  edgePatterns);

void destroyGraph(Graph graphToDestroy);

#endif
