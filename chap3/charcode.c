#include <stdio.h>
int main()
{
    char ch;

    printf("Please eneter a character.\n");
    scanf("%c", &ch);
    printf("The code for %c is %d.\n", ch, ch);
    return 0;
}