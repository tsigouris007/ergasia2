/* This is the file StackTypes.h   */

#define MAXSTACKSIZE 100

typedef float ItemType;
/* char is the type for our first application */
/* float is the type for our second application */

typedef struct{
           int Count;
           ItemType Items[MAXSTACKSIZE];
        } Stack;
