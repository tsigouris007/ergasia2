/* This is the file StackInterface.h */
/* #include "StackTypes.h" */

typedef struct {
           StackNode *ItemList;
        } Stack;

void InitializeStack(Stack *S);
int Empty(Stack *S);
int Full(Stack *S);
void Push(ItemType X, Stack *S);
void Pop(Stack *S, ItemType *X);
