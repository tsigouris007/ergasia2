#include <stdio.h>

int Factorial(int n)
{
   int i, f;

   f=1;
   for (i=2; i<=n; ++i) f*=i;
   return f;
}


int main(void)
{
   printf("%d\n", Factorial(5));
}
