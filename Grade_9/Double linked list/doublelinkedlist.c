#include <stdio.h>
#include <stdlib.h>
#include "doublelinkedlist.h"

List init()
{
    List newLinkedList = {
        .head = NULL,
        .size = 0};

    return newLinkedList;
}

static Node *createElement(listType value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("\nErorr alocating memory.");
        exit(1);
    }

    newNode->value = value;
    return newNode;
}

void pushFront(List *list, listType value)
{
    Node *newNode = createElement(value);

    newNode->next = list->head;
    list->head = newNode;
    newNode->prev = NULL;
    if (list->size > 0)
    {
        Node *nextNode = newNode->next;
        nextNode->prev = newNode;
    }

    list->size++;
}

void push(List *list, uint index, listType value)
{
    if (index == 0)
    {
        pushFront(list, value);
    }
    else
    {
        Node *prevNode = getElement(list, index - 1);
        Node *newNode = createElement(value);

        newNode->next = prevNode->next;
        prevNode->next = newNode;
        newNode->prev = prevNode;
        if (newNode->next != NULL)
        {
            Node *nextNode = newNode->next;
            nextNode->prev = newNode;
        }

        list->size++;
    }
}

void pushBack(List *list, listType value)
{
    push(list, list->size, value);
}

Node *getElement(List *list, uint index)
{
    if (index >= list->size)
        return NULL;

    Node *currentNode = list->head;

    for (uint i = 0; i < index; i++)
    {
        currentNode = currentNode->next;
    }
    return currentNode;
}

void setElement(List *list, uint index, listType value)
{
    Node *node = getElement(list, index);
    node->value = value;
}

listType popFront(List *list)
{
    Node *nodeToDel = list->head;

    list->head = nodeToDel->next;
    if (list->size > 1)
    {
        Node *nextNode = nodeToDel->next;
        nextNode->prev = NULL;
    }
    listType result = nodeToDel->value;

    free(nodeToDel);
    list->size--;

    return result;
}

listType pop(List *list, uint index)
{
    if (index == 0)
    {
        popFront(list);
    }

    Node *nodeToDel = getElement(list, index);
    Node *prevNode = nodeToDel->prev;

    prevNode->next = nodeToDel->next;

    if (nodeToDel->next != NULL)
    {
        Node *nextNode = nodeToDel->next;
        nextNode->prev = prevNode;
    }

    listType result = nodeToDel->value;

    free(nodeToDel);
    list->size--;

    return result;
}

listType popBack(List *list)
{
    return pop(list, list->size - 1);
}

void release(List *list)
{
    while (list->size > 0)
    {
        popFront(list);
    }
}

void forEeach(List *list, void (*callback)(uint, listType))
{
    Node *currentNode = list->head;

    uint index = 0;
    while (currentNode != NULL)
    {
        callback(index, currentNode->value);
        currentNode = currentNode->next;
        index++;
    }
}