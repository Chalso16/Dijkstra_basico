#include "Grafo.h"
#include <iostream>
using namespace std;

int main() {
    // Definimos el número de vértices
    int numVertices = 5;

    // Instanciamos la clase Graph
    Grafo grafo(numVertices);

    // Construimos el grafo añadiendo las aristas (origen, destino, peso)
    grafo.addArista(0, 1, 10);
    grafo.addArista(0, 4, 3);
    grafo.addArista(1, 2, 2);
    grafo.addArista(1, 4, 4);
    grafo.addArista(2, 3, 9);
    grafo.addArista(3, 2, 7);
    grafo.addArista(4, 1, 1);
    grafo.addArista(4, 2, 8);
    grafo.addArista(4, 3, 2);

    //Lista de Adyacencia
    grafo.imprimirListaAdyacencia();

    // Ejecutamos el algoritmo partiendo desde el nodo 0
    cout << "Ejecutando Dijkstra desde el nodo 0...\n";
    cout << "--------------------------------------\n";
    grafo.dijkstra(0);

    // Ejecutamos el algoritmo partiendo desde el nodo 0
    cout << "\nEjecutando Dijkstra desde el nodo 1...\n";
    cout << "--------------------------------------\n";
    grafo.dijkstra(1);

    return 0;
}
