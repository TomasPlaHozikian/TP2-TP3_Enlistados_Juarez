#ifndef ARBOL_HPP
#define ARBOL_HPP

#include "nodoarbol.hpp"


class Arbol{
    private:
        Nodo* raiz;
    public:
        Arbol();
        Nodo* obtener_raiz();
        void alta(Dato* d);//Agrega un dato al arbol
        bool existe(Clave clave);//Devuelve true si el dato existe.
        Dato* consulta(Clave clave);//Devuelve el nodo buscado.
        void baja(Clave clave);//Elimina dato donde se indique
        bool vacia();//Devuelve true si el arbol esta vacio.
        ~Arbol();
};


#endif