/* This code is from Chapter 4 of the book "Algorithms in C" by Robert Sedgewick. */

typedef struct queue *Q;
void QUEUEdump(Q);
   Q QUEUEinit(int maxN);
 int QUEUEempty(Q);
void QUEUEput(Q, Item);
Item QUEUEget(Q);
