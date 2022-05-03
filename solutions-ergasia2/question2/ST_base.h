#include "Item_base.h"

typedef struct STnode* link;
struct STnode {
  Item item;
  link l, r;
  int N;
};

static link head, z;
