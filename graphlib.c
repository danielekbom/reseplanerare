#include "graphlib.h"

struct node{
  char* nodeName;
  struct edgedata[];
};

struct edgedata{
  struct node end;
  unsigned short travel_time;
  unsigned short bus_line;
};

void testFunction(){
  puts("test");
}
