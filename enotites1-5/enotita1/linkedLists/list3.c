#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* The code is from Chapter 2 of the book "Data Structures, Algorithms and Software Principles in C" */
typedef char AirportCode[4];
typedef struct NodeTag {
                        AirportCode Airport;
                        struct NodeTag *Link;
                } NodeType;
typedef NodeType *NodePointer;


/* function prototypes */
void InsertNewSecondNode(NodeType **);
void InsertNewLastNode(char *, NodeType **);
void DeleteLastNode(NodeType **);
NodeType *ListSearch(char *, NodeType *);
void PrintList(NodeType *);



int main(void)
{
      NodeType *L;

      L=NULL;
      
      PrintList(L);
      InsertNewLastNode("DUS", &L);
      InsertNewLastNode("ORD", &L);
      InsertNewLastNode("SAN", &L);
      PrintList(L);

      InsertNewSecondNode(&L);

      PrintList(L);

      DeleteLastNode(&L);
      PrintList(L);

      if (ListSearch("DUS",L) != NULL) {
        printf("DUS is an element of the list\n");
      }
}

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


void DeleteLastNode(NodeType **L)
{
      NodeType *PreviousNode, *CurrentNode;

      if (*L != NULL) {
         if ((*L)->Link == NULL){
            free(*L);
            *L=NULL;
         } else {
            PreviousNode=*L;
            CurrentNode=(*L)->Link;
            while (CurrentNode->Link != NULL){
               PreviousNode=CurrentNode;
               CurrentNode=CurrentNode->Link;
            }
            PreviousNode->Link=NULL;
            free(CurrentNode);
         }
      }
}


void InsertNewSecondNode (NodeType **L)
{
      NodeType *N;
      N=(NodeType *)malloc(sizeof(NodeType));
      strcpy(N->Airport,"BRU");
      N->Link=(*L)->Link;
      (*L)->Link=N;
}



NodeType *ListSearch(char *A, NodeType *L)
{
      NodeType *N;

      N=L;
      while (N != NULL){
        if (strcmp(N->Airport,A)==0){
           return N;
        } else {
           N=N->Link;
        }
      }
      return N;
}
