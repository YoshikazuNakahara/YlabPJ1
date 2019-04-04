#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// check corresponding parentheses
int parenthesesChecker(char*);

int main(void){
    char buffer[256]; // a string in the file 
    char* string;
    FILE *fp;
    char input[256]; // file name
    
    printf("Input a file name which is ascii string and length of 256:\n");
    scanf("%s", &input);
    fp = fopen(input, "r");
    
    // openning the file failed
    if (fp == NULL) {                             
        printf("Cannot open the file.\n");            
        exit(1);                                    
    }
    
    // input string in the file into a string buffer.
    for (int i = 0; (buffer[i] = fgetc( fp )) != EOF && strlen(buffer) < 257;i++);
    // string in the file > 256
    if (strlen(buffer) > 256){
        printf("String in the file is longer than 256.\n");
        exit(1);
    }
    
    int flag = parenthesesChecker(buffer);
    
    // output whether correspond parentheses or not
    if (flag)
        printf("Not correspond parentheses.\n");
    else
        printf("Correspond parentheses.\n");
    // Close the file.
    fclose(fp);
    
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
