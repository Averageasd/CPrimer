#include <stdio.h>

int main(void){

    // use pointer to string literal. we cannot ALTER the characters. 
    // better to use non-const char array
    char * pt = "I am Ng";
    printf("first character of string is %c\n", pt[0]);
    return 0;
}