
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define LEN 20

void appyly_func(void(*)(char *), char*);
void reverse_str(char*);
void print_str(char*);

int main(void){

    char buffer[20];
    strcpy(buffer,"hello");

    // function pointer 
    // (char *) argument accepted by function pointer
    void(*pf)(char *);

    printf("applying string reversal...\n");

    // function pointer now points to reverse_str function
    pf = reverse_str;

    // pass function pointer as argument
    appyly_func(pf, buffer);

    print_str(buffer);
    return 0;
}

void appyly_func(void (*fp)(char *), char * str){

    // apply function pointer to str
    (*fp)(str);
}

void reverse_str(char * s){
    int len = strlen(s);
    int i = 0;
    int k = len-1;
    printf("len is %d\n", len);
    int tmp = 0;

    while (i < k){
        tmp = s[k];
        s[k] = s[i];
        s[i] = tmp;
        i++;
        k--;
    }
}

void print_str(char * s){
    int len = strlen(s);
    int i = 0;
    for (i = 0; i < len; i++){
        printf("%c ",s[i]);
    }

    printf("\n");
}
