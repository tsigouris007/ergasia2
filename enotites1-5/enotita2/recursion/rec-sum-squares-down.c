#include <stdio.h>

int SumSquares(int m, int n) {
   if (m<n) {
      return SumSquares(m, n-1) + n*n;
   } else {
      return n*n;
   }
}



int main(void)
{
   printf("%d\n", SumSquares(1,10));
}
