from grafos import Grafo_MatrizAdjacencia

if __name__ == "__main__":
    g = Grafo_MatrizAdjacencia(5)

    g.adicionar_aresta(0, 1, 2)
    g.adicionar_aresta(0, 2, 4)
    g.adicionar_aresta(1, 2, 1)
    g.adicionar_aresta(1, 3, 7)
    g.adicionar_aresta(2, 4, 3)

    print("Matriz de adjacência:")
    g.exibir_matriz()
    print()

    inicio = 0
    destino = 4

    buscas = [
        ("DFS", g.depth_first_search),
        ("BFS", g.breadth_first_search),
        ("UCS", g.uniform_cost_search),
        ("IDS", g.iterative_deepening_search),
        ("DLS (limite 3)", lambda s, d: g.depth_limited_search(s, d, limite=3))
    ]

    for nome, func in buscas:
        caminho, pai = func(inicio, destino)
        if caminho:
            print(f"{nome}: Caminho de {inicio} a {destino}: {caminho}")
        else:
            print(f"{nome}: Caminho não encontrado.")
        print(f"Pais: {pai}\n")
