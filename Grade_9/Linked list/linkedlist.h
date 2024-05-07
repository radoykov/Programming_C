#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef enum
{
    New = 1,
    Started,
    Finished

} Status;

typedef enum
{
    addTask = 1,
    changeStatus,
    printAll,
    delTask,
    exitOfTask
} Commands;

typedef struct
{
    char name[30];
    Status status;
    
} Task;

typedef Task ListType;
typedef unsigned int uint;

struct ListNode {
  ListType value;
  struct ListNode * next;
};

typedef struct {
  struct ListNode * head;
  uint size;
} LinkedList;

LinkedList init();

void pushFront(LinkedList * list, ListType value);
void push(LinkedList * list, uint index, ListType value);
void pushBack(LinkedList * list, ListType value);

struct ListNode * getElement(LinkedList * list, uint index);
void setElement(LinkedList * list, uint index, ListType value);

ListType popFront(LinkedList * list);
ListType pop(LinkedList * list, uint index);
ListType popBack(LinkedList * list);

void release(LinkedList * list);

void forEeach(LinkedList * list, void (*callback)(uint, ListType));

#endif