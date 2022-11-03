#include "lista.hpp"


Lista::Lista(){
    primero = 0;
    cantidad = 0;
    actual = primero;
}


Nodo* Lista::obtener_nodo(int pos){
    Nodo* aux = primero;
    for(int i = 1; i < pos; i++){
        aux = aux->obtener_siguiente();
    }
    return aux;
}


void Lista::alta(Dato* d, int pos){
    Nodo* nuevo = new Nodo(d);
    Nodo* siguiente = primero;
    if(pos == 1){
        primero = nuevo;
    }
    else{  
        Nodo* anterior = obtener_nodo(pos-1);
        siguiente = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(nuevo);
    }
    nuevo->cambiar_siguiente(siguiente);
    cantidad++;
    }


Dato* Lista::consulta(int pos){
    Nodo* nodo = obtener_nodo(pos);
    return nodo->obtener_dato();
}


void Lista::baja(int pos){
    Nodo* borrar = primero;
    if(pos == 1){
        primero = primero->obtener_siguiente();
    } 
    else{
        Nodo* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
        Nodo* siguiente = borrar->obtener_siguiente();
        anterior->cambiar_siguiente(siguiente);

    }
    delete borrar;
    cantidad--;
}


bool Lista::vacia(){
    return (primero == 0);
}


int Lista::obtener_cantidad(){
    return cantidad;
}


//ITERADOR
bool Lista::hay_siguiente(){
    return actual != 0;
}


Dato* Lista::siguiente(){
    Dato* dato = actual->obtener_dato();
    actual = actual->obtener_siguiente();
    return dato;
}


void Lista::iniciar(){
    actual = primero;
}


Lista::~Lista(){
    while (! vacia())
        baja(1);
}