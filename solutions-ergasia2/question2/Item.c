#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_NUMBER 999

int ITEMrand(void) {
  return rand() % MAX_NUMBER + 1;
}

int ITEMscan(int *x) {
  return scanf("%d", x);
}

void ITEMshow(int x) {
  printf("%3d ", x);
}

int isNumber(char number[]) {
  int i = 0;

  //checking for negative numbers
  if (number[0] == '-')
      i = 1;
  for (; number[i] != 0; i++)
    if (!isdigit(number[i]))
        return 0;
  return 1;
}