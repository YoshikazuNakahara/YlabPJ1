#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 10000
typedef struct
{
  int top;
  char array[STACKSIZE];
} Stack;

void makeStack(Stack*);
int isEmptyStack(Stack*);
void pushStack(Stack*, int);
int popStack(Stack*);
int checkParentheses(FILE*);
void printStack(Stack*);
