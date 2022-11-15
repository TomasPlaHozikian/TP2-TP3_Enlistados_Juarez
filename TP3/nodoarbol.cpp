#include "nodoarbol.hpp"


Nodo::Nodo(Dato* d){
    dato = d;
    hijo_izquierdo = 0;
    hijo_derecho = 0;
}


bool Nodo::hay_izquierdo(){
    return  hijo_izquierdo != 0;
}


bool Nodo::hay_derecho(){
    return  hijo_derecho != 0;
}


Nodo* Nodo::obtener_izquierdo(){
    return hijo_izquierdo;
}


Nodo* Nodo::obtener_derecho(){
    return hijo_derecho;
}


void Nodo::agregar(Nodo* nuevo){
    if (dato->obtener_nombre() > nuevo->obtener_dato()->obtener_nombre()) {
            if (hijo_izquierdo != 0) hijo_izquierdo->agregar(nuevo);
            else hijo_izquierdo = nuevo;
        }
    else
        if (hijo_derecho != 0) hijo_derecho->agregar(nuevo);
        else hijo_derecho = nuevo;
}


void Nodo::baja(string nombre){
    if (hijo_izquierdo->obtener_dato()->obtener_nombre() == nombre) eliminar_nodo(hijo_izquierdo, "izquierdo");
    else if (hijo_derecho->obtener_dato()->obtener_nombre() == nombre) eliminar_nodo(hijo_derecho, "derecho");
    else if (dato->obtener_nombre() > nombre) hijo_izquierdo->baja(nombre);
    else hijo_derecho->baja(nombre);
}


void Nodo::eliminar_nodo(Nodo* eliminar, string lado){
    Nodo* derecho, *izquierdo, *borrar;
    Dato* borrar2;
    borrar = eliminar;
    borrar2 = eliminar->obtener_dato();
    derecho = eliminar->obtener_derecho();
    izquierdo = eliminar->obtener_izquierdo();
    izquierdo->agregar(derecho->obtener_izquierdo());
    derecho->cambiar_izquierdo(izquierdo);
    if (lado == "izquierdo") hijo_izquierdo = derecho;
    else hijo_derecho = derecho;
    delete borrar2;
    delete borrar;
}


void Nodo::cambiar_izquierdo(Nodo* nuevo){
    hijo_izquierdo = nuevo;
}


void Nodo::eliminar_hijos(){
    Animal* dato_borrar;
    if (hijo_izquierdo)
    {
        if (hijo_izquierdo->hay_izquierdo() || hijo_izquierdo->hay_derecho())
        {
            hijo_izquierdo->eliminar_hijos();
        }
        else
        {
            dato_borrar = hijo_izquierdo->obtener_dato();
            delete dato_borrar;
            delete hijo_izquierdo;
        }
    }
    if (hijo_derecho){
        if (hijo_derecho->hay_izquierdo() || hijo_derecho->hay_derecho())
        {
            hijo_derecho->eliminar_hijos();
        }
        else
        {
            dato_borrar = hijo_derecho->obtener_dato();
            delete dato_borrar;
            delete hijo_derecho;
        }
    }
}