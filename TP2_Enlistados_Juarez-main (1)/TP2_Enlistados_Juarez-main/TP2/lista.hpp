#ifndef LISTA_HPP
#define LISTA_HPP

#include "nodo.hpp"

class Lista{
    private:
        Nodo* primero;
        int cantidad;
        Nodo* actual;
    public:
        Lista();
        void alta(Dato* d, int pos);//agrega dato donde se indique
        Dato* consulta(int pos);//dato donde se indique
        void baja(int pos);//devuelve y elimina dato donde se indique
        bool vacia();
        int obtener_cantidad();
        ~Lista();
        //ITERADOR
        bool hay_siguiente();
        Dato* siguiente();
        void iniciar(); //cursor al principio
    private:
        Nodo* obtener_nodo(int pos);//devueve puntero a nodo donde se indique
};


#endif