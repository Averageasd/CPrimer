#include <stdio.h>
#define NAME "GIGATHINK, INC."
#define ADDRESS "101 Megabuck Plaza"
#define PLACE "Megapolist, CA 94904"
#define WIDTH 40

void starbar();

int main(){
    starbar();
    printf("%s\n", NAME);
    printf("%s\n", ADDRESS);
    printf("%s\n", PLACE);
    starbar();
    return 0;
}

void starbar(){
    int count;

    for (count = 1; count <= WIDTH; count++){
        putchar('*');
    }
    putchar('\n');
}