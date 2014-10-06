#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graphlib.h"

#ifndef _BUSNETWORKIMPORTER_h
#define _BUSNETWORKIMPORTER_h

Graph importNetwork();
void collectNodesFromFile(Graph nodeGraph);
Ushort convertClockTimeToShort(char* clockTime);

#endif
