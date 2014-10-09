#include "customVoidList.h"

struct voidlist {
   Voidlist next;
   void *data;
};

void addToList(Voidlist firstNode, void* data){
  if(firstNode == NULL){
    firstNode->data = data;
    firstNode->next = NULL;
  }
  while(firstNode != NULL){
    firstNode = firstNode->next;
  }
  Voidlist newNode = malloc(sizeof(Voidlist));
  firstNode->next = newNode;
  newNode->data = data;
  newNode->next = NULL;
}
