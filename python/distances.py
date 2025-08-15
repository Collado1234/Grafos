import math
from abc import ABC, abstractmethod



class DistanceMetric(ABC):
    """
    Classe base abstrata para métricas de distância.
    Define a interface para a implementação do método `calculate`.
    """
    # @classmethod
    @abstractmethod 
    def distance(self, point1, point2):
        """
        Método abstrato para calcular a distância entre dois pontos.
        Deve ser implementado por subclasses.
        """
        pass

#p1(1,1), p2(4,5)
class EuclideanDistance(DistanceMetric):
    """
    Implementação da distância Euclidiana.
    Calcula a distância entre dois pontos no espaço n-dimensional.
    """ 
    def distance(self,point1, point2):
        return math.sqrt(sum( (x - y) ** 2 for x, y in zip(point1, point2)) )
    
class ManhattanDistance(DistanceMetric):
    """
    Implementação da distância de Manhattan (ou distância L1).
    Calcula a soma das diferenças absolutas entre as coordenadas dos pontos.
    """
    def distance(self, point1, point2):
        return sum(abs(x - y) for x, y in zip(point1, point2))
    