#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP

#include "animal.hpp"

typedef Animal Dato;


class Nodo{
    private:
        Dato* dato;
        Nodo* hijo_izquierdo;
        Nodo* hijo_derecho;
    public:
        Nodo(Dato* d);
        Dato* obtener_dato();
        //PRE: -
        //POST: Devuelve true si tiene hijo izquierdo.
        bool hay_izquierdo();
        //PRE: -
        //POST: Devuelve true si tiene hijo derecho.
        bool hay_derecho();
        //PRE: Debe tener hijo izquierdo.
        //POST: Devuelve el hijo izquierdo.
        Nodo* obtener_izquierdo();
        //PRE: Debe tener hijo derecho.
        //POST: Devuelve el hijo derecho.
        Nodo* obtener_derecho();
        //PRE: -
        //POST: Agrega un nuevo nodo al arbol.
        void agregar(Nodo* nuevo);
        //PRE: Debe existir el nodo al que se le quiere dar de baja.
        //POST: Elimina al nodo y dato que se quiere buscandolo por el nombre.
        void baja(string nombre);
        //PRE: -
        //POST: Cambia el hijo izquierdo de un nodo por otro.
        void cambiar_izquierdo(Nodo* nuevo);
        //PRE: lado tiene que decir el lado del hijo que se quiere eliminar.
        //POST: Elimina un nodo desde su padre, sin perder los hijos.
        void eliminar_nodo(Nodo* eliminar, string lado);
        //PRE: -
        //POST: Elimina ambos hijos de un padre.
        void eliminar_hijos();
};


#endif