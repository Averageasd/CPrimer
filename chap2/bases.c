#include <stdio.h>

int main(){

    int x = 100;

    printf("dec = %d; octal = %o; hex = %x\n", x, x, x);

    // will display 0 and 0x in output
    printf("dec = %d; octal = %#o; hex = %#x\n", x, x, x);
    return  0;
}