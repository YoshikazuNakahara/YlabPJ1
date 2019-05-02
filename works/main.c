#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int checkKeywords (FILE *);

int
main (int argc, char *argv[])
{
  FILE *fp = NULL;
  char input[256];		// file name

  if (argc == 1)
    {
      printf ("Input a file name which is ascii string:\n");
      scanf ("%s", &input);
      fp = fopen (input, "r");
    }
  else if (argc == 2)
    {
      fp = fopen (argv[1], "r");
    }
  else
    printf ("Too much program parameters.");

  // openning the file failed
  if (fp == NULL)
    {
      printf ("Cannot open the file.\n");
      exit (1);
    }

  int flag = checkKeywords (fp);

  // output whether correspond parentheses or not
  if (flag)
    printf ("Correspond parentheses.\n");
  else
    printf ("Not correspond parentheses.\n");
  // Close the file.
  fclose (fp);

  return 0;
}
