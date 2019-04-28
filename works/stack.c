#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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
           if (popStack(sp) != 1)
               return 0;
        } 
        else if (c == '['){
           pushStack(sp, 2);
        }
        else if (c == ']' ){
           if (popStack(sp) != 2)
               return 0;
        } 
        else if (c == '{'){
           pushStack(sp, 3);
        }
        else if (c == '}' ){
           if (popStack(sp) != 3)
               return 0;
        } 

    }
    //printStack(sp);
    return (isEmptyStack(sp));
}
