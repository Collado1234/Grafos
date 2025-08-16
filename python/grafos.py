class Grafo_MatrizAdjacencia:
    def __init__(self, vertices):
        self.vertices = vertices
        self.matriz = [[0 for _ in range(vertices)] for _ in range(vertices)]

    def adicionar_aresta(self, origem, destino, peso=1): #idealmente aqui você passa a distância calculada
        if 0 <= origem < self.vertices and 0 <= destino < self.vertices: #verifica se os vértices estão dentro do intervalo
            self.matriz[origem][destino] = peso
            self.matriz[destino][origem] = peso  # Grafo não direcionado

    def remover_aresta(self, origem, destino):
        if 0 <= origem < self.vertices and 0 <= destino < self.vertices:
            self.matriz[origem][destino] = 0
            self.matriz[destino][origem] = 0  # Se o grafo for não direcionado

    def exibir_matriz(self):
        for linha in self.matriz:
            print(linha)

    def obter_arestas(self):
        arestas = []
        for i in range(self.vertices):
            for j in range(i + 1, self.vertices):  # Evita duplicatas em grafos não direcionados
                if self.matriz[i][j] != 0:
                    arestas.append((i, j, self.matriz[i][j]))
        return arestas
    
    def depth_first_search(self, inicio, objetivo):
        visitado = [False] * self.vertices
        pai = [-1] * self.vertices
        pilha = []

        # Inicialização
        pilha.append(inicio)
        visitado[inicio] = True
        pai[inicio] = inicio

        while pilha:
            vertice = pilha.pop()

            # Verifica se atingiu o objetivo
            if vertice == objetivo:
                # Reconstrução do caminho
                caminho = []
                v = objetivo
                while v != inicio:
                    caminho.append(v)
                    v = pai[v]
                caminho.append(inicio)
                caminho.reverse()
                return caminho, pai

            # Explora vizinhos
            for vizinho in range(self.vertices):
                if self.matriz[vertice][vizinho] != 0 and not visitado[vizinho]:
                    pilha.append(vizinho)
                    visitado[vizinho] = True
                    pai[vizinho] = vertice

        return None, pai  # Retorna None se não encontrar caminho

    def exibir_matriz(self):
        for linha in self.matriz:
            print(" ".join(f"{peso:3}" for peso in linha))
    
    
