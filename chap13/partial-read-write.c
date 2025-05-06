#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 50

void open_file(FILE**, char[], char[]);
void close_file(FILE**);

int main(int argc, char *argv[]){
    FILE *in, *out;
    int ch;
    int count;

    if (argc < 3){
        fprintf(stderr, "Usage: %s filename filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    open_file(&in, argv[1], "r");
    open_file(&out, argv[2], "w");

    while ((ch = getc(in)) != EOF){
        if (count % 3 == 0){
            putc(ch, out);
        }
        count++;
    }
    return 0;
}

// if we only pass single pointer, we essentially create create a local copy of file
// that also points to null. modifying such single pointer does nothing for us
// we have to instead, pass a pointer that points to file. inside here, it will create a local copy
// of double pointer that holds address of *file. dereference it, we will get the reference to *file we created in
// main
void open_file(FILE **file, char filename[], char mode[]){
    if ((*(file) = fopen(filename, mode)) == NULL){
        fprintf(stderr, "Cannot open the file %s\n", filename);
        exit(EXIT_FAILURE);
    }
}

void close_file(FILE** file){
    if (fclose(*(file)) != 0){
        fprintf(stderr, "Error in closing file\n");
    }
}