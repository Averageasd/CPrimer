#include <stdio.h>
#include <string.h>

// constant vatriable 
#define DENSITY 62.4

int main(){
    float weight, volume;
    int size, letters;

    // array of 40 chars
    char name[40];

    printf("Hi! What's your first name?\n");
    // store string input in variable name
    scanf("%s", name);
    printf("%s, what's your weight in pounds?\n", name);
    // store weight input in variable weight
    scanf("%f", &weight);
    size = sizeof(name);
    letters = strlen(name);
    volume = weight / DENSITY;
    printf("Well, %s, your volumne is %2.2f cubic feet.\n", name, volume);
    printf("Also, your first name has %d letters,\n", letters);
    printf("and we have %d bytes to store it.\n", size);
    return 0;
}