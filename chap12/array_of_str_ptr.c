#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TMP_BUFFER_SIZE 100

void free_word_arr(char**, size_t);

int main(void){
    char ** str_arr_ptr;
    char buffer[TMP_BUFFER_SIZE];
    int num_words;
    int i;

    printf("enter number of words: ");
    scanf("%d", &num_words);
    str_arr_ptr = (char**)malloc(num_words * sizeof(char*));
    i = 0;
    for (i = 0; i < num_words; i++){
        scanf("%s",buffer);
        str_arr_ptr[i] = (char*)malloc((strlen(buffer) + 1) * sizeof(char));
        strncpy(str_arr_ptr[i], buffer, sizeof(str_arr_ptr[i]) - 1);
        printf("word is %s\n", str_arr_ptr[i]);
    }

    free_word_arr(str_arr_ptr, sizeof(str_arr_ptr));
    return 0;
}

void free_word_arr(char** words, size_t words_size){
    size_t i;
    size_t len;

    i = 0;
    len = words_size / sizeof(char*);

    for (i = 0; i<len;i++){
        free(words[i]);
    }

    free(words);
}