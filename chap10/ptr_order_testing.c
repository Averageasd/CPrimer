#include <stdio.h>
#define SIZE 5

void traverse_with_ptrs(int* start, int* end);

int main(void){
    int arr[5] = {1,2,3,4,5};

    int* pt = arr;
    
    printf("pt + 1 is %p\n", pt);
    printf("*pt + 1 is %d\n", *pt + 1);
    printf("*(pt + 1) is %d\n", *(pt + 1));
    printf("size of pt is %zd bytes\n", sizeof(pt));
    traverse_with_ptrs(pt, pt + SIZE);
}

void traverse_with_ptrs(int* start, int* end){
    printf("\n");
    printf("Calling traverse_with_ptrs(int*, int*)\n");
    int* dummy = start;
    for (dummy = start; dummy < end; dummy++){
        printf("visit element %d at address %p\n", *dummy, dummy);
    }    
}