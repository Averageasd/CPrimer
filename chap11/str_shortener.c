#include <stdio.h>
#include <string.h>

#define BUFFER_LEN 20
#define SHORTENED_LEN 5

void shorten_str(char[], unsigned int);
int main(void){
    char buffer[BUFFER_LEN];
    printf("enter a string that contains up to %d characters.\n", BUFFER_LEN - 1);
    fgets(buffer, BUFFER_LEN, stdin);
    shorten_str(buffer, SHORTENED_LEN);

    // printf stops at first null character but rest of string is still there
    printf("shortened string %s\n", buffer);
    printf("string beyond %d characters : %s\n", SHORTENED_LEN, (buffer + 6));
    return 0;
}

void shorten_str(char str[], unsigned int shortened_len){
    if (strlen(str) > shortened_len){

        // put a terminated character to signal end of string.
        // example:
        // str = abcdef
        // shortened version is abcd
        str[shortened_len] = '\0';
    }
}


