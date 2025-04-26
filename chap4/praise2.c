#include <stdio.h>
#include <string.h>
#define PRAISE "You are an extraodinary being."

int main(){

    // stores 39 chars plus the null character
    char name[40];

    printf("What's your name? ");
    scanf("%s", name);
    printf("Hello, %s. %s\n", name, PRAISE);
    printf("Your name of %zd letters occupies %zd memory cells.\n", strlen(name), sizeof(name));
    printf("The phrase of praise has %zd letters ", strlen(PRAISE));
    printf("and occupies %zd memory cells.\n", sizeof(PRAISE));
    printf("last character in name is: %c\n", name[39]);
    return 0;
}