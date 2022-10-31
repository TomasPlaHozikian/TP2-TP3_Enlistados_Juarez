#include "nodo.hpp"

Nodo::Nodo(Dato* d){
    dato = d;
    siguiente = 0;
}

void Nodo::cambiar_siguiente(Nodo* p){
    siguiente = p;
}

Nodo* Nodo::obtener_siguiente(){
    return siguiente;
}

Dato* Nodo::obtener_dato(){
    return dato;
}