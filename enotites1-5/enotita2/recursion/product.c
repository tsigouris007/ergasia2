#include <stdio.h>

int Product(int m, int n)
{
   int middle;

   if (m==n) {
     return m;
   } else {
     middle=(m+n)/2;
     return Product(m,middle)*Product(middle+1,n);
   }
}




int main(void)
{
   printf("%d\n", Product(1,5));
}
