/* This is the file StackInterface.h */
/* #include "StackTypes.h" */

void InitializeStack(Stack *S);
int Empty(Stack *S);
int Full(Stack *S);
void Push(ItemType X, Stack *S);
void Pop(Stack *S, ItemType *X);
