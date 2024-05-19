#include <stdio.h>
#include <stdlib.h>
#include "dynarr.h"
#define CHECK(arr)                     \
    if (file == NULL)                  \
    {                                  \
        printf("Cannot open file \n"); \
        exit(1);                       \
    }

void printRules()
{
    printf("\nAdd new book -> 1");
    printf("\nView all book -> 2");
    printf("\nDeleta a book -> 3");
    printf("\nSave all books -> 4");
    printf("\nExit -> 5");
}
void readFile(DynamicArray *array)
{
    FILE *file = fopen("text.txt", "r");
    CHECK(file);

    int isEof = 0;

    while (1)
    {
       Book book;
       isEof = fscanf(file, "%s %s %s %d %lu", &book.name, &book.author, &book.genre, &book.year, &book.ISBN);
       if(isEof == EOF) break;
       pushBack(array, book);
    }

    fclose(file);
}

void addBook(DynamicArray *array)
{
    Book bookForAdd;
    char ch;

    printf("\nName: ");
    scanf("%s", &bookForAdd.name);
    getchar();
    printf("\nAuthor: ");
    scanf("%s", &bookForAdd.author);
    getchar();
    printf("\nGenre: ");
    scanf("%s", &bookForAdd.genre);
    getchar();
    printf("\nYear: ");
    scanf("%d", &bookForAdd.year);
    printf("\nISBN: ");
    scanf("%lu", &bookForAdd.ISBN);

    pushBack(array, bookForAdd);
}

void printBooks(DynamicArray *array)
{
    for (int index = 0; index < array->size; index++)
    {
        Book book = getElement(array, index);

        printf("\n%s %s %s %d %lu", book.name, book.author, book.genre, book.year, book.ISBN);
    }
    printf("\n");
}

void deleteBook(DynamicArray *array, ulong ISBN)
{
    for (int i = 0; i < array->size; i++)
    {
        Book book = getElement(array, i);

        if (book.ISBN == ISBN)
        {
            removeElement(array, i);
            printf("Deleted sucessfuly.");
            break;
        }
    }
    printf("\n");
}

int main()
{
    DynamicArray array = init(0);

    readFile(&array);

    int command;
    while (1)
    {
        printRules();
        printf("\nInput a command: ");
        scanf("%d", &command);

        switch (command)
        {
        case 1:
            addBook(&array);
            break;
        case 2:
            if (array.size == 0)
            {
                printf("\nList is empty.\n");
                continue;
            }
            printBooks(&array);
            break;
        case 3:
            ulong currentISBN;
            if (array.size == 0)
            {
                printf("\nList is empty. Please add book.\n");
                continue;
            }

            printf("\nISBN:");
            scanf("%lu", &currentISBN);

            deleteBook(&array, currentISBN);
            break;
        case 4:
            FILE *file = fopen("text.txt", "w");
            CHECK(arr);
            Book book;
            for (int i = 0; i < array.size; i++)
            {
                book = getElement(&array, i);
                fprintf(file, "%s %s %s %d %lu\n", book.name, book.author, book.genre, book.year, book.ISBN);
            }
            fclose(file);
            printf("Sucessfuly saved.\n");
            break;

        case 5:
            printf("\nProgram has finished.\n");
            exit(0);
            break;

        default:
            printf("\nYou have been inputed a wrong command.Plese try again.\n");
            break;
        }
    }

    return 0;
}