#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parenthesesChecker(char*);
int parentheseschecker(char*);

int main(void){
    // Your code here!
    // ファイルのオープン
    char buffer[256];
    FILE *fp;
    fp = fopen(stdin, "r");
    
    int flag = 1;
    flag = parenthesesChecker();
    if flag
        printf("Complete parentheses.");
    else
        printf("Not complete parentheses.");
    // ファイルのクローズ
    fclose(fp);
}

int parentheseschecker(char* string){
    if (*string == '('){
        string++;
        int number = strlen(string)+1;
        for (int i = 0;i < number;i++){
            string++;
        }
        if (*string == ')'){
            return 1;
        }
        else
            return 0;
    }
}

int parenthesesChecker(char* string){
    if (*string == '('){
        return parenthesesChecker() and 1;
    }
    else
        
}
