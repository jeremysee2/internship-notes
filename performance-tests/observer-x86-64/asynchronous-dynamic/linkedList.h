#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "observer.h"

// Linked list typedef struct
typedef struct linkedListNode {
	Observer_t observer;
	struct linkedListNode *next;
} linkedListNode_t;

// Linked list operations
void linkedListCreate(linkedListNode_t **head, int queue_size);
void linkedListDestroy(linkedListNode_t **head);
void linkedListInsert(linkedListNode_t **head, Observer_t *observer);
void linkedListRemove(linkedListNode_t **head, Observer_t *observer);
void linkedListPrint(linkedListNode_t **head);

#endif