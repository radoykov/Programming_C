#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedlist.h"

void printElement(uint index, ListType value);
void printLinkedList(LinkedList *list);
void printMenu();
char *getStatusName(Status status);

int main()
{
    int command;
    LinkedList listTasks = init();

    printMenu();

    while (1)
    {
        printf("\nInput command: ");
        scanf("%d", &command);

        switch (command)
        {
        case addTask:
            char name[30];
            uint priority;

            printf("\nInput priority: ");
            scanf("%u", &priority);
            if (priority < 1)
            {
                printf("\nInvalid priority!");
                break;
            }

            printf("\nInput name: ");
            scanf("%s", &name);
            getchar();

            ListType newTask = {.status = New};
            strcpy(newTask.name, name);

            if (priority == 1)
            {
                pushFront(&listTasks, newTask);
            }
            else if (priority > listTasks.size)
            {
                pushBack(&listTasks, newTask);
            }
            else
            {
                push(&listTasks, priority - 1, newTask);
            }

            printf("\nTask has been added.");

            break;

        case changeStatus:
            Status newStatus;

            printf("\nInput priority: ");
            scanf("%u", &priority);
            if (priority < 1)
            {
                printf("\nInvalid priority!");
                break;
            }

            struct ListNode *element = getElement(&listTasks, priority - 1);
            if (element == NULL)
            {
                printf("\nNo task with such priority.");
                break;
            }
            printf("Current status: %s", getStatusName(element->value.status));
            printf("\nInput new status (1: New, 2: Started, 3: Finished) = ");
            scanf("%d", &newStatus);

            element->value.status = newStatus;
            printf("\nTask status has been changed.");


            break;
        case printAll:
            if (listTasks.size > 0)
            {
                printLinkedList(&listTasks);
            }
            else
            {
                printf("No tasks exists.");
            }
            break;
        case delTask:

            printf("\nProvide task priority: ");
            scanf("%u", &priority);

            if (priority < 1)
            {
                printf("\nInvalid priority!");
                break;
            }

            struct ListNode *elementToDelete = getElement(&listTasks, priority - 1);
            if (elementToDelete == NULL)
            {
                printf("\nNo task with such priority.");
                break;
            }
            pop(&listTasks, priority - 1);
            printf("\nTask has been deleted.");

            break;
        case exitOfTask:
            release(&listTasks);
            printf("The program have finished.");
            exit(0);

        default:
            printf("\nYou have provided a wrong command. Please try again.");
            break;
        }
    }

    return 0;
}

void printElement(uint index, ListType value)
{
    printf("\n#%d name:%s status:%s", index + 1, value.name, getStatusName(value.status));
}

void printLinkedList(LinkedList *list)
{
    forEeach(list, printElement);
    printf("\n");
}

void printMenu()
{
    printf("\nAdd task -> 1");
    printf("\nChange status -> 2");
    printf("\nPrint all tasks-> 3");
    printf("\nDelete task -> 4");
    printf("\nExit -> 5");
}

char *getStatusName(Status status)
{
    switch (status)
    {
    case New:
        return "New";
    case Started:
        return "Started";
    case Finished:
        return "Finished";
    default:
        return NULL;
    }
}