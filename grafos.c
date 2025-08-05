#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Stack.h"
#include "Queue.h"
#define MAX_VERTICES 100
#define MAX_NAME_LENGTH 30

// Estrutura para ponto (vértice)
typedef struct Point {
    int pos_x;
    int pos_y;
    char name[30];
} Point;

// Estrutura para aresta (nó da lista)
typedef struct Node {
    int neighbor;
    float weight;
    struct Node* prox;
} Node;

typedef Node* p_node;

// Estrutura para grafo
typedef struct Graph {
    p_node *list_adjacency;
    int number_of_vertices;
    Point *coordinates;
    boolean *busy;  // <-- vetor para indicar quais índices já têm vértices
} Graph;

typedef Graph* p_graph;

// Cria grafo
p_graph create_graph(int size) {
    p_graph new_g = malloc(sizeof(Graph));
    new_g->number_of_vertices = size;
    new_g->list_adjacency = malloc(size * sizeof(p_node));
    new_g->coordinates = malloc(size * sizeof(Point));
    new_g->busy = calloc(size, sizeof(boolean));  // Inicializa como false

    for (int i = 0; i < size; i++) {
        new_g->list_adjacency[i] = NULL;
    }

    return new_g;
}

// Define coordenadas para o primeiro índice disponível
void set_coordinates(p_graph g, int x, int y, char *name) {
    for (int i = 0; i < g->number_of_vertices; i++) {
        if (!g->busy[i]) {
            g->coordinates[i].pos_x = x;
            g->coordinates[i].pos_y = y;
            strcpy(g->coordinates[i].name, name);
            g->busy[i] = true;
            return;
        }
    }
    printf("Erro: Não há espaço livre no grafo.\n");
}

// Calcula distância euclidiana
float calculate_distance(Point a, Point b) {
    return sqrt(pow(a.pos_x - b.pos_x, 2) + pow(a.pos_y - b.pos_y, 2));
}

void free_list(p_node list) {
    p_node temp;
    while (list != NULL) {
        temp = list;
        list = list->prox;
        free(temp);
    }
}

void free_graph(p_graph g){
    for(int i = 0; i < g->number_of_vertices; i++) {
        free_list(g->list_adjacency[i]);
    }
    free(g->list_adjacency);
    free(g->coordinates);
    free(g->busy);
    free(g);
    g = NULL;
    printf("Grafo destruído com sucesso.\n");
    return;    
}

/* 
    function to insert a node in the adjacency list
    This function creates a new node with the given neighbor and weight,
    and inserts it at the beginning of the list.
    @param list Pointer to the head of the adjacency list
    @param neighbor The index of the neighbor vertex
    @param weight The weight of the edge (distance)
    @return Pointer to the new head of the list
*/
p_node insert_list(p_node list, int neighbor, float weight) {
    p_node new_node = malloc(sizeof(Node));
    new_node->neighbor = neighbor;
    new_node->weight = weight;
    new_node->prox = list;
    return new_node;
}

/*
Function to insert an edge in the graph
This function adds an edge between two vertices in the graph.
It updates the adjacency list for both vertices.
It also calculates the distance between the two vertices and stores it as the weight of the edge.
If the vertices are invalid (out of bounds), it prints an error message.
@param g Pointer to the graph
@param src Source vertex index
@param dest Destination vertex index
*/
void insert_edge(p_graph g, int src, int dest) {
    if (src >= g->number_of_vertices || dest >= g->number_of_vertices) {
        printf("Erro: vértice inválido.\n");
        return;
    }

    float distance = calculate_distance(g->coordinates[src], g->coordinates[dest]);

    // Insere nas duas direções (grafo não direcionado)
    g->list_adjacency[src] = insert_list(g->list_adjacency[src], dest, distance);
    g->list_adjacency[dest] = insert_list(g->list_adjacency[dest], src, distance);
}

/*
    Function to print the graph
    This function prints the adjacency list of each vertex in the graph.
    @param g Pointer to the graph
*/
void print_graph(p_graph g) {
    for (int i = 0; i < g->number_of_vertices; i++) {
        if (g->busy[i]) {
            printf("%s (%d, %d): ", g->coordinates[i].name, g->coordinates[i].pos_x, g->coordinates[i].pos_y);
            p_node current = g->list_adjacency[i];
            while (current != NULL) {
                printf(" -> %s [%.2f]", g->coordinates[current->neighbor].name, current->weight);
                current = current->prox;
            }
            printf("\n");
        }
    }
}

//void depth_first_search(p_graph g, int start, boolean *visited){}


void depth_first_search(p_graph g, int start, boolean *visited) {
    if (!g->busy[start] || visited[start]) return;

    visited[start] = true;
    printf("Visitando: %s\n", g->coordinates[start].name);

    p_node current = g->list_adjacency[start];
    while (current != NULL) {
        if (!visited[current->neighbor]) {
            depth_first_search(g, current->neighbor, visited);
        }
        current = current->prox;
    }
}

void dfs(p_graph g, int start) {
    int visited[MAX_VERTICES] = {0};
    p_stack s = create_stack();

    push(s, start);
    visited[start] = 1;

    while (!is_stack_empty(s)) {
        int v = pop(s);
        printf("Visitou: %s\n", g->coordinates[v].name);

        for (p_node u = g->list_adjacency[v]; u != NULL; u = u->prox){
            if (!visited[u->neighbor]) {
                visited[u->neighbor] = 1;
                push(s, u->neighbor);
            }
        }
    }

    free_stack(s);
}


// Main
int main() {
    p_graph g = create_graph(4);

    set_coordinates(g, 0, 0, "Casa A");
    set_coordinates(g, 3, 4, "Casa B");
    set_coordinates(g, 5, 2, "Casa C");
    set_coordinates(g, 1, 1, "Casa D"); 

    float d = calculate_distance(g->coordinates[0], g->coordinates[1]);
    printf("Distância entre %s e %s: %.2f\n",
           g->coordinates[0].name,
           g->coordinates[1].name,
           d);

    insert_edge(g, 0, 1);
    insert_edge(g, 1, 2);
    insert_edge(g, 0, 3);
    insert_edge(g, 2, 3);

    print_graph(g);

    // Chamada do DFS
    for (int i = 0; i < g->number_of_vertices; i++) {
        boolean *visited = calloc(g->number_of_vertices, sizeof(boolean));
        printf("DFS a partir de %s:\n", g->coordinates[i].name);
        depth_first_search(g, i, visited);
        free(visited);
    }   

    Queue *queue = create_queue(5);
    free_graph(g);
    printf("Programa finalizado.\n");
    return 0;
}

