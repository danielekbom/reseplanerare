#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "customVoidList.h"

#ifndef _GRAPHLIB_H
#define _GRAPHLIB_H

//graphlib is a library used to create graphs containging labeled nodes which are connected by
//labeled edges. The edges then contain weights which is used to find the shortest path between nodes.
//Nodes can also contain additional infotmation called departures, which is used to store edge labels
//and a timestamp. The departures can be used for example in a bus network to specify times when edges
//(bus lines) departure.

typedef unsigned int Uint;
typedef unsigned short Ushort;
typedef struct graph graph;
typedef struct node node;
typedef struct departure departure;
typedef struct edge edge;
typedef struct array2d array2d;
typedef graph* Graph;
typedef node* Node;
typedef departure* Departure;
typedef edge* Edge;
typedef array2d* Array2d;

//testFunction used in development purposes, will be deleted soon.
void testFunction(Graph testGraph);
//Creates a new graph on the heap and returns a pointer to it.
Graph createGraph();
//Adds a new node ("nodeToAdd") to the graph "targetGraph".
void addNodeToGraph(Graph targetGraph, Node nodeToAdd);
//Creates a new node on the heap labeled "nodeName" and returns a pointer to it.
Node createNode(char* nodeName);

//Creates a new departure on the heap with the data "busLine" and "clockTime" and returns a pointer to it.
Departure createDeparture(Ushort busLine, Ushort clockTime);
//Connects the departure "departureToConnect" to the node "nodeToExpand".
void connectDeparture(Node nodeToExpand, Departure departureToConnect);
//Creates a new edge on the heap with the endnode "endNode", the data "time" and "busLine" and returns a pointer to it.
Edge createEdge(Node endNode, unsigned int time, unsigned short busLine);
//Connects the edge "edgeToConnect" to the node "startNode".
void connectEdge(Node startNode, Edge edgeToConnect);
//Connects the edge "edgeToConnect" to the node named "nodeName" in "srcGraph".
void connectEdgeByNodeName(Graph srcGraph, char* nodeName, Edge edgeToConnect);

//Returns the index of node "nodeToFind" in the graph "srcGraph".
int getNodeIndex(Graph srcGraph, Node nodeToFind);
//Returns a pointer to the node named "nodeName" in graph "srcGraph". If the node does not exists it is added to the graph.
Node getNodeByNameElseAddNode(Graph srcGraph, char* nodeName);

//Prints possible paths from node "fromNodeName" to node "toNodeName".
void printPossiblePaths(Graph srcGraph, char* fromNodeName, char* toNodeName);
//Prints the fastest path from node "fromNodeName" to node "toNodeName".
void printFastestPath(Graph srcGraph, char* fromNodeName, char* toNodeName);
//Returns an pointer to an array2d containing possible paths between node "fromNode" and node "toNode".
Array2d getPossiblePaths(Node fromNode, Node toNode);
//Helper function to printPossiblePaths.
void printEdgePatterns(Node fromNode, Array2d  edgePatterns);
//Helper function to printFastestPath.
void printFastestEdgePattern(Node fromNode, Array2d edgePatterns);
//Prints a nodes ("srcNode") departures in clockformat, i.e. xxxx is printed as xx:xx.
void printDeparturesInClockFormat(Node srcNode);
//Converts a departure time to string format, i.e. xxxx is converted to "xxxx".
char* convertDepartureTimeToString(int departureTime);

//Removes the node "nodeToRemove" from the graph "srcGraph".
void removeNode(Graph srcGraph, Node nodeToRemove);
//Removes the edge with edge label "edgeLabel" from node "srcNode".
void removeEdge(Node srcNode, Ushort edgeLabel);
//Frees all the memory allocated by the graph "graphToDestroy" and all of its nodes.
void destroyGraph(Graph graphToDestroy);

#endif
