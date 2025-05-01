#include <stdio.h>

void swap_op(int* u, int* v);
int main(void){
    int u = 5;
    int v = 7;

    printf("value of u before swap %d\n", u);
    printf("value of v before swap %d\n", v);
    // since swap_op accepts pointers
    // we have to pass addresses of u and v
    // to swap_op (pointer stores address of variable)
    swap_op(&u, &v);
    printf("value of u now %d\n", u);
    printf("value of v now %d\n", v);
    return 0;
}

void swap_op(int* u, int* v){
    int tmp;

    // u and v are pointers that point to addresses of 
    // original u and v
    // when we do *u, we retrieve the value stored at the address
    // which stored in u

    // dereference u. assign value stored in u (integer)
    // to tmp
    tmp = *u;

    // assign value stored in v to value stored in u
    *u = *v;
    *v = tmp;
}