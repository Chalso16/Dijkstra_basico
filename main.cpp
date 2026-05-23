#include "Grafo.h"
#include <iostream>
using namespace std;

int main() {
    // Definimos el número de vértices
    int numVertices = 5;

    // Instanciamos la clase Graph
    Grafo g(numVertices);

    // Construimos el grafo añadiendo las aristas (origen, destino, peso)
    g.addArista(0, 1, 10);
    g.addArista(0, 4, 3);
    g.addArista(1, 2, 2);
    g.addArista(1, 4, 4);
    g.addArista(2, 3, 9);
    g.addArista(3, 2, 7);
    g.addArista(4, 1, 1);
    g.addArista(4, 2, 8);
    g.addArista(4, 3, 2);

    // Ejecutamos el algoritmo partiendo desde el nodo 0
    cout << "Ejecutando Dijkstra desde el nodo 0...\n";
    cout << "--------------------------------------\n";
    g.dijkstra(0);

    return 0;
}
