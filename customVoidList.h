#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _CUSTOMVOIDLIST_H
#define _CUSTOMVOIDLIST_H

typedef struct voidlist voidlist;
typedef voidlist* Voidlist;

void addToList(Voidlist firstNode, void* data);

#endif
