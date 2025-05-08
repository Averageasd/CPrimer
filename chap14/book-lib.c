#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXBOOKS 50
#define UPDATE_ACTION "update"
#define DELETE_ACTION "delete"

struct book
{
    int id;
    char bookname[20];
    char author[20];
    float price;
    int delete;
};

void set_empty_book(struct book *, int);
void create_new_book(struct book *);
void get_str_input(char *s, int size);
void notifyFullDB();
void print_book(struct book *);
void print_books(struct book *);
void set_book_info(struct book *);
void update_book(struct book *);
void delete_book(struct book *);
int find_valid_book_id(struct book*, char[]);

int main(void)
{

    FILE *book_file_ptr;
    struct book books[MAXBOOKS];
    int count;
    int choice;
    size_t book_read_res;
    struct book *book_arr_ptr;
    struct book *book_arr_tmp;

    book_file_ptr = fopen("books.dat", "rb+");
    count = 0;
    choice = 0;
    book_read_res = 0;
    book_arr_ptr = &books[0];
    book_arr_tmp = book_arr_ptr;
    rewind(book_file_ptr);
    printf("contents of book.dat:\n");
    while (count < MAXBOOKS)
    {
        book_read_res = fread(book_arr_tmp, sizeof(struct book), 1, book_file_ptr);
        if (book_read_res == 0)
        {
            set_empty_book(book_arr_tmp, count);
        }
        else{
            if (book_arr_tmp->delete == 1){
                set_empty_book(book_arr_tmp, count);
            }
            print_book(book_arr_tmp);
        }
        book_arr_tmp++;
        count++;
    }

    do
    {
        printf("enter 4 to quit\n");
        scanf("%d", &choice);
        getchar();
        if (choice == 4)
        {
            break;
        }
        else if (choice == 0){
            print_books(book_arr_ptr);
        }
        else if (choice == 1)
        {
            create_new_book(book_arr_ptr);
        }
        else if (choice == 2)
        {
            update_book(book_arr_ptr);
        }
        else if (choice == 3){
            delete_book(book_arr_ptr);
        }
    } while (choice != 4);

    rewind(book_file_ptr);
    print_books(books);
    fwrite(&books[0], sizeof(struct book), MAXBOOKS, book_file_ptr);
    fclose(book_file_ptr);
    return 0;
}

void set_empty_book(struct book *book_ptr, int id)
{
    strcpy(book_ptr->author, "");
    strcpy(book_ptr->bookname, "");
    book_ptr->id = id;
    book_ptr->price = 0.0f;
    book_ptr->delete = 1;
}

void create_new_book(struct book *book_ptr)
{
    int empty_book_idx;
    int i;
    struct book *tmp_pointer;

    tmp_pointer = book_ptr;

    for (i = 0; i < MAXBOOKS; i++)
    {
        if (tmp_pointer->delete == 1)
        {
            empty_book_idx = i;
            break;
        }
        tmp_pointer++;
    }

    if (i >= MAXBOOKS)
    {
        notifyFullDB();
    }

    tmp_pointer->id = empty_book_idx;
    printf("enter new book:\n");
    set_book_info(tmp_pointer);
}

void set_book_info(struct book *book_ptr)
{
    printf("enter book name: ");
    get_str_input(book_ptr->bookname, 20);
    printf("enter author name: ");
    get_str_input(book_ptr->author, 20);
    printf("enter price: ");
    scanf("%f", &(book_ptr->price));
    book_ptr->delete = 0;
    getchar();
}

void update_book(struct book *book_ptr)
{
    int valid_id = find_valid_book_id(book_ptr,UPDATE_ACTION);
    if (valid_id == -1){
        printf("failed to update book.\n");
        return;
    }
    set_book_info(book_ptr + valid_id);
    printf("book with id %d updated.\n", valid_id);
}

void delete_book(struct book *book_ptr)
{
    int valid_id = find_valid_book_id(book_ptr,DELETE_ACTION);
    if (valid_id == -1){
        printf("failed to delete book.\n");
        return;
    }
    printf("book with id %d deleted.\n", valid_id);
    set_empty_book(book_ptr + valid_id, valid_id);
}

void get_str_input(char *s, int size)
{
    fgets(s, size, stdin);
    int i;
    for (i = 0; i < size; i++)
    {
        if (s[i] == '\n')
        {
            s[i] = '\0';
            return;
        }
    }

    while (getchar() != '\n')
    {
        continue;
    }
}

void print_books(struct book *book_ptr)
{
    struct book *tmp_book_ptr = book_ptr;
    int i = 0;

    for (i = 0; i < MAXBOOKS; i++)
    {
        if (tmp_book_ptr->delete == 0)
        {
            print_book(tmp_book_ptr);
        }
        tmp_book_ptr++;
    }
}

int find_valid_book_id(struct book* book_ptr, char action[]){
    int existing_book_id;
    int i;
    struct book *tmp_book_ptr;
    int found_valid_id;

    tmp_book_ptr = book_ptr;
    i = 0;
    existing_book_id = 0;
    printf("enter book id you want to %s: ", action);
    scanf("%d", &existing_book_id);
    getchar();
    if (existing_book_id < 0 || existing_book_id >= MAXBOOKS)
    {
        return -1;
    }
    else
    {
        tmp_book_ptr = (book_ptr + existing_book_id);
        if (tmp_book_ptr->delete == 1)
        {
            printf("no book with this ID\n");
            return -1;
        }
    }
    return existing_book_id;
}

void print_book(struct book *book_ptr)
{
    printf("Id: %d; name: %s; author: %s; price: %.2f\n", book_ptr->id, book_ptr->bookname, book_ptr->author, book_ptr->price);
}

void notifyFullDB()
{
    printf("book.dat is full");
}
