#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char AirportCode[4];
typedef struct NodeTag {
                        AirportCode Airport;
                        struct NodeTag *Link;
                } NodeType;
typedef NodeType *NodePointer;

void InsertNewLastNode(char *A, NodeType **L)
{
      NodeType *N, *P;

      N=(NodeType *)malloc(sizeof(NodeType));
      strcpy(N->Airport, A);
      N->Link=NULL;

      if (*L == NULL) {
         *L=N;
      } else {
         P=*L;
         while (P->Link != NULL) P=P->Link;
         P->Link=N;
      }

}


void PrintList(NodeType *L)
{
      NodeType *N;

      printf("(");
      N=L;
      while(N != NULL) {
         printf("%s", N->Airport);
         N=N->Link;
         if (N!=NULL) printf(",");
      }
      printf(")\n");
}


void Reverse(NodeType **L)
{
   NodeType *R, *N, *L1;
   
   L1=*L;
   R=NULL;
   while (L1 != NULL) {
      N=L1;
      L1=L1->Link;
      N->Link=R;
      R=N;
   }
   *L=R;
}



int main(void)
{
      NodeType *A;

      A=NULL;

      InsertNewLastNode("DUS", &A);
      InsertNewLastNode("ORD", &A);
      InsertNewLastNode("SAN", &A);
      PrintList(A);

      Reverse(&A);

      PrintList(A);
}
