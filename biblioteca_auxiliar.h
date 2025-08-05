//.h da biblioteca auxiliar 
#ifndef BIBLIOTECA_AUXILIAR_H
#define BIBLIOTECA_AUXILIAR_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "biblioteca_auxiliar.h"

// Tipo booleano
typedef enum Boolean {
    true = 1,
    false = 0
} boolean;

typedef struct Stack_node{
    int neighbor;
    struct Stack_node* prox;
}Stack_node;

typedef struct Stack_node* p_stack_node;

typedef struct Stack {
    Stack_node* top;
    int size;       
} Stack;

typedef Stack* p_stack;

p_stack create_stack();
int is_stack_empty(p_stack s);
void push(p_stack s, int neighbor);
int pop(p_stack s);
void free_stack(p_stack s);

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

#endif