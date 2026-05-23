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
    //Camino de ida
    listaAdyacencia.at(nodoOrigen).push_back(make_shared<Arista>(nodoDestino, peso));

    //Camino de vuelta
    //Descomentar hace que el grafo NO sea dirigido
    //listaAdyacencia.at(nodoDestino).push_back(make_shared<Arista>(nodoOrigen, peso));

}

void Grafo::dijkstra(int inicio) {
    //inicializar distancias a "infinito"
    vector<int> distancias(numVertices,INT_MAX);

    //Cola de prioridad para almacenar pares (distancia, nodoActual)
    //greater<> hace que el elemento con menor distancia quede en el tope
    //priority_queue<Tipo_de_dato, como_se_almacena, criterio_de_ordenacion> nombre;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> colaPrioridad;

    //Distancia al nodo origen
    distancias.at(inicio) = 0;
    colaPrioridad.push({0, inicio});


    while (!colaPrioridad.empty()) {
        int dist = colaPrioridad.top().first;
        int nodoActual = colaPrioridad.top().second;
        colaPrioridad.pop();

        if (dist > distancias.at(nodoActual)) continue;

        //Recorrer aristas adyacentes
        for (auto& arista: listaAdyacencia.at(nodoActual)) {
            int nodoDestino = arista->hacia;
            int peso = arista->peso;

            //Si se encuentra un camino mas corto
            //Distancia hasta NodoActual
            if (distancias.at(nodoActual) + peso < distancias.at(nodoDestino)) {
                //actualizamos el valor de la distancia al nodoDestino
                distancias.at(nodoDestino) = distancias.at(nodoActual) + peso;
                //lo añadimos a la cola para recorrerlo luego
                colaPrioridad.push({distancias.at(nodoDestino), nodoDestino});
                //cout << "Distancia minTemporal a nodo " << nodoDestino << ": " << distancias.at(nodoDestino) << endl;
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

void Grafo::imprimirListaAdyacencia() {
    cout << "\n--- Lista de Adyacencia del Grafo ---" << endl;
    for (int i = 0; i < numVertices; ++i) {
        cout << "Nodo [" << i << "]: ";

        // Si no hay conexiones
        if (listaAdyacencia.at(i).empty()) {
            cout << "Sin conexiones";
        } else {
            // Recorremos las aristas almacenadas en este indice
            for (auto& arista : listaAdyacencia.at(i)) {
                // Al usar shared_ptr, utilizamos -> para acceder a los miembros de la estructura
                cout << "-> (Destino: " << arista->hacia << ", Peso: " << arista->peso << ") ";
            }
        }
        cout << endl;
    }
    cout << "-------------------------------------\n" << endl;
}
