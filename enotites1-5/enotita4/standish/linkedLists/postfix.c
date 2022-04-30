#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include "StackInterface1.h"

Stack EvalStack;
char PostfixString[20];

void InterpretPostfix(void)
{
  float LeftOperand, RightOperand, Result;
  int i;
  char c;
  char s[]="x";


  InitializeStack(&EvalStack);


  for (i=0; i<strlen(PostfixString); ++i){
     s[0]=c=PostfixString[i];
     if (isdigit(c)){
       Push((float)(atof(s)), &EvalStack);
     } else if (c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
          Pop(&EvalStack, &RightOperand);
          Pop(&EvalStack, &LeftOperand);

          switch (c) {
             case '+': Push(LeftOperand+RightOperand, &EvalStack);
                       break;
             case '-': Push(LeftOperand-RightOperand, &EvalStack);
                       break;
             case '*': Push(LeftOperand*RightOperand, &EvalStack);
                       break;
             case '/': Push(LeftOperand/RightOperand, &EvalStack);
                       break;
             case '^': Push(pow(LeftOperand, RightOperand), &EvalStack);
                       break;
             default: break;
          }
      }
  }

  Pop(&EvalStack, &Result);
  printf("Value of postfix expression = %f\n", Result);
}

int main(void) {

     printf("Give input postfix string without blanks:");
     scanf("%s", PostfixString);
     InterpretPostfix();
}
