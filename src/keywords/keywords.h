#define WORDCOUNT 2
#define KEYWORDS_MAX_LENGTH 4
typedef struct {
  char left[WORDCOUNT+1][KEYWORDS_MAX_LENGTH+1];
  char right[WORDCOUNT+1][KEYWORDS_MAX_LENGTH+1];
} Keywords;

int* analizeKeywords(FILE *);
