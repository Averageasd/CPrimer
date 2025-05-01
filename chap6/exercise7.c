#include <stdio.h>
#include <string.h>

#define SIZE 10

int main(){
    char str[SIZE];
    char c;
    int i;
    int strLen;
    for (i = 0; i < SIZE; i++){
        scanf("%c", &c);
        str[i] = c;
    }
    strLen = strlen(str);
    for (i = strLen - 1; i>=0; i--){
        printf("%c", str[i]);
    }
    printf("\n");
    return 0;
}