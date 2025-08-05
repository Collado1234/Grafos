//Biblioteca auxiliar para o trabalho de Grafos, criar fila e pilha

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "biblioteca_auxiliar.h"

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

p_stack create_stack() {
    p_stack s = malloc(sizeof(Stack));
    s->top = NULL;
    s->size = 0;
    return s;
}

int is_stack_empty(p_stack s) {
    return s->top == NULL;
}

void push(p_stack s, int neighbor) {
    p_stack_node new_node = malloc(sizeof(Stack_node));
    new_node->neighbor = neighbor;
    new_node->prox = s->top;
    s->top = new_node;
    s->size++;
}

int pop(p_stack s) {
    if (is_stack_empty(s)) {
        printf("Erro: pilha vazia!\n");
        exit(1);
    }
    p_stack_node temp = s->top;
    int neighbor = temp->neighbor;
    s->top = s->top->prox;
    free(temp);
    s->size--;
    return neighbor;
}

void free_stack(p_stack s) {
    p_stack_node current = s->top;
    p_stack_node temp;
    while (current != NULL) {
        temp = current;
        current = current->prox;
        free(temp);
    }
    free(s);
}

typedef struct Queue {
    int *data;       
    int front;      
    int rear;       
    int size;       
    int capacity;  
} Queue;

typedef Queue* p_queue;

p_queue create_queue(int capacity) {
    p_queue q = malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Erro ao alocar memória para a fila.\n");
        exit(1);
    }
    q->data = malloc(capacity * sizeof(int));
    if (q->data == NULL) {
        printf("Erro ao alocar memória para os dados da fila.\n");
        free(q);
        exit(1);
    }
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = capacity;
    return q;
}

int is_queue_empty(p_queue q) {
    return q->size == 0;
}

int is_queue_full(p_queue q) {
    return q->size == q->capacity;
}

void enqueue(p_queue q, int value) {
    if (is_queue_full(q)) {
        printf("Erro: fila cheia!\n");
        exit(1);
    }
    q->rear = (q->rear + 1) % q->capacity; // Incrementa o índice do fim circularmente
    q->data[q->rear] = value;
    q->size++;
}

int dequeue(p_queue q) {
    if (is_queue_empty(q)) {
        printf("Erro: fila vazia!\n");
        exit(1);
    }
    int value = q->data[q->front];
    q->front = (q->front + 1) % q->capacity; // Incrementa o índice do início circularmente
    q->size--;
    return value;
}

void free_queue(p_queue q) {
    free(q->data);
    free(q);
}



