#include "arbol.hpp"


Arbol::Arbol(){
    raiz = 0;
}


void Arbol::alta(Dato* d){
    Nodo* nuevo = new Nodo(d);
    if (vacia()) raiz = nuevo;
    else raiz->agregar(nuevo);
}


bool Arbol::existe(Clave nombre){
    bool existe = false, parar = false;
    Nodo* actual = raiz;
    while (!parar) {
        if (actual->obtener_dato()->obtener_nombre() == nombre) {
            existe = true;
        }
        else if (actual->obtener_dato()->obtener_nombre() > nombre) {
            if (actual->hay_izquierdo()) actual=actual->obtener_izquierdo();
            else parar = true;
        }
        else {
            if (actual->hay_derecho()) actual=actual->obtener_derecho();
            else parar = true;
        }
    }
    return existe;
}


Animal* Arbol::consulta(Clave nombre){
    bool parar = false;
    Nodo* actual = raiz;
    Animal* existe;
    while (!parar) {
        if (actual->obtener_dato()->obtener_nombre() == nombre) {
            existe = actual->obtener_dato();
        }
        else if (actual->obtener_dato()->obtener_nombre() > nombre) {
            if (actual->hay_izquierdo()) actual=actual->obtener_izquierdo();
            else parar = true;
        }
        else {
            if (actual->hay_derecho()) actual=actual->obtener_derecho();
            else parar = true;
        }
    }
    return existe;
}


void Arbol::baja(Clave nombre){
    if (raiz->obtener_dato()->obtener_nombre() == nombre) {
        Nodo* derecho, *izquierdo, *borrar;
        Dato* borrar2;
        borrar = raiz;
        borrar2 = raiz->obtener_dato();
        derecho = raiz->obtener_derecho();
        izquierdo->agregar(derecho->obtener_izquierdo());
        derecho->cambiar_izquierdo(izquierdo);
        raiz = derecho;
        delete borrar2;
        delete borrar;
    }
    else
    {
        raiz->baja(nombre);
    } 
}


bool Arbol::vacia(){
    return (raiz == 0);
}


Arbol::~Arbol(){
    Animal* dato_borrar;
    raiz->eliminar_hijos();
    dato_borrar = raiz->obtener_dato();
    delete dato_borrar;
    delete raiz;
}