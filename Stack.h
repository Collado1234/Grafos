//.h da biblioteca auxiliar 
#ifndef STACK_H
#define STACK_H

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

#endif