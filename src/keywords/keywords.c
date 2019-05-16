#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "keywords.h"
#include "../stack/stack.h"

void
parseKeywords (FILE * fp, int* ret)
{
  char c;
  char left[WORDCOUNT][KEYWORDS_MAX_LENGTH+1] = {"(", "if",};
  char right[WORDCOUNT][KEYWORDS_MAX_LENGTH+1] = {")", "else", };
  char buf[KEYWORDS_MAX_LENGTH+1];
  int j = 0;
  int l = 0;
  int flag = 0;

	printf("input: ");
  for (int i = 0; (c = fgetc (fp)) != EOF; i++)
    {
	printf("%c", c);
      buf[j] = c;
      buf[j+1] = '\0';
      for (int k = 0;k < WORDCOUNT; k++) {
        if (!strcmp(buf, left[k])) {
          ret[l] = k+1;
        }
        else if (!strcmp(buf, right[k])) {
          ret[l] = (k+1) * -1;
        }
        else {
          continue;
        }
        l++;
        flag = 1;
        break;
      }
      if (flag) {
        j = 0;
        flag = 0;
      }
      else {
        j++;
      }
    }
printf("\n");
}

int
checkSyntax (int * array)
{
  Stack st;
  Stack * sp = &st;
  makeStack(sp);

  for (int i = 0;array[i] != 0;i++) {
    printStack(sp);
    if (array[i] > 0) {
      pushStack(sp, array[i]);
    }
    else if (popStack(sp) + array[i] != 0) {
      return 0;
    }
  }
  printStack(sp);
  destructStack(sp);
  return isEmptyStack(sp);
}
