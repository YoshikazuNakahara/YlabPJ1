#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int checkParentheses(FILE* fp){
    char c, c1;
    Stack st;
    Stack* sp = &st;
    char leftBrackets[] = {'(', '[', '{', '\0'};
    char rightBrackets[] = {')', ']', '}', '\0'};
    
    makeStack(sp);
    
    for (int i = 0; (c = fgetc( fp )) != EOF;i++){
    	int flag = 1;
	printf("debug %c\n", c);
	printStack(sp);
	for (int j = 0;rightBrackets[j] != '\0';j++){
	   if (c == rightBrackets[j]) {
		if (popStack(sp) != j) {
		return 0;	
	   	}
	   	else {
		flag = 0;
	   	}
	    }
	}
	for (int j = 0;leftBrackets[j] != '\0';j++){
		if (leftBrackets[j] == c) {
		pushStack(sp, j);
		}
	}
    }
	printStack(sp);
    return (isEmptyStack(sp));
}
