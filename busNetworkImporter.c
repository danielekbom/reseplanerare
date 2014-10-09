#include "busNetworkImporter.h"

Graph importNetwork(){
  Graph importedGraph = createGraph();
  collectNodesFromFile(importedGraph);
  collectEdgesFromFile(importedGraph);
  return importedGraph;
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
  Ushort departureTime;
  Departure newDeparture;

  while(fgets(line, 128, nodesFile) != NULL){
    token = strtok(line, ",");
    busLine = (unsigned short)atoi(token);

    token = strtok(NULL, ",");
    if(token[0] == ' ') token++;
    if(strcmp(tmpToken, token)){
      nodeName = malloc(128);
      strcpy(nodeName, token);
      newNode = createNode(nodeName);
      addNodeToGraph(nodeGraph, newNode);
    }

    strcpy(tmpToken, token);

    token = strtok(NULL, "\n");
    if(token[0] == ' ') token++;
    departureTime = convertClockTimeToShort(token);
    newDeparture = createDeparture(busLine, departureTime);
    connectDeparture(newNode, newDeparture);
  }
  free(line);
  free(tmpToken);
  fclose(nodesFile);
}

void collectEdgesFromFile(Graph nodeGraph){
  FILE* edgesFile = fopen("data/natverk.txt", "r");
  char* line = malloc(128);
  char* token;
  char nodeToExpand[64];
  char* endNodeName;
  Ushort travelTime;
  Ushort busLine;
  Edge newEdge;

  while(fgets(line, 128, edgesFile) != NULL){
    endNodeName = calloc(64, 1);
    token = strtok(line, ",");
    busLine = (Ushort)atoi(token);

    token = strtok(NULL, ",");
    if(token[0] == ' ') token++;
    strcpy(nodeToExpand, token);

    token = strtok(NULL, ",");
    if(token[0] == ' ') token++;
    strcpy(endNodeName, token);

    token = strtok(NULL, ",");
    if(token[0] == ' ') token++;
    travelTime = (Ushort)atoi(token);

    newEdge = createEdge(getNodeByNameElseAddNode(nodeGraph, endNodeName), travelTime, busLine);
    connectEdgeByNodeName(nodeGraph, nodeToExpand, newEdge);
  }
  free(line);
  fclose(edgesFile);
}

//Converts a string in the format xx:xx to an Ushort xxxx
Ushort convertClockTimeToShort(char* clockTime){
  char tmpString[5];
  int clockTimeIndex = 0;
  int tmpStringIndex = 0;
  while(clockTime[clockTimeIndex] != '\0'){
    if(clockTime[clockTimeIndex] != ':'){
      tmpString[tmpStringIndex] = clockTime[clockTimeIndex];
      ++tmpStringIndex;
    }
    ++clockTimeIndex;
  }
  tmpString[tmpStringIndex] = '\0';
  return (unsigned short)atoi(tmpString);
}
