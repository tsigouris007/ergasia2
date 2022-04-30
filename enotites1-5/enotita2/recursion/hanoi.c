#include <stdio.h>

void MoveTowers(int n, int start, int finish, int spare)
{
   if (n==1){
      printf("Move a disk from peg %1d to peg %1d\n", start, finish);
   } else {
      MoveTowers(n-1, start, spare, finish);
      printf("Move a disk from peg %1d to peg %1d\n", start, finish);
      MoveTowers(n-1, spare, finish, start);
   }
}




int main(void)
{
   MoveTowers(3,1,2,3);
}
