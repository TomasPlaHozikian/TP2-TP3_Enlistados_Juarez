#ifndef NODOARBOL_HPP
#define NODOARBOL_HPP

#include "animal.hpp"

typedef Animal Dato;
typedef string Clave;


class Nodo{
    private:
        Dato* clave1;
        Dato* clave2;
        Nodo* padre;
        Nodo* hijo_izquierdo;
        Nodo* hijo_medio;
        Nodo* hijo_derecho;
    public:
        Nodo(Dato* d);
        Dato* obtener_clave1();
        Dato* obtener_clave2();
        Nodo* obtener_padre();
        void cambiar_clave1(Dato* nuevo);
        void eliminar_clave2();
        void eliminar_hijo_izquierdo();
        void eliminar_hijo_medio();
        void eliminar_hijo_derecho();
        void derivar_agregar_a_hijos(Dato* nuevo);
        void asignar_hijo_derecho(Nodo* padre_nuevo);
        void asignar_hijo_medio(Nodo* hijo_medio_nuevo);
        void asignar_hijo_izquierdo(Nodo* hijo_izquierdo_nuevo);
        void asignar_clave1(Dato* nueva_clave1);
        void asignar_clave2(Dato* nueva_clave2);
        bool verificar_existencia_de_la_clave(Clave clave);
        Dato* devolver_dato_por_clave(Clave clave);
        void baja(Clave clave);
        //PRE: -
        //POST: Devuelve true si tiene 2da clave.
        bool hay_clave2();
        //PRE: -
        //POST: Devuelve true si tiene hijo izquierdo.
        bool hay_izquierdo();
        //PRE: -
        //POST: Devuelve true si tiene hijo derecho.
        bool hay_derecho();
        //PRE: -
        //POST: Devuelve true si tiene hijo medio.
        bool hay_medio();
        bool hay_padre();
        void asignar_padre(Nodo* padre_nuevo);
        //PRE: Debe tener hijo izquierdo.
        //POST: Devuelve el hijo izquierdo.
        Nodo* obtener_izquierdo();
        //PRE: Debe tener hijo derecho.
        //POST: Devuelve el hijo derecho.
        Nodo* obtener_derecho();
        //PRE: Debe tener hijo medio.
        //POST: Devuelve el hijo medio.
        Nodo* obtener_medio();
        void crear_hijos(Dato* izquierdo, Dato* medio, Dato* derecho);
        void agregar_clave2(Dato* clave_nueva);
        void agregar_clave_a_padre(Dato* nuevo, Nodo* nodo_izquierdo, Nodo* nodo_derecho);
        //PRE: -
        //POST: Agrega un nuevo dato al arbol.
        void agregar(Dato* nuevo);
        //PRE: -
        //POST: Si tiene hijos los manda a eliminar, sino se elimina.
        void eliminarse_completo();
};


#endif