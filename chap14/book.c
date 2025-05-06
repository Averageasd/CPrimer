#include <stdio.h>
#include <string.h>

#define TITLE_LENGTH 20
#define AUTHOR_LENGTH 20

void get_str_input(char*, int);

struct Book {
    char title[TITLE_LENGTH];
    char author[TITLE_LENGTH];
    float value;
};

int main(void) {
    struct Book book;
    printf("Please enter the book title:\n");
    get_str_input(book.title, TITLE_LENGTH);
    printf("Please enter the author:\n");
    get_str_input(book.author, AUTHOR_LENGTH);
    printf("Please enter book value:\n");
    scanf("%f", &book.value);
    printf("%s by %s: %.2f\n", book.title, book.author, book.value);
    printf("size of Book struct %zd\n", sizeof(book));
    return 0;
}

void get_str_input(char * st, int n){
    fgets(st, n, stdin);
    
    int i;
    int len;

    i = 0;
    len = strlen(st);

    for (i = 0; i < len; i++){
        if (st[i] == '\n'){
            st[i] = '\0';
            return;
        }
    }
    
    while (getchar() != '\n'){
        continue;
    }
}