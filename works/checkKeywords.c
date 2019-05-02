#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int
checkKeywords (FILE * fp)
{
  char c;
  char leftKeywords[] = { '(', '[', '{', '\0' };
  char rightKeywords[] = { ')', ']', '}', '\0' };

  Stack st;
  Stack *sp;
  sp = &st;
  makeStack (sp);

  for (int i = 0; (c = fgetc (fp)) != EOF; i++)
    {
      int flag = 1;
      int popValue;
      printStack (sp);
      for (int j = 0; rightKeywords[j] != '\0'; j++)
	{
	  if (c == rightKeywords[j])
	    {
	      popValue = popStack (sp);
	      //if (popStack(sp) != j) {
	      if (popValue != j)
		{
		  printf ("debug %d", popValue);
		  return 0;
		}
	      else
		{
		  flag = 0;
		}
	    }
	}
      for (int j = 0; leftKeywords[j] != '\0'; j++)
	{
	  if (leftKeywords[j] == c)
	    {
	      pushStack (sp, j);
	    }
	}
    }
  printf ("End ");
  printStack (sp);
//      destructStack(sp);
  return (isEmptyStack (sp));
}
