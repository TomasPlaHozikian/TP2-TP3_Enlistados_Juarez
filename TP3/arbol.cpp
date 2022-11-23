#include "arbol.hpp"


Arbol::Arbol(){
    raiz = 0;
}


void Arbol::alta(Dato* d){
    
    if (vacia()){
        Nodo* nuevo = new Nodo(d);
        raiz = nuevo;
    } 
    else raiz->agregar(d);
}


void Arbol::baja(Clave clave){
    raiz->baja(clave);
}


bool Arbol::existe(Clave nombre){
    bool existe;
    existe = raiz->verificar_existencia_de_la_clave(nombre);
    return existe;
}


Dato* Arbol::consulta(Clave clave){
    return raiz->devolver_dato_por_clave(clave);
}


bool Arbol::vacia(){
    return (raiz == 0);
}


Arbol::~Arbol(){
    raiz->eliminarse_completo();
    delete raiz;
}