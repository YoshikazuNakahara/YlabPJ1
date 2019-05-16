#include <stdio.h>
#include <stdlib.h>
#include "keywords.h"

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
  int array[10000];
  for (int i = 0;i < COUNT;i++){
    array[i] = 0;
  }
  parseKeywords(fp, array);

  printf("array: ");
  for (int i = 0;array[i] != 0;i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
  if (!checkSyntax(array))
	printf("Correct syntax.");
  else
	printf("Not correct syntax.");
  return 0;
}
