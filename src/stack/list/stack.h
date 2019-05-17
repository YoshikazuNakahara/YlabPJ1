typedef struct _Stack
{
  struct _Stack *next;
  int value;
} Stack;

void makeStack (Stack *);
int isEmptyStack (Stack *);
int isSubEmptyStack (Stack *);
int isFullStack (Stack *);
int isSubFullStack (Stack *);
void pushStack (Stack *, int);
int popStack (Stack *);
void printStack (Stack *);
void sub_printStack (Stack *);
void destructStack (Stack *);
void sub_destructStack (Stack *);
