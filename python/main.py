import grafos as g

if __name__ == "__main__":
    # Criar grafo com 5 vértices
    g = g.Grafo_MatrizAdjacencia(5)

    # Adicionar algumas arestas
    g.adicionar_aresta(0, 1, 2)
    g.adicionar_aresta(0, 2, 4)
    g.adicionar_aresta(1, 2, 1)
    g.adicionar_aresta(1, 3, 7)
    g.adicionar_aresta(2, 4, 3)

    # Exibir a matriz de adjacência
    print("Matriz de adjacência:")
    g.exibir_matriz()
    print()

    inicio = 0
    destino = 4
    # Testar DFS do vértice 0 ao 4
    caminho, pai = g.depth_first_search(inicio, destino)

    if caminho:
        print(f"Caminho encontrado de {inicio} até {destino}: {caminho}")
    else:
        print("Caminho não encontrado.")

    # Exibir array de pais
    print(f"Pais dos vértices: {pai}")
