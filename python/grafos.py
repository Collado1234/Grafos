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