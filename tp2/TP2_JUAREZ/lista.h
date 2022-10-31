#ifndef LISTA_H
#define LISTA_H

#include "nodo.h"

class Lista{
    private:
        Nodo* primero;
        int cantidad;
        Nodo* actual;
    public:
        Lista();
        void alta(Dato d, int pos);//agrega dato donde se indique
        Dato consulta(int pos);//dato donde se indique
        void baja(int pos);//devuelve y elimina dato donde se indique
        bool vacia();
        int obtener_cantidad();
        ~Lista();
        //ITERADOR
        bool hay_siguiente();
        Dato siguiente();
        void iniciar(); //cursor al principio
    private:
        Nodo* obtener_nodo(int pos);//devueve puntero a nodo donde se indique
    //************EJERCICIO DE LISTA************
    public:
        //PRE: Se tienen dos posiciones dentro de la lista.
        //POST: Se itercambian los datos de las posiciones entre si.
        void intercambio_dato(int pos1, int pos2);
        //PRE: Se ingresa una nueva lista por parametro.
        //POST: La nueva lista se une a la original.
        void union_listas(Lista lista_nueva);
        //PRE: Se ingresa una nueva lista por parametro.
        //POST: La nueva lista se une a la original y devuelve la lista nueva unida a la inicial.
        Lista* union_listas_a_nueva(Lista lista_nueva);
        //PRE: -.
        //POST: Invierte la lista.
        void invertir_lista();
        //PRE: Se ingresa una lista nueva por parametro.
        //POST: Invierte la lista nueva y devuelve la misma invertida.
        Lista* invertir_lista_nueva(Lista lista_nueva);
        //PRE: Se ingresa una nueva lista por parametro ordenada.
        //POST: La nueva lista se une a la original y se ordenan los datos y se eliminan los repetidos.
        void union_listas_ordenada_sin_repetidos(Lista lista_nueva);
        //PRE: La lista no esta vacia.
        //POST: Elimina el dato indicado de la lista.
        void eliminar_dato(Dato dato);
        //PRE: La lista no esta vacia.
        //POST: Elimina el dato indicado de la lista en todas sus ocurrencias.
        void eliminar_dato_total(Dato dato);
        //PRE: Ingresa una lista nueva por parametrp.
        //POST: Devuelve una lista que posee todos los datos que no estan en la lista ingresada por parametro.
        void eliminar_datos_de_nueva_lista(Lista* lista_nueva);

};


#endif