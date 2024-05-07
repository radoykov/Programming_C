#include <stdio.h>
#include "doublelinkedlist.h"

void printList(uint index, listType value)
{
    printf("index(%u)=>%lf", index, value);
}

void printLinkedList(List *list)
{
    forEeach(list, printList);
    printf("\n");
}

int main()
{
    printf("Executing tests: \n");
    List list = init();
    printf("Is head NULL: %d\n", list.head == NULL);
    printf("Size: %u\n", list.size);

    pushFront(&list, 10);
    pushFront(&list, 15);
    pushFront(&list, 20);
    printLinkedList(&list);

    Node *secondNode = getElement(&list, 1);
    printf("Second value : %lf\n", secondNode->value);

    push(&list, 1, 99);
    printLinkedList(&list);

    pushBack(&list, 105);
    printLinkedList(&list);

    setElement(&list, 2, 999);
    printLinkedList(&list);

    listType firstElement = popFront(&list);
    printf("First element: %lf \n", firstElement);
    printLinkedList(&list);

    listType thirdElement = pop(&list, 2);
    printf("Third element: %lf \n", thirdElement);
    printLinkedList(&list);

    listType lastElement = popBack(&list);
    printf("Last element: %lf \n", lastElement);
    printLinkedList(&list);

    release(&list);
    printf("Is head NULL: %d\n", list.head == NULL);
    printf("Size: %u\n", list.size);

    return 0;
}