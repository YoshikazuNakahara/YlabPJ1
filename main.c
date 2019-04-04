#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// check corresponding parentheses
int parenthesesChecker(FILE*);

int main(int argc, char* argv[]){
    FILE* fp;
    char input[256]; // file name
    
    if (argc == 0) {
        printf("Input a file name which is ascii string:\n");
        scanf("%s", &input);
        fp = fopen(input, "r");
    }
    else if (argc == 1) {
        fp = fopen(argv[1], "r");
    }
    else
        printf("Too much program parameters.");
    
    // openning the file failed
    if (fp == NULL) {                             
        printf("Cannot open the file.\n");            
        exit(1);                                    
    }
    
    int flag = parenthesesChecker(fp);
    
    // output whether correspond parentheses or not
    if (flag)
        printf("Not correspond parentheses.\n");
    else
        printf("Correspond parentheses.\n");
    // Close the file.
    fclose(fp);
    
    return 0;
}

int parenthesesChecker(FILE* fp){
    int checker = 0;
    char c;
    for (int i = 0; (c = fgetc( fp )) != EOF;i++)
        if (c == '('){
            checker++;
        }
        else if (c == ')' ){
             checker--;
             if (checker < 0)
                break; 
        } 
        if (c == '['){
            checker += 10;
        }
        else if (c == ']' ){
            checker -= 10;
             if (checker < 0)
                break; 
        }
        if (c == '{'){
            checker += 100;
        }
        else if (c == '}' ){
             checker -= 100;
             if (checker < 0)
                break; 
        } 
    }
    return checker;
}
