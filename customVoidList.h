#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _CUSTOMVOIDLIST_H
#define _CUSTOMVOIDLIST_H

//customVoidList is a linked list where generic data can be stored.
//struct customVoidList is the list itself, which contains strucs listnodes which represents the nodes.

//A type named customVoidList is defined as a struct customVoidList.
typedef struct customVoidList customVoidList;
//A type named CustomVoidList is defined as a pointer to customVoidList
typedef customVoidList* CustomVoidList;
//A type named listnode is defined as a struct listnode
typedef struct listnode listnode;
//A type named Listnode is defined as a pointer to listnode
typedef listnode* Listnode;

//Creates a new customVoidList on the heap and returns a pointer to it.
CustomVoidList createNewList();
//Adds a new item to the end of the list containing the generic data from the "data" parameter.
void addToList(CustomVoidList list, void* data);
//Returns a pointer to the first element in the customVoidList parameter. 
Listnode getFirst(CustomVoidList list);
//Returns a pointer to the next element in with srcListNode as starting point.
Listnode getNext(Listnode srcListNode);
//Returns the data from the element pointed to by the srcListNode parameter.
void* getData(Listnode srcListNode);
//Removes the element at index "nodeIndex" from "list".
void removeNodeAtIndex(CustomVoidList list, int nodeIndex);
//Frees all the memory allocated by the list and its elements.
void destroyList(CustomVoidList list);

#endif
