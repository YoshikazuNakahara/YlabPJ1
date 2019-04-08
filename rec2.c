#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkBrackets(char*);

int main(void){
    // Your code here!
    // ファイルのオープン
    int flag = 1;
    flag = checkBrackets("*((dd()dd))**");
    if (flag)
        printf("Complete parentheses.");
    else
        printf("Not complete parentheses.");
}

int checkBrackets(char* string){
    char sub_string[256];
    printf("string: %s\n", string);
    int length = strlen(string);
    printf("length: %d\n", length);
    if (length == 0) {
            return 1;
    }
    else {
        int left, right;
        int i;
        int flag = 0;
        for (left = 0;left < length;left++){
                printf("left: %c\n", string[left]);
           if (string[left] == '(') {
               break;
           }
           else if (string[left] == ')'){
               return 0;
           }
        }
        for (right = length - 1;right > - 1;right--){
                printf("right: %c\n", string[right]);
           if (string[right] == ')') {
               break;
           }
           else if (string[right] == '('){
               return 0;
           }
        }
        int sub_length = right - left - 1;
        printf("sub_length: %d\n", sub_length);
        if (sub_length > 0) {
            for (i = 0;i < sub_length;i++){
                sub_string[i] = string[left+i+1];
            }
            sub_string[i] = '\0';
        }
        else
            *sub_string = '\0';
        printf("sub_string: %s\n", sub_string);
        return checkBrackets(sub_string);
    }
}
