#include<Stdio.h>
#include<stdlib.h>

//criando um tipo booleano, para facilitar a leitura do código
// true = 1, false = 0
typedef enum Boolean{
    true = 1,
    false = 0
} boolean;

typedef struct Node {    
    int pos_x;
    int pos_y;
} Node;

typedef Node* p_node;
