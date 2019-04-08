#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 10000
typedef struct
{
  int top;
  char array[STACKSIZE];
} Stack;

void makeStack(Stack*);
int isEmptyStack(Stack*);
void pushStack(Stack*, int);
int popStack(Stack*);
int checkBrackets(FILE*);
void printStack(Stack*);
int checkLeftBrackets(Stack*, char);
int checkRightBrackets(Stack*, char);
int matchBrackets(char , char );


int main(int argc, char* argv[]){
    FILE* fp = NULL;
    char input[256]; // file name
    
    if (argc == 1) {
        printf("Input a file name which is ascii string:\n");
        scanf("%s", &input);
        fp = fopen(input, "r");
    }
    else if (argc == 2) {
        fp = fopen(argv[1], "r");
    }
    else
        printf("Too much program parameters.");
    
    // openning the file failed
    if (fp == NULL) {                             
        printf("Cannot open the file.\n");            
        exit(1);                                    
    }
    
    int flag = checkBrackets(fp);
    
    // output whether correspond brackets or not
    if (flag)
        printf("Correspond brackets.\n");
    else
        printf("Not correspond brackets.\n");
    // Close the file.
    fclose(fp);
    
    return 0;
}

void makeStack(Stack* sp){
   sp->top = STACKSIZE;
}

int isEmptyStack(Stack* sp){
    return sp->top == STACKSIZE;
}

void pushStack(Stack* sp,int number){
    if (sp->top > -1){
        sp->top--;
        sp->array[sp->top] = number;
    }
    else
        printf("Stack is full.\n");
}

int popStack(Stack* sp){
   if (sp->top > 0) {
       sp->top++;
       return sp->array[sp->top - 1];
   }
   else {
       return -1;
   }
}

void printStack(Stack* sp){
    printf("Stack\n");
    printf("Stack top %d\n", sp->top);
    for (int i = (STACKSIZE - 1);i > sp->top;i--){
        printf("index %d, bracket %c\n", i, sp->array[i]);
    }
    if (sp->top == STACKSIZE){
        printf("Stack Empty.\n");
    }
}

int checkBrackets(FILE* fp){
    char c;
    Stack st;
    Stack* sp = &st;
    
    makeStack(sp);
    for (int i = 0; (c = fgetc( fp )) != EOF;i++){
        checkLeftBrackets(sp, c);
        checkRightBrackets(sp, c); 
    }
    printStack(sp);
    return (isEmptyStack(sp));
}


int matchBrackets(char bracket1, char bracket2){
    if (bracket1 == '(' && bracket2 == ')') {
        return 1;
    }
    else if (bracket1 == '[' && bracket2 == ']') {
        return 1;
    }
    else if (bracket1 == '{' && bracket2 == '}') {
        return 1;
    }
    else if (bracket1 == '<' && bracket2 == '>') {
        return 1;
    }
    else
        return 0;
}
        
int checkLeftBrackets(Stack* sp, char fileChar){
        if (fileChar == '(' || fileChar == '[' || fileChar == '{' || fileChar == '<'){
           pushStack(sp, fileChar);
           printStack(sp);
        }
}

int checkRightBrackets(Stack* sp, char fileChar){
        if (fileChar == ')' || fileChar == ']' || fileChar == '}' || fileChar == '>'){
           if (matchBrackets(popStack(sp), fileChar)) {
              printStack(sp);
              return 0;
           }
        }
}
