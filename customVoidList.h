#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _CUSTOMVOIDLIST_H
#define _CUSTOMVOIDLIST_H

typedef struct customVoidList customVoidList;
typedef customVoidList* CustomVoidList;
typedef struct listnode listnode;
typedef listnode* Listnode;

CustomVoidList createNewList();
void addToList(CustomVoidList list, void* data);
Listnode getFirst(CustomVoidList list);
Listnode getNext(Listnode srcListNode);
void* getData(Listnode srcListNode);
void destroyList(CustomVoidList list);

#endif
