//.h da biblioteca auxiliar 
#ifndef QUEUE_H
#define QUEUE_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Queue.h"


typedef struct Queue {
    int *data;       
    int front;      
    int rear;       
    int size;       
    int capacity;  
} Queue;

typedef Queue* p_queue;

p_queue create_queue(int capacity);
int is_queue_empty(p_queue q);
int is_queue_full(p_queue q);
void enqueue(p_queue q, int value);
int dequeue(p_queue q);
void free_queue(p_queue q);

#endif // STACK_H