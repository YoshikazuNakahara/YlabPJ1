#include <stdio.h>
#include <stdlib.h>
#define STACKSIZE 10000
typedef struct
{
  int top;
  int array[STACKSIZE];
} Stack;

void makeStack(Stack*);
int isEmptyStack(Stack*);
void pushStack(Stack*, int);
int popStack(Stack*);
int checkParentheses(FILE*);

// chec corresponding parentheses

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
    
    int flag = checkParentheses(fp);
    
    // output whether correspond parentheses or not
    if (flag)
        printf("Correspond parentheses.\n");
    else
        printf("Not correspond parentheses.\n");
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
        printf("index %d, number %d\n", i, sp->array[i]);
    }
    if (sp->top == STACKSIZE){
        printf("Stack Empty.\n");
    }
}

int checkParentheses(FILE* fp){
    char c;
    Stack st;
    Stack* sp = &st;
    
    makeStack(sp);
    
    for (int i = 0; (c = fgetc( fp )) != EOF;i++){
        if (c == '('){
           pushStack(sp, 1);
        }
        else if (c == ')' ){
           popStack(sp);
        } 
        else if (c == '['){
           pushStack(sp, 2);
        }
        else if (c == ']' ){
           popStack(sp);
        } 
        else if (c == '{'){
           pushStack(sp, 3);
        }
        else if (c == '}' ){
           popStack(sp);
        } 

    }
    //printStack(sp);
    return (isEmptyStack(sp));
}
