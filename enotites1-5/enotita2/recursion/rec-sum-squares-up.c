#include <stdio.h>

int SumSquares(int m, int n)
{
   if (m<n) {
      return m*m + SumSquares(m+1, n);
   } else {
      return m*m;
   }
}


int main(void)
{
   printf("%d\n", SumSquares(1,10));
}
