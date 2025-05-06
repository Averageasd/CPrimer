#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    printf("hello\n");
    int ch;
    FILE *fp;
    unsigned long count = 0;
    if (argc != 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF)
    {
        // print char from file to screen
        putc(ch, stdout);
        count++;
    }

    printf("\n");

    if (fclose(fp) != 0){
        fclose(fp);
    }
    printf("File %s has %lu characters\n", argv[1], count);

    return 0;
}