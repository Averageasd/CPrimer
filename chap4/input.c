#include <stdio.h>
int main(){
    int age;
    float assets;

    // 29 characters + null terminator
    char pet[30];

    printf("Enter your age, assets, and favorite pet.\n");

    // skip whitespaces, match conversion specifications to fields
    scanf("%d %f", &age, &assets);

    // dont use & for pet. it is already a pointer
    scanf("%s", pet);
    printf("%d $%.2f %s\n", age, assets, pet);
}