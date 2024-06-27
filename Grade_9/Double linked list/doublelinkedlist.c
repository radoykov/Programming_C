#include <stdio.h>
#include <stdlib.h>
#include "doublelinkedlist.h"

List init()
{
    List newLinkedList = {
        .head = NULL,
        .tail = NULL,
        .size = 0};

    return newLinkedList;
}

static Node *createElement(ListType value)
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

void pushFront(List *list, ListType value)
{
    Node *newNode = createElement(value);

    if (list->size > 0)
    {
        newNode->next = list->head;
        newNode->prev = NULL;
        list->head->prev = newNode;
        list->head = newNode;
    }
    else
    {
        list->head = newNode;
        list->tail = newNode;
        newNode->prev = NULL;
        newNode->next = NULL;
    }

    list->size++;
}

void push(List *list, uint index, ListType value)
{
    if (index == 0)
    {
        pushFront(list, value);
    }
    else if (index == list->size)
    {
        pushBack(list, value);
    }
    else
    {
        Node *prevNode = getElement(list, index - 1);
        Node *newNode = createElement(value);

        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        prevNode->next->prev = newNode;
        prevNode->next = newNode;

        list->size++;
    }
}

void pushBack(List *list, ListType value)
{
    Node *newNode = createElement(value);

    if (list->size > 0)
    {
        newNode->next = NULL;
        newNode->prev = list->tail;
        list->tail->next = newNode;
        list->tail = newNode;
    }
    else
    {
        list->head = newNode;
        list->tail = newNode;
        newNode->prev = NULL;
        newNode->next = NULL;
    }

    list->size++;
}

Node *getElement(List *list, uint index)
{

    if (index >= list->size)
    {
        return NULL;
    }

    if (index <= list->size / 2)
    {
        Node *currentNode = list->head;
        for (uint i = 0; i < index; i++)
        {
            currentNode = currentNode->next;
        }
        return currentNode;
    }
    else
    {
        Node *currentNode = list->tail;
        for (uint i = list->size - 1; i > index; i--)
        {
            currentNode = currentNode->prev;
        }
        return currentNode;
    }
}

void setElement(List *list, uint index, ListType value)
{
    Node *node = getElement(list, index);
    node->value = value;
}

ListType popFront(List *list)
{
    Node *nodeToDel = list->head;

    if (list->size == 1)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        nodeToDel->next->prev = NULL;
        list->head = nodeToDel->next;
    }

    ListType result = nodeToDel->value;
    free(nodeToDel);
    list->size--;

    return result;
}

ListType pop(List *list, uint index)
{
    if (index == 0)
    {
        popFront(list);
    }
    else if (index == list->size - 1)
    {
        popBack(list);
    }

    Node *nodeToDel = getElement(list, index);
    Node *prevNode = nodeToDel->prev;

    nodeToDel->next->prev = prevNode;
    prevNode->next = nodeToDel->next;

    ListType result = nodeToDel->value;

    free(nodeToDel);
    list->size--;

    return result;
}

ListType popBack(List *list)
{
    Node *nodeToDel = list->tail;
    ListType result = nodeToDel->value;

    if (list->size == 1)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        nodeToDel->prev->next = NULL;
        list->tail = nodeToDel->prev;
        free(nodeToDel);
    }

    list->size--;

    return result;
}

void release(List *list)
{
    while (list->size > 0)
    {
        popFront(list);
    }
}

void forEeach(List *list, void (*callback)(uint, ListType))
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

void forEeachReversed(List *list, void (*callback)(uint, ListType))
{
    Node *currentNode = list->tail;

    uint index = list->size - 1;
    while (currentNode != NULL)
    {
        callback(index, currentNode->value);
        currentNode = currentNode->prev;
        index--;
    }
}