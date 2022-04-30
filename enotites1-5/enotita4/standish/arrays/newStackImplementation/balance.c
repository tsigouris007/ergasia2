#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "StackTypes.h" 
#include "StackInterface.h"

char *InputExpression;

int Match(char c, char d)
{
   switch (c){
       case '('   : return d==')';
          break;
       case '['   : return d==']';
          break;
       case '{'   : return d=='}';
          break;
       default    : return(0);
          break;
   }
}


void ParenMatch(void)
{
    int  n, i=0;
    char c, d;
    Stack ParenStack;

    n=strlen(InputExpression);
    while (i < n){
       d=InputExpression[i];
       if ( d=='(' || d=='[' || d=='{' ){
          Push(d, &ParenStack);
       } else if ( d==')' || d==']' || d=='}' ){
          if (Empty(&ParenStack)){
             printf("More right parentheses than left parentheses\n");
             return;
          } else {
             Pop(&ParenStack, &c);
             if (!Match(c,d)){
                printf("Mismatched Parentheses: %c and %c\n", c, d);
                return;
             }
          }
       }
       ++i;
    }
    if (Empty(&ParenStack)){
       printf("Parentheses are balanced properly\n");
    } else {
       printf("More left parentheses than right parentheses\n");
    }
}


int main(void)
{
     InputExpression=(char *)malloc(100);
     printf("Give Input Expression without blanks:");
     scanf("%s", InputExpression);
     ParenMatch();
}
