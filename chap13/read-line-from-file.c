#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIM 250

void remove_new_line(char buffer[], FILE*);

int main(int argc, char *argv[]){
    FILE *fp;
    char buffer[LIM];

    if (argc < 2){
        fprintf(stderr, "Usage: %s filename\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL){
        fprintf(stderr, "Failed to open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(buffer, LIM, fp) != NULL){
        remove_new_line(buffer, fp);
        printf("line: %s\n", buffer);
    }
    printf("\n");
    fclose(fp);
    return 0;
}

void remove_new_line(char buffer[], FILE * fp){
    int i;
    int size;
    int ch;

    i = 0;
    size = LIM;

    while (i < size){
        if (buffer[i] == '\n'){
            buffer[i] = '\0';
            return;
        }
        i++;
    }
}