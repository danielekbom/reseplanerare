#include <stdio.h>
#include <stdlib.h>

#ifndef _GRAPHLIB_H
#define _GRAPHLIB_H

typedef unsigned int Uint;
typedef unsigned short Ushort;

typedef struct graph graph;
typedef struct node node;
typedef struct edge edge;
typedef graph* Graph;
typedef node* Node;
typedef edge* Edge;

void testFunction();
Graph createGraph();
Node createNode(char nodeName[]);
Edge createEdge(Node endNode, unsigned int time, unsigned short busLine);
void connectEdge(Node startNode, Edge edgeToConnect);

#endif
