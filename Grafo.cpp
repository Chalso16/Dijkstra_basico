//
// Created by cbalb on 23/05/2026.
//

#include "Grafo.h"

//constructores
Arista::Arista(int hacia, int peso):hacia(hacia), peso(peso) {
}

Grafo::Grafo(int numVertices):numVertices(numVertices) {
    listaAdyacencia.resize(numVertices);
}

void Grafo::addArista(int nodoOrigen, int nodoDestino, int peso) {
    listaAdyacencia.at(nodoOrigen).push_back(make_shared<Arista>(nodoDestino, peso));
}

void Grafo::dijkstra(int inicio) {
    //inicializar distancias a "infinito"
    vector<int> distancias(numVertices,INT_MAX);

    //Cola de prioridad para almacenar pares (distancia, nodo)
    // greater<> hace que el elemento con menor distancia quede en el tope
    //priority_queue<Tipo_de_dato, como_se_almacena, criterio_de_ordenacion> nombre;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> colaPrioridad;

    //distancia al nodo origen
    distancias.at(inicio) = 0;
    colaPrioridad.push({0, inicio});


    while (!colaPrioridad.empty()) {
        int dist = colaPrioridad.top().first;
        int nodo = colaPrioridad.top().second;
        colaPrioridad.pop();

        if (dist > distancias.at(nodo)) continue;

        //Recorrer aristas adyacentes
        for (auto& arista: listaAdyacencia.at(nodo)) {
            int nodoDestino = arista->hacia;
            int peso = arista->peso;

            //si se encuentra un camino mas corto
            if (distancias.at(nodo) + peso < distancias.at(nodoDestino)) {
                distancias.at(nodoDestino) = distancias.at(nodo) + nodo;
                colaPrioridad.push({distancias.at(nodoDestino), nodoDestino});
            }
        }
    }

    cout << "Distancias minimas desde el nodo " << inicio << ":" << endl;
    for (int i=0; i<numVertices; i++) {
        if (distancias.at(i) == INT_MAX) {
            cout << "Nodo " << i << ": Inalcanzable" << endl;
        }
        else {
            cout << "Nodo " << i << ": " << distancias.at(i) << endl;
        }
    }
}