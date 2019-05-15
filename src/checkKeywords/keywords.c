#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"
#include "keywords.h"

int*
analizeKeywords (FILE * fp)
{
  char c;
  Keywords key;
  Keywords* kp = &key;
  //readKeywords(kp);
  //kp->left[WORDCOUNT+1][KEYWORDS_MAX_LENGTH+1] = {"(", "if",};
  kp->left[WORDCOUNT+1][KEYWORDS_MAX_LENGTH+1] = {"(", "[",};
  //kp->right[WORDCOUNT+1][KEYWORDS_MAX_LENGTH+1] = {")", "else", };
  kp->right[WORDCOUNT+1][KEYWORDS_MAX_LENGTH+1] = {")", "]", };
  int ret[WORDCOUNT*2+1];
  char buf[KEYWORDS_MAX_LENGTH+1];
  int j = 0;
  int l = 0;
  int flag = 0;

  for (int i = 0; (c = fgetc (fp)) != EOF; i++)
    {
      buf[j] = c;
      buf[j+1] = '\0';
      for (int k = 0;k < WORDCOUNT; k++) {
        if (strcmp(buf, key.left[k])) {
          ret[l] = k+1;
        }
        else if (strcmp(buf, key.right[k])) {
          ret[l] = (k+1) * -1;
        }
        else {
          continue;
        }
        l++;
        flag = 1;
      }
      if (flag) {
        j = 0;
      }
      else {
        j++;
      }
    }
  return ret;
}
