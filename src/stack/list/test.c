#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int
main (void)
{
  Stack st;
  Stack *sp = &st;

  makeStack (sp);
  printStack (sp);
  if (isEmptyStack (sp))
    printf ("stack is empty.\n");
  pushStack (sp, 1);
  printStack (sp);
  if (isEmptyStack (sp))
    printf ("stack is empty.\n");
  if (1 == popStack (sp))
    printf ("Pop success.\n");
  if (isEmptyStack (sp))
    printf ("stack is empty.\n");
  printStack (sp);
  popStack (sp);
  if (isEmptyStack (sp))
    printf ("stack is empty.\n");

  pushStack (sp, 1);
  printStack (sp);
  if (isEmptyStack (sp))
    printf ("stack is empty.\n");

  pushStack (sp, 2);
  printStack (sp);
  if (isEmptyStack (sp))
    printf ("stack is empty.\n");

  pushStack (sp, 3);
  printStack (sp);
  if (isEmptyStack (sp))
    printf ("stack is empty.\n");

    destructStack (sp);

  return 0;
}
