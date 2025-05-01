#include <stdio.h>

void mikado(int pooh, int bah);

int main(void){
    int pooh = 2, bah = 5;

    printf("In main(), value stored in pooh : %d and address of pooh : %p\n", pooh, &pooh);
    printf("In main(), value stored in bah : %d and address of bah : %p\n", bah, &bah);
    mikado(pooh, bah);
    return 0;
}

// copies of pooh and bar are passed to mikado. these copies have different addresses
void mikado(int pooh, int bah){
    printf("In mikado(), value stored in pooh : %d and address of pooh : %p\n", pooh, &pooh);
    printf("In mikado(), value stored in bah : %d and address of bah : %p\n", bah, &bah);
}