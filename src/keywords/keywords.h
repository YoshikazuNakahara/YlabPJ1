#define WORDCOUNT 2
#define COUNT 10000
#define KEYWORDS_MAX_LENGTH 4
//#ifndef KEYWORDS_H //二重でincludeされることを防ぐ
//#define KEYWORDS_H


void parseKeywords(FILE *, int*);
int checkSyntax(int *);
