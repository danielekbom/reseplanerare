#include <stdio.h>
#include <stdlib.h>

#ifndef _GRAPHLIB_H
#define _GRAPHLIB_H

struct graph;
struct node;
struct edge;

void testFunction();
struct graph* createGraphFromFile();
struct graph* createGraph();
struct node* createNode();
void printFile();

#endif
