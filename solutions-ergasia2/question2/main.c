#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Item_base.h"
#include "Item.h"
#include "ST_base.h"
// #include "ST.h"
#include "BST.h"

int main(int argc, char *argv[]) {
  // Program checks
  if (argc != 3) {
    printf("usage: %s <max_nodes> <input_type>\n", argv[0]);
    printf("\tmax_nodes:\t Max number of nodes (int)\n");
    printf("\tinput_type:\t Input type of nodes (int). Accepted values: [0, 1].\n");
    printf("\t\t\t 0: Random number, 1: Input from keyboard\n");
    return 1;
  }
  if (isNumber(argv[1]) == 0) {
    printf("\"max_nodes\" has to be an integer\n");
    return 1;
  }
  if (isNumber(argv[2]) == 0) {
    printf("\"input_type\" has to be an integer\n");
    return 1;
  }

  int N, maxN = atoi(argv[1]), sw = atoi(argv[2]);

  if (sw != 0 && sw != 1) {
    printf("\"input_type\" has to be in range of [0, 1]\n");
    return 1;
  }
  srand(time(NULL));

  Key v;
  Item item;

  STinit(maxN);
  for (N = 0; N < maxN; N++) {
    if (sw == 0)
      v = ITEMrand();
    else if (ITEMscan(&v) == EOF)
      break;

    if (STsearch(v) != NULLitem)
      continue;

    printf("Inserting: %d\n", v);
    key(item) = v;
    STinsert(item);
  }

  printf("\nPrinting items:\n");
  STsort(ITEMshow);
  printf("\n");

  printf("\nSummary:\n");
  printf("%d keys ", N);
  printf("%d distinct keys\n", STcount());

  return 0;
}
