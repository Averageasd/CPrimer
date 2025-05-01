#include <stdio.h>

void display(char c, int lines, int width);

int main(){
    int ch;
    int rows, cols;
    int lineBreaker;
    printf("Enter a character and two integers:\n");
    
    // press enter -> program terminates
    while((ch = getchar()) != '\n'){
        printf("char read %c\n", ch);
        if (scanf("%d %d", &rows, &cols) != 2){
            break;
        }
        printf("rows and cols %d %d\n", rows, cols);
        display(ch, rows, cols);

        // read all characters left out by scanf.
        // when newline read, this loop breaks.
        // without this loop, left out new line
        // read by first getchar() causes program to
        // terminate
        while ((lineBreaker = getchar()) != '\n'){}
        printf("Enter another character and two numbers:\n");
        printf("Enter a new line to quit:\n");
    }

    printf("Bye\n");
    return 0;
}

void display(char c, int rows, int cols){
    int i;
    int j;
    for (i = 0; i < rows;i++){
        for (j = 0; j < cols; j++){
            putchar(c);
        }
        putchar('\n');
    }
    
}