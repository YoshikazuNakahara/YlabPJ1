#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void makeStack(Stack* sp){
   sp->top = (int*)malloc(sizeof(int));
   *(sp->top) = -1;
   sp->number = (int*)malloc(sizeof(int));
   *(sp->number) = 0;
   sp->array = (int**)malloc(sizeof(int*));
   *(sp->array) = (int*)malloc(sizeof(int) * BASESTACKSIZE);
   *sp->index = sp->array;
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
    return *(sp->top) > (BASESTACKSIZE - 2);
}

int isEmptyStack(Stack* sp){
    return isSubEmptyStack(sp) && *(sp->number) < 1;
}

int isFullStack(Stack* sp){
    return isSubFullStack(sp) && *(sp->number) > (INDEXSIZE - 2);
}

void pushStack(Stack* sp,int integer){
    if (isFullStack(sp)){
	printf("Stack is Full.\nCannot push stack.\n");
    }
  else if (isSubFullStack(sp)) {
	*(sp->top) = 0;
	*(sp->array) = (int*)malloc(sizeof(int) * BASESTACKSIZE);
	*(sp->number) = *(sp->number) + 1;
	*(*(sp->index) + *(sp->number)) = *(sp->array);
	*(*(sp->array) + *(sp->top)) = integer;
//	printf("Over PUSH! top:%d number:%d value:%d array:%d\n", *(sp->top), *(sp->number), integer, *(*(sp->array) + *(sp->top)));
    } 
  else {
	*(*(sp->array) + *(sp->top)) = integer;
 	*(sp->top) = *(sp->top) + 1;
//	printf("PUSH! top:%d number:%d value:%d array:%d\n", *(sp->top), *(sp->number), integer, *(*(sp->array) + *(sp->top)));
  }
}

int popStack(Stack* sp){
   int ret;
   if (isEmptyStack(sp)){
	printf("Stack is empty.\nCannot pop stack.\n");
	return -1;
    }
    else if (isSubEmptyStack(sp)) {
	ret = *(*(sp->array) + *(sp->top));
	*(sp->top) = BASESTACKSIZE - 2;
	*(sp->number) = *(sp->number) - 1;
	sp->array = *(sp->index) + *(sp->number);
//	printf("Under POP! top:%d, number:%d, value:%d\n", *(sp->top), *(sp->number), *(*(sp->array) + *(sp->top)));
     }
     else {
	ret = *(*(sp->array) + *(sp->top));
	*(sp->top) = *(sp->top) - 1;
//	printf("POP! top:%d, number:%d, value:%d\n", *(sp->top), *(sp->number), *(*(sp->array) + *(sp->top)));
    }
//    printf("return value %d\n", ret);
    return ret;
}

void printStack(Stack* sp){
    int* array;
    for (int j = *(sp->number);j > -1;j--) {
	array = *(*(sp->index) + j);
    	printf("stack number:%d", j);
    	for (int i = *(sp->top);i > -1;i--){
        	printf("top:%d value:%d", i ,array[i]);
    	}
    	printf("\n");
    }
}
