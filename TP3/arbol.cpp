#include "arbol.hpp"


Arbol::Arbol(){
    raiz = 0;
}

Nodo* Arbol::obtener_raiz(){
    return raiz;
}

void Arbol::alta(Dato* d){
    if (vacia()){
        Nodo* nuevo = new Nodo(d);
        raiz = nuevo;
    } 
    else {
        raiz->agregar(d);
    }
    if (raiz->hay_padre())
    {
        Nodo* nueva_raiz = raiz->obtener_padre();
        raiz = nueva_raiz;
    }
}


void Arbol::baja(Clave clave){
    raiz->baja(clave);
}


bool Arbol::existe(Clave nombre){
    bool existe;
    existe = raiz->verificar_existencia_de_la_clave(nombre, false);
    return existe;
}


Dato* Arbol::devuelve_dato_por_clave(Clave clave){
    Dato* dato;
    dato = raiz->devolver_dato_por_clave(clave);
    return dato;
}


Dato* Arbol::consulta(Clave clave){
    return raiz->devolver_dato_por_clave(clave);
}


bool Arbol::vacia(){
    return (raiz == 0);
}


Arbol::~Arbol(){
    delete raiz;
}
