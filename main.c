#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// check corresponding parentheses
void bracketsCheck(FILE*);

int main(int argc, char* argv[]){
    FILE* fp;
    char input[256]; // file name
    
    if (argc == 1) {
        printf("Input a file name which is ascii string:\n");
        scanf("%s", &input);
        fp = fopen(input, "r");
    }
    else if (argc == 2) {
        fp = fopen(argv[1], "r");
    }
    else
        printf("Too much program parameters.");
    
    // openning the file failed
    if (fp == NULL) {                             
        printf("Cannot open the file.\n");            
        exit(1);                                    
    }
    
    bracketsCheck(fp);
    
    // Close the file.
    fclose(fp);
    
    return 0;
}

void bracketsCheck(FILE* fp){
    int checker = 0;
    int checker1 = 0;
    int checker2 = 0;
    int checker3 = 0;
    char c;
    for (int i = 0; (c = fgetc( fp )) != EOF;i++) {
        if (c == '('){
            checker1++;
        }
        else if (c == ')' ){
             checker1--;
             if (checker1 < 0)
                break; 
        } 
        else if (c == '['){
            checker2++;
        }
        else if (c == ']' ){
            checker2--;
             if (checker2 < 0)
                break; 
        }
        else if (c == '{'){
            checker3++;
        }
        else if (c == '}' ){
             checker3--;
             if (checker3 < 0)
                break; 
        } 
    }
    if (checker1 == 0 && checker2 == 0 && checker3 == 0)
        printf("Correspond all brackets.\n");
    else if (checker1 == 0 && checker2 != 0 && checker3 != 0)
        printf("correspond parentheses.\n");
    else if (checker1 == 0 && checker2 == 0 && checker3 != 0)
        printf("correspond parentheses and square brackets.\n");
    else if (checker1 == 0 && checker2 != 0 && checker3 == 0)
        printf("correspond parentheses and curly brackets.\n");
    else if (checker1 != 0 && checker2 == 0 && checker3 != 0)
        printf("correspond square brackets.\n");
    else if (checker1 != 0 && checker2 == 0 && checker3 == 0)
        printf("correspond curly brackets and square brackets.\n");
    else if (checker1 != 0 && checker2 == 0 && checker3 == 0)
        printf("Not correspond brackets.\n");
    else
        printf("correspond curly brackets.\n");
}
