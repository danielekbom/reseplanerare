#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
Departure createDeparture(Ushort clockTime, Ushort busLine);
void connectDeparture(Node nodeToExpand, Departure departureToConnect);
Edge createEdge(Node endNode, unsigned int time, unsigned short busLine);
void connectEdge(Node startNode, Edge edgeToConnect);

void collectNodesFromFile(Graph nodeGraph);

void destroyGraph(Graph graphToDestroy);

#endif
