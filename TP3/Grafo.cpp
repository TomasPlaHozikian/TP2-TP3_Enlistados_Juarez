#include "Grafo.h"
#include "Dijkstra.h"
#include <iostream>

Grafo::Grafo() {
    matrizDeAdyacencia = nullptr;
    vertices = new Lista<Vertice>();
    algoritmoCaminoMinimo = nullptr;
}


bool es_borde_superior(int vertice){
    bool es_borde_superior = false;
    if (1 <= vertice && vertice <= 8) es_borde_superior = true;
    return es_borde_superior;
}


bool es_borde_inferior(int vertice){
    bool es_borde_inferior = false;
    if (56 <= vertice && vertice <= 64) es_borde_inferior = true;
    return es_borde_inferior;
}


bool es_borde_izquierdo(int vertice){
    bool es_borde_izquierdo = false;
    if (vertice % 8 == 1 || vertice == 25) es_borde_izquierdo = true;
    return es_borde_izquierdo;
}


bool es_borde_derecho(int vertice){
    bool es_borde_derecho = false;
    if (vertice % 8 == 0) es_borde_derecho = true;
    return es_borde_derecho;
}


void Grafo::conectar_vertices(int vertice){
    for(int i = vertice; i <= 64; i++){
        if(i == vertice){
            agregarCamino(i, to_string(vertice), to_string(i));
        }
        else if (es_borde_superior(vertice)){
            if (es_borde_izquierdo(vertice) && (i == vertice + 8 || i == vertice + 1 )) agregarCamino(i, to_string(vertice), to_string(i));
            else if (es_borde_derecho(vertice) && (i == vertice + 8 || i == vertice - 1)) agregarCamino(i, to_string(vertice), to_string(i));
            else if(i == vertice + 8 || i == vertice + 1 || i == vertice - 1) agregarCamino(i, to_string(vertice), to_string(i));
        }
        else if (es_borde_inferior(vertice)){
            if (es_borde_izquierdo(vertice) && (i == vertice - 8 || i == vertice + 1 )) agregarCamino(i, to_string(vertice), to_string(i));
            else if (es_borde_derecho(vertice) && (i == vertice - 8 || i == vertice - 1)) agregarCamino(i, to_string(vertice), to_string(i));
            else if(i == vertice - 8 || i == vertice + 1 || i == vertice - 1) agregarCamino(i, to_string(vertice), to_string(i));
        }
        else if (es_borde_izquierdo(vertice) && (i == vertice + 8 || i == vertice - 8 || i == vertice + 1)) agregarCamino(i, to_string(vertice), to_string(i));
        else if (es_borde_derecho(vertice) && (i == vertice + 8 || i == vertice - 8 || i == vertice - 1)) agregarCamino(i, to_string(vertice), to_string(i));
        else{
            if(i == vertice + 1 || i == vertice - 1 || i == vertice + 8 || i == vertice - 8){
                agregarCamino(i, to_string(vertice), to_string(i));
            }
        }
    }
}

void Grafo::agregarVertice(string nuevoVertice) {
    agrandarMatrizDeAdyacencia();
    vertices -> agregar(nuevoVertice);
}

void Grafo::mostrarGrafo() {
    mostrarVertices();
    mostrarMatrizAdyacencia();
}

void Grafo::agregarCamino(int terreno, string origen, string destino) {
    int peso;
    int posicionOrigen = vertices ->obtenerPosicion(origen);
    int posicionDestino = vertices ->obtenerPosicion(destino);
    string terrenos[65] = {"x","C", "P", "T", "T", "T", "T", "T" , "T", "C", "T", "T", "T", "P",
     "P", "P", "P", "C", "C", "C", "C", "C", "T", "M", "M", "T", "T", "T", "T", "C", "T", "M"
    , "M", "M", "M", "M", "T", "C", "T", "M", "M", "T", "T", "T", "T", "C", "T", "M", "M", "T"
    , "P", "P", "P", "C", "T", "M", "M", "T", "T", "T", "T", "C", "C", "C", "C"};

    if (terrenos[terreno] == "C") peso = 1;
    else if (terrenos[terreno] == "T") peso = 2;
    else if (terrenos[terreno] == "M") peso = 5;
    else if (terrenos[terreno] == "P") peso = 40;

    if(posicionOrigen == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    else if(posicionDestino == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }
    else{
        matrizDeAdyacencia[posicionOrigen][posicionDestino] = peso;
        matrizDeAdyacencia[posicionDestino][posicionOrigen] = peso;
    }
}

void Grafo::caminoMinimo(string origen, string destino) {
    int posicionOrigen = vertices ->obtenerPosicion(origen);
    int posicionDestino = vertices ->obtenerPosicion(destino);

    if(posicionOrigen == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << origen << " no existe en el grafo" << endl;
    }
    if(posicionDestino == POSICION_NO_ENCONTRADA){
        cout << "El vertice " << destino << " no existe en el grafo" << endl;
    }

    caminoMinimo(posicionOrigen, posicionDestino);
}

void Grafo::agrandarMatrizDeAdyacencia() {
    int** matrizAuxiliar;
    int nuevaCantidadDeVertices = vertices->obtenerCantidadDeElementos() + 1;

    matrizAuxiliar = new int*[nuevaCantidadDeVertices];
    for(int i = 0; i < nuevaCantidadDeVertices; i++){
        matrizAuxiliar[i] = new int[nuevaCantidadDeVertices];
    }

    copiarMatrizAdyacente(matrizAuxiliar);
    inicializarNuevoVertice(matrizAuxiliar);
    liberarMatrizAdyacencia();
    matrizDeAdyacencia = matrizAuxiliar;
}

void Grafo::copiarMatrizAdyacente(int** nuevaAdyacente) {
    for(int i = 0; i < vertices -> obtenerCantidadDeElementos(); i++){
        for(int j = 0; j < vertices -> obtenerCantidadDeElementos(); j++){
            nuevaAdyacente[i][j] = matrizDeAdyacencia[i][j];
        }
    }
}

void Grafo::inicializarNuevoVertice(int** nuevaAdyacente) {
    for(int i = 0; i < vertices -> obtenerCantidadDeElementos(); i++){
        nuevaAdyacente[vertices -> obtenerCantidadDeElementos()][i] = INFINITO;
        nuevaAdyacente[i][vertices -> obtenerCantidadDeElementos()] = INFINITO;
    }
    nuevaAdyacente[vertices -> obtenerCantidadDeElementos()][vertices -> obtenerCantidadDeElementos()] = 0;
}

void Grafo::liberarMatrizAdyacencia() {
    for(int i = 0; i < vertices -> obtenerCantidadDeElementos(); i++){
        delete[] matrizDeAdyacencia[i];
    }
    delete[] matrizDeAdyacencia;
}

Grafo::~Grafo() {
    liberarMatrizAdyacencia();
    matrizDeAdyacencia = nullptr;
    delete vertices;
    delete algoritmoCaminoMinimo;
}

void Grafo::mostrarVertices() {
    cout << "Lista de vértices: [";
    for(int i = 0; i < vertices -> obtenerCantidadDeElementos(); i++){
        cout << vertices -> obtenerNombre(i + 1);
        if(i + 1 != vertices -> obtenerCantidadDeElementos()){
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

void Grafo::mostrarMatrizAdyacencia() {
    cout << "Matriz de adyacencia:" << endl;
    for(int i = 0; i < vertices -> obtenerCantidadDeElementos(); i++){
        for(int j = 0; j < vertices -> obtenerCantidadDeElementos() * 2; j++) {
            if(j == vertices -> obtenerCantidadDeElementos() * 2 - 1){
                cout << endl;
            } else if(j % 2 == 0){
                if(matrizDeAdyacencia[i][j/2] == INFINITO){
                    cout << "∞";
                } else {
                    cout << matrizDeAdyacencia[i][j/2];
                }
            } else{
                cout << "|";
            }
        }
    }
    cout << endl;
}

void Grafo::caminoMinimo(int origen, int destino) {
    algoritmoCaminoMinimo -> caminoMinimo(origen, destino);
}

int Grafo::costoViaje(int origen, int destino){
    return algoritmoCaminoMinimo->costoViaje(origen, destino);
}

int ** Grafo::obtenerMatrizCaminos(){
    return algoritmoCaminoMinimo->obtenerMatrizCaminos();
}

CaminoMinimo* Grafo::obtenerCaminoMinimo(){
    return this->algoritmoCaminoMinimo;
}

void Grafo::usarFloyd() {
    delete algoritmoCaminoMinimo;
    algoritmoCaminoMinimo = new Floyd(vertices, matrizDeAdyacencia);
}

