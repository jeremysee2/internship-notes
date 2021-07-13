#ifndef QUEUE_H
#define QUEUE_H

// Queue implementation using a list

typedef struct {
    size_t head;
    size_t tail;
    size_t size;
    void** data;
} queue_t;

void* queue_read(queue_t *queue);
int queue_write(queue_t *queue, void* handle);

#endif