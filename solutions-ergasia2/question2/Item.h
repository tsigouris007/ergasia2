#define NULLitem -1 /* NULLitem is a constant */

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define eq(A, B) (!less(A, B) && !less(B, A))

Item ITEMrand(void);
 int ITEMscan(Item *);
void ITEMshow(Item);
 int isNumber(char number[]);