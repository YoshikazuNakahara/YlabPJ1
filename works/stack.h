#include <stdio.h>
#include <stdlib.h>
//#define BASESTACKSIZE 10000
#define BASESTACKSIZE 1
#define INDEXSIZE 10000
typedef struct
{
  int* top;
  //int array[STACKSIZE];
  int** array;
  int*(*(index[INDEXSIZE]));
  int* number;
} Stack;

Stack* makeStack(Stack);
int isEmptyStack(Stack*);
int isSubEmptyStack(Stack*);
int isFullStack(Stack*);
int isSubFullStack(Stack*);
void pushStack(Stack*, int);
int popStack(Stack*);
int checkParentheses(FILE*);
void printStack(Stack*);
void destructStack(Stack*);
