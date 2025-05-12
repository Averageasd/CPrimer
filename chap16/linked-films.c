#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FilmLen 50
#define DirectorLen 50

typedef struct FilmNode {
    char authName [DirectorLen];
    char filmName[FilmLen];
    struct FilmNode * next;
} Film;

void insertFilm(Film **,Film **, char[], char[]);
void printList(Film * head);
void free_linked_movies(Film **);
Film * makeFilm(char[], char[]);

int main(void){
    Film * head = NULL;
    Film * tail = NULL;
    insertFilm(&head, &tail, "my movie1", "director1");
    insertFilm(&head, &tail, "my movie2", "director1");
    insertFilm(&head, &tail, "my king1", "kingdir");
    insertFilm(&head, &tail, "my q1", "kingdir");
    printList(head);

    puts("-------");
    puts("free all movies");
    free_linked_movies(&head);
    puts("-------");
    return 0;
}

void insertFilm(Film ** head, Film ** tail, char filmName[], char authName[]){
    Film * newFilm = makeFilm(filmName, authName);
    if ((*tail) == NULL){
        *(head) = newFilm;
        *(tail) = newFilm;
        return;
    }

    (*tail)->next = newFilm;
    (*tail) = newFilm;
    return;
}

Film * makeFilm(char filmName[], char authorName[]){
     Film * newFilm = (Film *)malloc(sizeof(Film));
     strcpy(newFilm->filmName, filmName);
     strcpy(newFilm->authName, authorName);
     return newFilm;
}

void printList(Film * head){
    Film * tmp = head;
    while (tmp != NULL){
        printf("film: %s. Director: %s\n", tmp->filmName, tmp->authName);
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