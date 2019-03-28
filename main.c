#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int parenthesesChecker(char*);

int main(void){
    // Your code here!
    // ファイルのオープン
    char buffer[256];t
    char* string;
    FILE *fp;
    char input[256];
    
    printf("input string:");
    scanf(&s, &input);
    fp = fopen(input, "r");
    if (fp == NULL) {                             // オープンに失敗した場合
        printf("Cannot open the file.¥n");            // エラーメッセージを出して
        exit(1);                                    // 異常終了
    }
    
    for (int i = 0; (buffer[i] = fgetc( fp )) != EOF;i++);
    
    int flag = parenthesesChecker(buffer);
    if (flag)
        printf("Not correspond parentheses.");
    else
        printf("Correspond parentheses.");
    // ファイルのクローズ
    //fclose(fp);
    
    return 0;
}

int parenthesesChecker(char* string){
    int checker = 0;
    for (int i = 0;i < strlen(string);i++){
        if (string[i] == '('){
            checker++;
        }
        else if (string[i] == ')' ){
                    checker--;
                if (checker < 0)
                    break; 
        } 
    }
    return checker;
}
