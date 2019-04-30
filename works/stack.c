#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* makeStack(Stack st){
   Stack* sp = &st;
   sp->top = (int*)malloc(sizeof(int));
   *(sp->top) = -1;
   sp->number = (int*)malloc(sizeof(int));
   *(sp->number) = 0;
   sp->array = (int**)malloc(sizeof(int*));
   *(sp->array) = (int*)malloc(sizeof(int) * BASESTACKSIZE);
   *sp->index = sp->array;
   return sp;
}

void destructStack(Stack* sp){
   while (*(sp->number) > -1) {
	free(*(sp->array));
        *(sp->number)--;
        *(sp->array) = *(*(sp->index) + *(sp->number));
   }
   free(sp);
}

int isSubEmptyStack(Stack* sp){
    return *(sp->top) < 0;
}

int isSubFullStack(Stack* sp){
    return *(sp->top) > (BASESTACKSIZE - 1);
}

int isEmptyStack(Stack* sp){
    return isSubEmptyStack(sp) && *(sp->number) < 1;
}

int isFullStack(Stack* sp){
    return isSubFullStack(sp) && *(sp->number) > (INDEXSIZE - 1);
}

void pushStack(Stack* sp,int integer){
    if (!isFullStack(sp)){
	if (!isSubFullStack(sp)) {
        	*(*(sp->array) + *(sp->top)) = integer;
            //printf("PUSH! top:%d, value:%d array: %d\n", *(sp->top), integer, *(*(sp->array) + *(sp->top)));
        	*(sp->top) = *(sp->top) + 1;
        }
    	else {
        printf("Substack empty.\n");
   		*(sp->top) = 0;
   		*(sp->array) = (int*)malloc(sizeof(int) * BASESTACKSIZE);
   		*(sp->number) = *(sp->number) + 1;
   		*(*(sp->index) + *(sp->number)) = *(sp->array);
    	}
     }
      else {
	printf("Stack is Full.\nCannot push stack.\n");
      }
}

int popStack(Stack* sp){
   if (!isEmptyStack(sp)){
       if (!isSubEmptyStack(sp)) {
	printf("debug\n");
       	 *(sp->top) = *(sp->top) - 1;
            printf("POP! top:%d, value:%d\n", *(sp->top), *(*(sp->array) + *(sp->top)));
       	 return *(*(sp->array) + *(sp->top) + 1);
       }
       else {
	printf("DEBUG\n");
            *(sp->top) = BASESTACKSIZE - 1;
       	 *(sp->number) = *(sp->number) - 1;
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
    for (int j = *(sp->number);j > -1;j--) {
	array = *(*(sp->index) + *(sp->number));
    	printf("character:%d", j);
    	for (int i = *(sp->top);i > -1;i--){
        	printf("%d, ",array[i]);
    	}
    	printf("\n");
    }
}
