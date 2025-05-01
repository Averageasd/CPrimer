#include <stdio.h>
#include <stdlib.h>

int main(){
    int ch;
    FILE* fp;
    char fname[50];

    printf("Enter the name of the file: ");
    // store string into fname
    scanf("%s", fname);

    // open the file
    fp = fopen(fname, "r");

    if (fp == NULL){
        printf("Failed to open file. Bye\n");
        exit(1);
    }

    // reading file till EOF
    while ((ch = getc(fp)) != EOF){
        // print each character of file to screen
        putchar(ch);
    }
    fclose(fp);
    return 0;
}