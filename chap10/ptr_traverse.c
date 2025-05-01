#include <stdio.h>
#define SIZE 5

int main(void){
    int arr[SIZE] = {1,2,3,4,5};
    int* pt = arr;
    int i = 0;
    int* cur_pt = NULL;
    int len = sizeof(arr) / (sizeof(arr[0]));
    printf("len %d\n", len);

    for (i = 0; i < len; i++){
        cur_pt = pt + i;
        printf("pt + %d. pt pointing at %p\n", i, cur_pt);
        printf("value is %d\n",*cur_pt);
    }
    return 0;

}