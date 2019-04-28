#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

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
