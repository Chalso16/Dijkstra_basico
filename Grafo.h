//
// Created by cbalb on 23/05/2026.
//

#ifndef DIJKSTRA_BASICO_GRAFO_H
#define DIJKSTRA_BASICO_GRAFO_H
#include <iostream>
#include <vector>
#include <memory>
#include <queue>
using namespace std;

struct Arista {
    int hacia;
    int peso;
    Arista(int hacia, int peso) ;
};

class Grafo {
private:
    int numVertices;
    vector<vector<shared_ptr<Arista>>> listaAdyacencia;
public:
    //constructores
    Grafo(int numVertices);
    //metodos;
    void addArista(int nodoOrigen, int nodoDestino, int peso);
    void dijkstra(int inicio);
    void imprimirListaAdyacencia();
};


#endif //DIJKSTRA_BASICO_GRAFO_H
