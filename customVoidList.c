#include "customVoidList.h"

struct customVoidList{
  Listnode firstNode;
};

struct listnode{
   Listnode next;
   void *data;
};

CustomVoidList createNewList(){
  CustomVoidList newList = malloc(sizeof(CustomVoidList));
  newList->firstNode = NULL;
  return newList;
}

void addToList(CustomVoidList list, void* data){
  if(list->firstNode == NULL){
    list->firstNode = malloc(sizeof(Listnode));
    list->firstNode->data = data;
    list->firstNode->next = NULL;
    return;
  }
  Listnode tmpNode;
  tmpNode = list->firstNode;
  while(tmpNode->next != NULL){
    tmpNode = tmpNode->next;
  }
  Listnode newNode = malloc(sizeof(Listnode));
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
