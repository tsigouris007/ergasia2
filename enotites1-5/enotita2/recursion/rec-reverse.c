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

NodeType *Concat(NodeType *L1, NodeType *L2)
{
   NodeType *N;

   if (L1 == NULL) {
      return L2;
   } else {
      N=L1;
      while (N->Link != NULL) N=N->Link;
      N->Link=L2;
      return L1;
   }
}


void Partition(NodeType *L, NodeType **Head, NodeType **Tail)
{
     if (L != NULL) {
         *Tail=L->Link;
         *Head=L;
         (*Head)->Link=NULL;
    }
}


NodeType *Reverse(NodeType *L)
{
     NodeType *Head, *Tail;
     
     if (L==NULL) {
         return NULL;
     } else {
         Partition(L, &Head, &Tail);
         return Concat(Reverse(Tail), Head);
    }
}



int main(void)
{
      NodeType *A, *B;

      A=NULL;

      InsertNewLastNode("DUS", &A);
      InsertNewLastNode("ORD", &A);
      InsertNewLastNode("SAN", &A);
      PrintList(A);

      B=Reverse(A);

      PrintList(B);
}
