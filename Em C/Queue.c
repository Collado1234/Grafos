#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

/*
Esta biblioteca auxilia na manipulação de filas
Ela inclui funções para criar, destruir e manipular filas,
*/

/*
    Function to create a queue with a given capacity
    @param capacity The maximum number of elements the queue can hold
    @return Pointer to the created queue
*/
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

/*
    Function to check if the queue is empty
    @param q Pointer to the queue
    @return 1 if the queue is empty, 0 otherwise
*/
int is_queue_empty(p_queue q) {
    return q->size == 0;
}

/*
    Function to check if the queue is full
    @param q Pointer to the queue
    @return 1 if the queue is full, 0 otherwise
*/
int is_queue_full(p_queue q) {
    return q->size == q->capacity;
}

/*
    Function to add an element to the queue
    This function adds an element to the end of the queue.
    If the queue is full, it prints an error message and exits.
    @param q Pointer to the queue
    @param value The value to be added to the queue
*/
void enqueue(p_queue q, int value) {
    if (is_queue_full(q)) {
        printf("Erro: fila cheia!\n");
        exit(1);
    }
    q->rear = (q->rear + 1) % q->capacity; // Incrementa o índice do fim circularmente
    q->data[q->rear] = value;
    q->size++;
}

/*
    Function to remove an element from the queue
    This function removes an element from the front of the queue.
    If the queue is empty, it prints an error message and exits.
    @param q Pointer to the queue
    @return The value removed from the front of the queue
*/
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


/*
    Function to destroy the queue
    This function frees the memory allocated for the queue and its data.
    @param q Pointer to the queue
*/
void free_queue(p_queue q) {
    free(q->data);
    free(q);
}