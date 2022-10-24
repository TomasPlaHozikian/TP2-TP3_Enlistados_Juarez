#ifndef NODO_H
#define NODO_H

typedef char Dato;

class Nodo{
    private:
        Dato dato;
        Nodo* siguiente;
    public:
        Nodo(Dato d);
        void cambiar_siguiente(Nodo* p);
        Dato obtener_dato();
        Nodo* obtener_siguiente();

};

#endif