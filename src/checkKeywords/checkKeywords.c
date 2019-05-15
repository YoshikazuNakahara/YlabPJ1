#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "keywords.h"

int
checkKeywords (FILE * fp)
{
  char c;
  //Keywords key;
  //Keywords* kp = &key;
  //makeKeywords(kp);

  Stack st;
  Stack *sp = &st;
  makeStack (sp);

  for (int i = 0; (c = fgetc (fp)) != EOF; i++)
    {
      //int flag = 1;
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
	      /*else
		{
		  flag = 0;
		}*/
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

void readKeywords(Keywords* key) {
}

void checkLeftKeywords(const Keywords key, char c) {
}

void checkRightKeywords(const Keywords key, char c) {
}
