//#include <stdio.h>
//#include <stdlib.h>
#if defined(TEST)
	#define BASESTACKSIZE 1
	#define INDEXSIZE 2
#else
	#define BASESTACKSIZE 10000
	#define INDEXSIZE 10000
#endif
typedef struct
{
  int *top;
  //int array[STACKSIZE];
  int **array;
  int *(*(index[INDEXSIZE]));
  int *number;
} Stack;

void makeStack (Stack *);
//Stack* makeStack(Stack);
int isEmptyStack (Stack *);
int isSubEmptyStack (Stack *);
int isFullStack (Stack *);
int isSubFullStack (Stack *);
void pushStack (Stack *, int);
int popStack (Stack *);
void printStack (Stack *);
void destructStack (Stack *);
