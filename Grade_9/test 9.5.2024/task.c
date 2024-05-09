#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long type;
typedef unsigned int uint;

typedef struct node
{
    struct node * next;
    type value;

}Node;

typedef struct list
{
    uint size;
    Node * head;
}List;

List init()
{
    List newlist = {
        .size = 0,
        .head = NULL
    };

    return newlist;
}

void pushFront(List * list, type value)
{
    Node * newNode = (Node *) malloc(sizeof(Node));
    if(newNode == NULL)
    {
        printf("\nError");
        exit(1);
    }

    newNode->next=list->head;
    list->head=newNode;
    newNode->value = value;
    list->size++;
}

type popFront(List * list)
{
    Node * nodeDel = list->head;
    
    type res = nodeDel->value;

    list->head = nodeDel->next;

    free(nodeDel);
    list->size--;

    return res;
}

void printlinkedlist(List * list)
{
    Node * node = list->head;

    for(int i=list->size;i>0; i--)
    {
        printf("%ld, ", node->value);
        node = node->next;
    }
}

int main()
{
    List list = init();
    pushFront(&list, 10);
    pushFront(&list, 20);
    pushFront(&list, 30);

    printlinkedlist(&list);

    popFront(&list);
    popFront(&list);

    printlinkedlist(&list);

    return 0;
 
}