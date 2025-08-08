//Biblioteca auxiliar para o trabalho de Grafos, criar fila e pilha
#include <stdlib.h>
#include "Stack.h"
#include <stdio.h>

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





