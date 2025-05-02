#include <stdio.h>

int main(void){

    int zippo[4][2] = {
        {19, 2},
        {3, 4},
        {5, 6},
        {7, 8}
    };

    // zippo <-> zippo[0]. zippo points to first 1d array. zippo[0] points to first element in
    // first 1d array. since zippo points to first 1d array and also looks at the first element, 
    // zippo and zippo[0] point to the same memory block and thus have same numerical values. 

    // &zippo[0] <-> &zippo[0][0]
    // zippo[0] points to the first element in the first 1d array. In short, it has the size of int
    // since it points to an integer. so when we do &zippo[0], we actually ask for the address of first
    // int in the first 1d array zippo[0] points to which is effectively &zippo[0][0]

    // *(zippo) <-> zippo <-> zippo[0] <-> &zippo[0][0]
    // zippo holds the address of first 1d array element, which is technically the address of the
    // first int in the first 1d array element. when we dereference it, we get the address of the 
    // first 1d array, which is the equivalent address of the first element. dereference it again,
    // we will get the value of the first element in the first 1d array.
    printf("pointer to first element in array: zippo = %p, zippo[0] = %p\n", zippo, zippo[0]);
    printf("address of first element in the first 1d array %p\n", &zippo[0][0]);
    printf("deferencing pointer zippo : %p\n", *(zippo));
    printf("address of zippo[0]: &zippo[0] is %p\n", &(zippo[0]));
    printf("deferencing pointer zippo[0] : %d\n", *(zippo[0]));
    printf("value of *(zippo): %p\n", *(zippo));
    printf("value of *(*zippo) and *(zippo[0]) : %d and %d\n", *(*zippo), *(zippo[0]));


    // since zippo points to 1d array. when we increment it by 1, it will point to the next 1d array.
    // zippo + n <-> zippo[n]

    // &(*(zippo + 1)) <-> &zippo[1]
    // since *(zippo + 1) will give you the address of 2nd 1d array, when you use ambersand,
    // it is equivalent to &(zippo[1]) which is the the same as : &zippo[1][0] since zippo[1] holds
    // the address of first element in zippo[1].
    printf("value of zippo + 1 and zippo[1]: %p and %p\n", zippo + 1, zippo[1]);
    printf("value of &zippo : %p\n", &zippo);
    printf("value of first element in second 1d array: %d\n", *(*(zippo + 1)));
    printf("value of &(zippo + 1): %p\n", &(*(zippo + 1)));
    return 0;
}