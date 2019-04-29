#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void makeStack(Stack* sp){
   sp->top = -1;
}

int isEmptyStack(Stack* sp){
    return sp->top == -1;
}

int isFullStack(Stack* sp){
    return sp->top == STACKSIZE;
}

void pushStack(Stack* sp,int number){
    if (!isFullStack(sp)){
        sp->top++;
        sp->array[sp->top] = number;
    }
    else
        printf("Stack is full.\n");
}

int popStack(Stack* sp){
   if (!isEmptyStack(sp)){
       sp->top--;
       return sp->array[sp->top + 1];
   }
   else {
       return '\0';
   }
}

void printStack(Stack* sp){
    printf("Stack\ncharacter:");
    for (int i = sp->top;i > -1;i--){
        printf("%d, ",sp->array[i]);
    }
    if (isEmptyStack(sp)){
        printf("Empty");
    }
    printf("\n");
}
