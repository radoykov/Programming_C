#ifndef QUEUE_H
#define QUEUE_H

#include "doublelinkedlist.h"

typedef ListType QueueType;

typedef struct {
  List list;
} ListQueue;

ListQueue initQueue();

void enqueue(ListQueue * queue, QueueType value);

QueueType dequeue(ListQueue * queue);

#endif