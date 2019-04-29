#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void makeStack(Stack* sp){
   sp = (Stack*)malloc(sizeof(Stack));
   sp->top = -1;
   sp->array = (int*)malloc(sizeof(int) * BASESTACKSIZE);
   sp->number = 0;
   sp->index[sp->number] = sp->array;
}

void destructStack(Stack* sp){
   while (sp->number > -1) {
	free(sp->array);
        sp->number--;
        sp->array = sp->index[sp->number];
   }
   free(sp);
}

int isSubEmptyStack(Stack* sp){
    return sp->top > -1;
}

int isSubFullStack(Stack* sp){
    return sp->top < BASESTACKSIZE;
}

int isEmptyStack(Stack* sp){
    return isSubEmptyStack(sp) && sp->number < 1;
}

int isFullStack(Stack* sp){
    return isSubFullStack(sp) && sp->number > (INDEXSIZE - 1);
}

void pushStack(Stack* sp,int integer){
    if (!isFullStack(sp)){
	if (!isSubEmptyStack(sp)) {
        	sp->top++;
        	sp->array[sp->top] = integer;
        }
    	else {
   		sp->top = 0;
   		sp->array = (int*)malloc(sizeof(int) * BASESTACKSIZE);
   		sp->number++;
   		sp->index[sp->number] = sp->array;
    	}
     }
      else {
	printf("Stack is Full.\nCannot push stack.\n");
      }
}

int popStack(Stack* sp){
   if (!isEmptyStack(sp)){
       if (!isSubEmptyStack(sp)) {
       	 sp->top--;
       	 return sp->array[sp->top + 1];
       }
       else {
            sp->top = BASESTACKSIZE - 1;
	    sp->number--;
       }
    }
    else {
	printf("Stack is empty.\nCannot pop stack.\n");
	return -1;
    }
}

void printStack(Stack* sp){
    int* array;
    printf("Stack:");
    for (int j = sp->number;j > -1;j--) {
	array = sp->index[sp->number];
    	printf("character:%d", j);
    	for (int i = sp->top;i > -1;i--){
        	printf("%d, ",array[i]);
    	}
    	printf("\n");
    }
}
