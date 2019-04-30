#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int checkParentheses(FILE* fp){
    char c, c1;
    char leftBrackets[] = {'(', '[', '{', '\0'};
    char rightBrackets[] = {')', ']', '}', '\0'};
    
    Stack st;
    Stack* sp;
    sp = makeStack(st);
    
    for (int i = 0; (c = fgetc( fp )) != EOF;i++){
    	int flag = 1;
	    int d1;
//	    printf("debug %c\n", c);
    	printStack(sp);
	for (int j = 0;rightBrackets[j] != '\0';j++){
	   if (c == rightBrackets[j]) {
		d1 = popStack(sp);
		//if (popStack(sp) != j) {
		if (d1 != j) {
//		    printf("debug %d", d1);
		    return 0;	
	   	}
	   	else {
		flag = 0;
	   	}
	    }
	}
	for (int j = 0;leftBrackets[j] != '\0';j++){
		if (leftBrackets[j] == c) {
 //           printf("leftBrackets %c, integer %d\n", leftBrackets[j], j);
		    pushStack(sp, j);
		}
	}
    }
	printStack(sp);
//	destructStack(sp);
    return (isEmptyStack(sp));
}
