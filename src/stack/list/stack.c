#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void
makeStack (Stack * sp)
{
  sp->next = NULL;
  sp->value = 0;
}

void
destructStack (Stack * sp)
{
  if (sp == NULL) {
    printf("Stack does not exist.\n");
  }
  else {
    sub_destructStack(sp);
  }
}
void
sub_destructStack (Stack * sp)
{
  if (sp->next == NULL) {
    free(sp);
  }
  else {
    sub_destructStack(sp->next);
  }
  return;
}

int
isEmptyStack (Stack * sp)
{
  if (sp->next == NULL) {
    return 1;
  }
  else {
    return 0;
  }
}

void
pushStack (Stack * sp, int integer)
{
  Stack * sp1 = sp->next;
  sp->next = (Stack *)malloc(sizeof(Stack));
  sp->next->value = integer;
  sp->next->next = sp1;
}

int
popStack (Stack * sp)
{
  int ret;
  Stack * sp1;
  if (isEmptyStack (sp))
    {
      return -1;
    }
  else
    {
      ret = sp->next->value;
      sp1 = sp->next;
      sp->next = sp1->next;
      free(sp1);
    }
  return ret;
}

void
printStack (Stack * sp)
{
  if (sp == NULL) {
    printf("Stack does not exist.\n");
  }
  else {
    sub_printStack (sp);
  }
}

void
sub_printStack (Stack * sp)
{
  if (sp->next == NULL) {
    printf("Stack\n");
  }
  else {
    printf("value %d\n", sp->next->value);
    sub_printStack(sp->next);
  }
  return;
}
