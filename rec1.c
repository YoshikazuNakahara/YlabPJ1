#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parentheseschecker(char*, int);
int parenthesesChecker(char*);

int main(void){
    // Your code here!
    // ファイルのオープン
    int flag = 1;
    flag = parenthesesChecker("dl(Ji(l)ll)dd)");
    //flag = parenthesesChecker("(l)");
    if (flag)
        printf("Complete parentheses.");
    else
        printf("Not complete parentheses.");
}
int parenthesesChecker(char* string){
    return parentheseschecker(string, 0);
}
int parentheseschecker(char* string, int count){
    printf("string: %s\n", string);
    if (strlen(string) == 0) {
        if (count > 0)
            return 0;
        else if (count == 0)
            return 1;
        else
            return 0;
    }
    else {
        if (*string == '('){
            count++;
        }
        else if (*string == ')'){
            count--;
        }
        string++;
        return parentheseschecker(string, count);
    }
}
