#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FilmLen 50

typedef struct FilmNode {
    char filmName[FilmLen];
    struct FilmNode * next;
} Film;

void insertFilm(Film **,Film **, char[]);
void printList(Film * head);
void free_linked_movies(Film **);

int main(void){
    Film * head = NULL;
    Film * tail = NULL;
    insertFilm(&head, &tail, "my movie1");
    insertFilm(&head, &tail, "my movie2");
    insertFilm(&head, &tail, "my king1");
    insertFilm(&head, &tail, "my q1");
    printList(head);

    puts("-------");
    puts("free all movies");
    free_linked_movies(&head);
    puts("-------");
    return 0;
}

void insertFilm(Film ** head, Film ** tail, char filmName[]){
    Film * newFilm = (Film *)malloc(sizeof(Film));
    strcpy(newFilm->filmName, filmName);
    if ((*tail) == NULL){
        *(head) = newFilm;
        *(tail) = newFilm;
        return;
    }

    (*tail)->next = newFilm;
    (*tail) = newFilm;
    return;
}

void printList(Film * head){
    Film * tmp = head;
    while (tmp != NULL){
        printf("film: %s\n", tmp->filmName);
        tmp = tmp->next;
    }
}

void free_linked_movies(Film ** head){
    Film * tmp = *(head);
    while (tmp != NULL){
        Film * cur = tmp->next;
        free(tmp);
        tmp = cur;
    }
}