#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FNAME_SIZE 20
#define LNAME_SIZE 20
#define MNAME_SIZE 20
#define PERSONS_LEN 5

struct name_struct {
    char fname[FNAME_SIZE];
    char lname[LNAME_SIZE];
    char mname[MNAME_SIZE];
};

struct person {
    int ssn;
    struct name_struct name;
};

void show_record(struct person*);
int main(void){
    int i;
    struct person persons[PERSONS_LEN] = {
        {
            123,
            {"abc","def","af"}
        },
        {
            234,
            {"ng","de","tea"}
        },
        {
            456,
            {"king","queen","tea"}
        },
        {
            678,
            {"man","de","tea"}

        },
        {
            789,
            {"yoyo","car","tea"}

        },
    };

    for (i = 0; i < PERSONS_LEN;i++){
        show_record(&persons[i]);
    }
    return 0;
}

void show_record(struct person* person_ptr){
    printf("%s, %s %c. -- %d\n", person_ptr->name.fname, person_ptr->name.lname, person_ptr->name.mname[0], person_ptr->ssn);
}
