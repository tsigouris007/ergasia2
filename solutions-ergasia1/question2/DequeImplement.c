#include <stdio.h>
#include <stdlib.h>
#include "DequeInterface.h"



void Create(Deque q){
    q->FRONT=NULL;
    q->REAR=NULL; 
    q->sum=0; 

}
int SizeOf(Deque q){
    return q->sum;

}
int IsEmpty(Deque q){
    return (q->FRONT==NULL);

}
void Enqueue(Deque q, itype c){
    nodeDQ *TEMPORARY;
    TEMPORARY=(nodeDQ *) malloc(sizeof(nodeDQ));
    if (TEMPORARY==NULL) printf("Failed allocation of memory");
    else{
        TEMPORARY->ITEM=c;
        TEMPORARY->LINK=NULL;
        if(!IsEmpty(q)){
            q->REAR->LINK=TEMPORARY;
            q->REAR=TEMPORARY;
        }
        else{
            q->FRONT=TEMPORARY;
            q->REAR=TEMPORARY;
            
        }
        q->sum++;
    }
}
void Push(Deque q, itype c){
    nodeDQ *TEMPORARY;

    TEMPORARY=(nodeDQ *)malloc(sizeof(nodeDQ));

    if (TEMPORARY==NULL) printf("Failed allocation of memory");
    else{
        TEMPORARY->ITEM=c; 
        TEMPORARY->LINK=q->FRONT;
        if(!IsEmpty(q)) q->FRONT=TEMPORARY;
        else{
            q->FRONT=TEMPORARY;
            q->REAR=TEMPORARY;

        }
        q->sum++;

    }  

}
void Pop(Deque q, itype *c){
        nodeDQ *TEMPORARY;
        if (q->FRONT!=NULL){
            TEMPORARY=q->FRONT;
            q->FRONT=q->FRONT->LINK;
            *c=TEMPORARY->ITEM;
            free(TEMPORARY);
            q->sum--;
            if(q->FRONT==NULL)q->REAR=NULL;


        }
        else printf("Pop can not be executed because the queue is empty");


}
void Dequeue(Deque q, itype *c){
    nodeDQ *TEMPORARY;
    if(q->FRONT!=NULL){
        if(q->FRONT!=q->REAR){
        TEMPORARY=q->REAR;
        q->REAR=q->FRONT;
            while(q->REAR->LINK!=TEMPORARY){
            q->REAR=q->REAR->LINK;
            }
        }
        else{
        TEMPORARY=q->REAR;
        q->FRONT=NULL;
        q->REAR=NULL;
    }
    q->REAR->LINK=NULL;
    *c=TEMPORARY->ITEM;
    free(TEMPORARY);
    q->sum--;

    }
    else printf("Dequeue can not be executed because the queue is empty");


}
void Print(Deque q){
    nodeDQ *TEMPORARY;
    TEMPORARY=q->FRONT;
    while(TEMPORARY!=NULL){
        printf("%d, ",TEMPORARY->ITEM);
        TEMPORARY=TEMPORARY->LINK;
    }
}