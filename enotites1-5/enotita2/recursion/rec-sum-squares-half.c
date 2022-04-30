#include <stdio.h>

int SumSquares(int m, int n) {
   int middle;
   
   if (m==n) {
     return m*m;
   } else {
     middle=(m+n)/2;
     return
        SumSquares(m,middle)+SumSquares(middle+1,n);
   }
}




int main(void)
{
   printf("%d\n", SumSquares(1,10));
}
