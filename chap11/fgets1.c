#include <stdio.h>
#define STLEN 14

int main(void){
    char words[STLEN];

    // read string with space into words
    // willr read up to STLEN-1 characters
    fgets(words, STLEN, stdin);

    // puts will automatically append a new line 
    puts(words);

    // fputs is a file-oriented version of puts
    // does not automatically append a new line
    fputs(words, stdout);
    return 0;
}