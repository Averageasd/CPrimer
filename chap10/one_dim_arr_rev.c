#include <stdio.h>

int main(void){

    int arr[5] = {1,2,3,4,5};

    // arr <-> &arr[0]. both hold address of first element in array
    // *(arr) <-> arr[0]. both hold value of first element in array which is 1
    // &arr is address of the array arr. since arr points to first element, &arr is actually address
    // of arr[0]. so &arr <-> &arr[0] and arr
    printf("value of &arr: %p\n", &arr);
    printf("value of arr: %p\n", arr);
    printf("value of &arr[0]: %p\n", &arr[0]);
    return 0;
}