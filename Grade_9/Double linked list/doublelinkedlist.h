#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

typedef double ListType;
typedef unsigned int uint;

typedef struct node
{
    struct node *prev;
    struct node *next;
    ListType value;

} Node;

typedef struct 
{
    Node *head;
    Node *tail;
    uint size;

} List;

List init();
void pushFront(List * list, ListType value);
void push(List * list, uint index, ListType value);
void pushBack(List * list, ListType value);

Node * getElement(List * list, uint index);

void setElement(List *list, uint index, ListType value);

ListType popFront(List * list);
ListType pop(List * list, uint index);
ListType popBack(List * list);
void release(List * list);

void forEeach(List * list, void (*callback)(uint, ListType));
void forEeachReversed(List * list, void (*callback)(uint, ListType)) ;

#endif