#include "DequeTypes.h"

typedef struct tDeque *Deque;

void Create(Deque);
int SizeOf(Deque);
int IsEmpty(Deque);
void Enqueue(Deque, itype);
void Push(Deque, itype);
void Pop(Deque, itype *);
void Dequeue(Deque, itype *);
void Print(Deque);

        