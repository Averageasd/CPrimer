#include <stdio.h>

void rearrange_nums(double *a, double *b, double *c);
double find_min(double a, double b, double c);
double find_max(double a, double b, double c);
double find_mid(double a, double b, double c, double max, double min);

int main(void){
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    printf("enter 3 numbers that will be assigned to a,b and c: ");
    scanf("%lf %lf %lf",&a, &b, &c);
    rearrange_nums(&a, &b, &c);

    printf("values of a,b,c after rearrange: %.2f, %.2f, %.2f\n", a, b, c);
    return 0;
}

void rearrange_nums(double *a, double *b, double *c){
    printf("In rearrange_nums(), values stored in ptrs a, b and c: %p, %p, %p\n", a, b, c);
    printf("In rearrange_nums(), values stored in addresses pointed to by ptrs a, b and c: %lf, %lf, %lf\n", *a, *b, *c);
    double min = find_min(*a, *b, *c);
    double max = find_max(*a, *b, *c);
    double mid = find_mid(*a, *b, *c, max, min);
    *a = min;
    *b = mid;
    *c = max;
}

double find_min(double a, double b, double c){
    double min = a;
    if (a <= min){
        min = a;
    }
    if (b <= min){
        min = b;
    }
    if (c <= min){
        min = c;
    }
    return min;
}

double find_max(double a, double b, double c){
    double max = a;
    if (a >= max){
        max = a;
    }
    if (b >= max){
        max = b;
    }
    if (c >= max){
        max = c;
    }
    return max;
}

double find_mid(double a, double b, double c, double max, double min){
    int counter_a = 1;
    int counter_b = 1;
    int counter_c = 1;

    // check a
    if (b == a){
        counter_a += 1;
    }

    if (c == a){
        counter_a += 1;
    }

    // check b
    if (a == b){
        counter_b += 1;
    }

    if (c == b){
        counter_b += 1;
    }

    if (a == b){
        counter_b += 1;
    }

    // check c
    if (a == c){
        counter_c += 1;
    }

    if (b == c){
        counter_c += 1;
    }

    if (counter_a >= 2){
        return a;
    }

    else if (counter_b >= 2){
        return b;
    }

    else if (counter_c >= 2){
        return c;
    }
    
    if (a > min && a < max){
        return a;
    }

    else if (b > min && b < max){
        return b;
    }

    return c;
}
