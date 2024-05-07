#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

typedef double listType;
typedef unsigned int uint;

typedef struct node
{
    struct node *prev;
    struct node *next;
    listType value;

} Node;

typedef struct 
{
    Node *head;
    uint size;

} List;

List init();
void pushFront(List * list, listType value);
void push(List * list, uint index, listType value);
void pushBack(List * list, listType value);

Node * getElement(List * list, uint index);

void setElement(List *list, uint index, listType value);

listType popFront(List * list);
listType pop(List * list, uint index);
listType popBack(List * list);
void release(List * list);


void forEeach(List * list, void (*callback)(uint, listType));

#endif