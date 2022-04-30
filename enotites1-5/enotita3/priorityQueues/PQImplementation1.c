/* This is the file PQImplementation.c */

#include <stdio.h>
#include <stdlib.h>
#include "PQInterface1.h"

/* Now we give all the details of the functions */
/* declared in the interface file together with */
/* local private functions.                     */

void Initialize(PriorityQueue *PQ)
{
   PQ->Count=0;
}

int Empty(PriorityQueue *PQ)
{
   return(PQ->Count==0);
}


int Full(PriorityQueue *PQ)
{
   return(PQ->Count==MAXCOUNT);
}

void Insert(PQItem Item, PriorityQueue *PQ)
{
   if (!Full(PQ)) {
      PQ->ItemArray[PQ->Count]=Item;
      PQ->Count++;
   }
}


PQItem Remove(PriorityQueue *PQ)
{
   int i;
   int MaxIndex;
   PQItem MaxItem;

   if (!Empty(PQ)){
      MaxItem=PQ->ItemArray[0];
      MaxIndex=0;
      for (i=1; i<PQ->Count; ++i){
         if (PQ->ItemArray[i] > MaxItem){
            MaxItem=PQ->ItemArray[i];
            MaxIndex=i;
         }
      }
      PQ->Count--;
      PQ->ItemArray[MaxIndex]=PQ->ItemArray[PQ->Count];
      return(MaxItem);
   }
}
