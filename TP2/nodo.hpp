#ifndef NODO_HPP
#define NODO_HPP

#include "animal.hpp"

typedef Animal Dato;

class Nodo{
    private:
        Dato* dato;
        Nodo* siguiente;
    public:
        Nodo(Dato* d);
        void cambiar_siguiente(Nodo* p);
        Dato* obtener_dato();
        Nodo* obtener_siguiente();

};

#endif