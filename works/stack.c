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
