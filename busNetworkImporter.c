#include "busNetworkImporter.h"

void importNetwork(){
  Graph testGraph2 = createGraph();
  collectNodesFromFile(testGraph2);

  destroyGraph(testGraph2);
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
    printf("%s\n", token);
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
