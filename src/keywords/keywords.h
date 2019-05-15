void readKeywords(const Keywords, FILE*);
int checkLeftKeywords(const Keywords, const char);
int checkRightKeywords(const Keywords, const char);
typedef struct
{
char **left;
char **right;
} Keywords;
