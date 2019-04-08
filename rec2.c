#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkBrackets(char*);

int main(void){
    // Your code here!
    // ファイルのオープン
    int flag = 1;
    flag = checkBrackets("(())");
    if (flag)
        printf("Complete parentheses.");
    else
        printf("Not complete parentheses.");
}

int checkBrackets(char* string){
    char sub_string[256];
    printf("string: %s\n", string);
    int length = strlen(string);
    if (length == 0) {
            return 1;
    }
    else {
        int left, right;
        int i;
        int flag = 0;
        for (left = 0;left < length;i++){
           if (string[left] == '(') {
               break;
           }
           else if (string[left] == ')'){
               return 0;
           }
        }
        for (right = length - 1;right > - 1;right--){
           if (string[right] == ')') {
               break;
           }
           else if (string[right] == '('){
               return 0;
           }
        }
        for (i = left + 1;i < right;i++){
            sub_string[i] = string[i];
            printf("sub_string: %c, index %d\n", sub_string[i], i);
        }
        printf("sub_string: %s\n", sub_string);
        //return checkBrackets(sub_string);
        return 1;
    }
}
