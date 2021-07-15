#include "linkedList.h"
#include "observer.h"
#include <stdio.h>

// Implement the functions from linkedList.h

// Constructor for linkedList
void linkedListCreate(linkedListNode_t **head, int queue_size) {
	*head = malloc(sizeof(linkedListNode_t));
	(*head)->next = NULL;
	(*head)->observer = *observer_new(DEFAULT_DATA, 0, queue_size);
}

// Destructor for linkedList
void linkedListDestroy(linkedListNode_t **head) {
	linkedListNode_t *current = *head;
	linkedListNode_t *next;
	while (current != NULL) {
		next = current->next;
		free(current);
		current = next;
	}
	*head = NULL;
}

// Insert observer at the start of the linked list
void linkedListInsert(linkedListNode_t **head, Observer_t *observer) {
	linkedListNode_t *newNode = malloc(sizeof(linkedListNode_t));
	newNode->observer = *observer;
	newNode->next = *head;
	*head = newNode;
}

// Remove observer from the linked list
void linkedListRemove(linkedListNode_t **head, Observer_t *observer) {
	linkedListNode_t *current = *head;
	linkedListNode_t *previous = NULL;
	while (current != NULL) {
		// If the current node's observer matches the one we're looking for, remove it.
		if (current->observer.observerId == observer->observerId) {
			// If the observer is found, set previous to the previous node, and set current to the next node.
			if (previous == NULL) {
				*head = current->next;
			} else {
				previous->next = current->next;
			}
			free(current);
			return;
		}
		previous = current;
		current = current->next;
	}
}

void linkedListPrint(linkedListNode_t **head) {
	linkedListNode_t *current = *head;
	while (current != NULL) {
		printf("%d\n", current->observer.observerId);
		current = current->next;
	}
}