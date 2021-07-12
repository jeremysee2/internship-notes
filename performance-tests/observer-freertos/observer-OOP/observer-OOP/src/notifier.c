#include "notifier.h"
#include <stdio.h>

// Notification flag
static int isNotifying = 0;
static uint32_t currentData;

// Local helper functions for managing the linked-list
static void appendToList(const Observer* observer)
{
    // Append a copy of the observer to the linked-list
	struct ListNode* newNode = malloc(sizeof(struct ListNode));
	newNode->item = *observer;
	newNode->next = NULL;
	if (observers.next == NULL)
	{
		observers.next = newNode;
	}
	else
	{
		struct ListNode* currentNode = &observers;
		while (currentNode->next != NULL)
		{
			currentNode = currentNode->next;
		}
		currentNode->next = newNode;
	}
}

static void removeFromList(const Observer* observer)
{
    // Identify the observer in the linked-list and remove that node
	struct ListNode* currentNode = &observers;
	while (currentNode->next != NULL)
	{
		// Check if pointers match; if so, remove the node 
		if (currentNode->next == observer)
		{
			struct ListNode* toBeDeleted = currentNode->next;
			currentNode->next = currentNode->next->next;
			free(toBeDeleted);
			return;
		}
		currentNode = currentNode->next;
	}
}

// Implementation of the Notifier interface
void attach(const Observer* observer)
{
    assert(NULL != observer);
    appendToList(observer);
    // To constrain, that this does not occur during a Notification
    assert(0 == isNotifying);
}

// Implementation of the Notifier interface
void detach(const Observer* observer)
{
    assert(NULL != observer);
    removeFromList(observer);
    // To constrain, that this does not occur during a Notification
    assert(0 == isNotifying);
}