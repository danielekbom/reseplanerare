#include "main.h"

int main(int argc, char* argv[]){

  testFunction();
  struct node* testNode = malloc(sizeof(struct node*));
  testNode = createNode("Hej");
  printf("%s\n", testNode->nodeName);

  return 0;
}
