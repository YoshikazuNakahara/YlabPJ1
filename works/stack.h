#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 10000
typedef struct
{
  int top;
  int array[STACKSIZE];
} Stack;

void makeStack(Stack*);
int isEmptyStack(Stack*);
void pushStack(Stack*, int);
int popStack(Stack*);
int checkParentheses(FILE*);
