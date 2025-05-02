#include <stdio.h>

#define STRLEN 15

int main(void){
    char buffer[STRLEN];

   
    do{
        puts("Enter strings (empty line to quit): ");
        fgets(buffer, STRLEN, stdin);
        printf("You entered %s", buffer);
        
    }while (buffer[0]!='\n');
    
    printf("Program ends here.\n");
    return 0;
}