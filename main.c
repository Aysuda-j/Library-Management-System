# include <stdio.h>
# include <stdbool.h>
# include <time.h>
# include <string.h>
#include <stdlib.h>

# define MAX_BOOKS 100

struct Book{
    char id [20];
    char title [100];
    char author [100];
    int year;
    
    bool borrowed;

    struct tm check_out;
    struct tm check_in;

    char member_id [20];
};

struct Book library [MAX_BOOKS];
int book_count = 0;

void add_book(){
    printf("Book Title: \n");
    fgets(library[book_count].title, sizeof(library[book_count].title), stdin);
    library[book_count].title[strcspn(library[book_count].title, "\n")] = '\0';

    printf("Author: \n");
    fgets(library[book_count].author, sizeof(library[book_count].author), stdin);
    library[book_count].author[strcspn(library[book_count].author, "\n")] = '\0';

    printf("Publication Year: \n");
    char year_buffer[10];
    fgets(year_buffer, sizeof(year_buffer), stdin);
    year_buffer[strcspn(year_buffer, "\n")] = '\0';
    library[book_count].year = atoi(year_buffer);
    

    printf("Book ID: ");
    fgets(library[book_count].id, sizeof (library[book_count].id), stdin);
    library[book_count].id[strcspn(library[book_count].id, "\n")] = '\0';

    library[book_count].borrowed = false;
    strcpy(library[book_count].member_id, "");

    book_count ++;
}

void print_book(int index){
    printf("\n--- Book Info ---\n");
    printf("ID: %s\n", library[index].id);
    printf("Title: %s\n", library[index].title);
    printf("Author: %s\n", library[index].author);
    printf("Year: %d\n", library[index].year);
    printf("Borrowed: %s\n", library[index].borrowed ? "Yes" : "No");
}

void search_book(){
    
    printf("Enter search term (title/author/year/member ID): \n");
    char term [100];
    
    fgets(term, sizeof (term), stdin);
    term[strcspn(term, "\n")] = '\0';

    for (int i=0 ; i<book_count ; i++){
        char year_str [10];
        sprintf(year_str, "%d", library[i].year);

        if(strstr(library[i].title, term) ||
            strstr(library[i].author, term) ||
            strstr(year_str, term) ||
            strstr(library[i].member_id, term)){
            print_book(i);
        }
    }
}

void view_status(){
    printf("Enter Book Title/Author/year ID to Check Status: \n");
    char terms[100];
    fgets(terms, sizeof(terms), stdin);
    terms[strcspn(terms, "\n")] = '\0';

    bool found = false;

    for(int i=0 ; i<book_count ; i++){
        char year_str[10];
        sprintf(year_str, "%d", library[i].year);

        if(strstr(library[i].title, terms) ||
            strstr(library[i].author, terms) ||
            strstr(year_str, terms) ||
            strstr(library[i].member_id, terms)){
                printf("Title: %s\n", library[i].title);
                printf("Borrowed: %s\n", library[i].borrowed ? "Yes" : "No");
                found = true;
            }
    }

    if(!found){printf("Book Not Found");}
}

void check_out_book(){}

void check_in_book(){}



int main(){
    int choice;

    do{
        printf("\n=== Library Management System ===\n");
        printf("1. Add a new book\n");
        printf("2. Search for a book\n");
        printf("3. View availability\n");
        printf("4. Check out a book\n");
        printf("5. Check in a book\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        while (getchar() != '\n');

        switch (choice){
            case 1: add_book(); print_book(book_count - 1); break;
            case 2: search_book(); break;
            case 3: view_status(); break;
            case 4: check_out_book(); break;
            case 5: check_in_book(); break;
            case 6: printf ("Exiting...\n"); break;
            default: printf ("Invalid Choice, Try Again.\n");
        }
    } while(choice != 6);

    return 0;
}