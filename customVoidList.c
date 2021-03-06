#include "customVoidList.h"

struct customVoidList{
  Listnode firstNode;
};

struct listnode{
   Listnode next;
   void *data;
};

CustomVoidList createNewList(){
  CustomVoidList newList = malloc(sizeof(customVoidList));
  newList->firstNode = NULL;
  return newList;
}

void addToList(CustomVoidList list, void* data){
  Listnode tmpListnode;
  if(list->firstNode == NULL){
    tmpListnode = malloc(sizeof(listnode));
    list->firstNode = tmpListnode;
    list->firstNode->data = data;
    list->firstNode->next = NULL;
    return;
  }
  Listnode tmpNode;
  tmpNode = list->firstNode;
  while(tmpNode->next != NULL){
    tmpNode = tmpNode->next;
  }
  Listnode newNode = malloc(sizeof(listnode));
  tmpNode->next = newNode;
  newNode->data = data;
  newNode->next = NULL;
}

Listnode getFirst(CustomVoidList list){
  return list->firstNode;
}

Listnode getNext(Listnode srcListNode){
  return srcListNode->next;
}

void* getData(Listnode srcListNode){
  return srcListNode->data;
}

void removeNodeAtIndex(CustomVoidList list, int nodeIndex){
  Listnode prev = list->firstNode;

  if(nodeIndex == 0){
    Listnode ToRemove = list->firstNode;
    list->firstNode = list->firstNode->next;
    free(ToRemove);
    return;
  }

  for(int i = 0; i < nodeIndex-1; i++){
    prev = prev->next;
  }

  Listnode next = prev->next->next;
  Listnode toRemove = prev->next;

  prev->next = next;
  free(toRemove);
}

void destroyList(CustomVoidList list){
  Listnode tmpListnode = list->firstNode;
  Listnode tmptmpListnode;
  
  while(tmpListnode != NULL){
    tmptmpListnode = tmpListnode;
    tmpListnode = tmpListnode->next;
    free(tmptmpListnode->data);
    free(tmptmpListnode);
  }
  free(list);
}
