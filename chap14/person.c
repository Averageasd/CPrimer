#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PERSON_NAME_SIZE 20

void get_str(char *, int);

struct person
{
    int ID;
    char firstname[PERSON_NAME_SIZE];
    char lastname[PERSON_NAME_SIZE];
};

int main(void)
{
    int personId = 0;
    struct person person_template = {-1, "", ""};
    struct person *person_pt = &person_template;

    printf("Please enter person id: \n");
    scanf("%d", &person_pt->ID);
    getchar();
    printf("Please enter person's first name:\n");
    get_str(person_pt->firstname, PERSON_NAME_SIZE);

    printf("Please enter person's last name:\n");
    get_str(person_pt->lastname, PERSON_NAME_SIZE);

    printf("ID: %d, first name: %s, last name: %s\n", person_pt->ID, person_pt->firstname, person_pt->lastname);
    return 0;
}

void get_str(char *name, int n)
{
    fgets(name, n, stdin);
    int i;

    for (i = 0; i < PERSON_NAME_SIZE; i++)
    {
        if (name[i] == '\n')
        {
            name[i] = '\0';
            return;
        }
    }

    while (getchar() != '\n')
    {
        continue;
    }
}