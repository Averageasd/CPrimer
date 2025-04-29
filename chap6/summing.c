#include <stdio.h>

int main(){
    long num;
    long sum = 0L;
    int status;

    printf("Please enter an integer to be summed ");
    printf("(q to quit): ");
    status = scanf("%ld", &num);

    while (status == 1){
        sum = sum + num;
        printf("Please enter next integer (q to quit): ");

        // scanf returns 1 if it successfully reads an integer
        // if not, returns 0
        // so here, if we enter a non-integer, it will return 0 and 0
        // is assigned to status and loop is terminated
        status = scanf("%ld", &num);
    }

    printf("Those integers sum to %ld.\n", sum);
    return 0;
}