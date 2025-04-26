#include <stdio.h>
#define PI 3.14159

int main()
{
    float area, circum, radius;

    printf("What is the radius of your pizza?\n");
    scanf("%f", &radius);
    area = PI * radius * radius;
    circum = 2.0 * PI * radius;
    printf("Your bassic pizza parameters are as follow:\n");
    
    return 0;
}