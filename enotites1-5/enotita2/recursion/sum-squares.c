#include <stdio.h>

int SumSquares(int m, int n)
{
   int i, sum;

   sum=0;
   for (i=m; i<=n; ++i) sum +=i*i;
   return sum;
}

int main(void)
{
   printf("%d\n", SumSquares(1,10));
}
