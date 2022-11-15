#ifndef ARBOL_HPP
#define ARBOL_HPP

#include "nodo.hpp"

typedef string Clave;

class Arbol{
    private:
        Nodo* raiz;
    public:
        Arbol();
        void alta(Dato* d);//Agrega un dato al arbol
        bool existe(Clave nombre);//Devuelve true si el dato existe.
        Animal* consulta(Clave nombre);//Devuelve el nodo buscado.
        void baja(Clave nombre);//Elimina dato donde se indique
        bool vacia();//Devuelve true si el arbol esta vacio.
        ~Arbol();
        //ITERADOR
};


#endif