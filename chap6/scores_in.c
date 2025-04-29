#include <stdio.h>
#define SIZE 10
#define PAR 72

int main(void){
    int index, score[SIZE];
    int sum = 0;
    float average;

    printf("Enter %d golf scores:\n", SIZE);
    for (index = 0; index < SIZE; index++){
        // store the score in each element of array
        scanf("%d", &score[index]);
    }
    printf("The scores are in are as follows:\n");
    for (index = 0; index < SIZE; index++){
        printf("%5d", score[index]);
    }
    return 0;
}