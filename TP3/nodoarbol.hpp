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

        //SETTERS => Les asigna valores a todos los datos del nodo.

        //Agregan valores a los datos del nodo.
        void asignar_clave1(Dato* nueva_clave1);
        void asignar_clave2(Dato* nueva_clave2);
        void asignar_hijo_derecho(Nodo* padre_nuevo);
        void asignar_hijo_medio(Nodo* hijo_medio_nuevo);
        void asignar_hijo_izquierdo(Nodo* hijo_izquierdo_nuevo);
        void asignar_padre(Nodo* padre_nuevo);

        //Eliminan valores de los datos del nodo.
        void eliminar_clave2();
        void eliminar_hijo_izquierdo();
        void eliminar_hijo_medio();
        void eliminar_hijo_derecho();
        //---------------------------------------------------------------------------------------------------
        //GETTERS => PRE: Deben existir.

        //DATOS => POST: Devuelven los datos guardados con esas claves.
        Dato* obtener_clave1();
        Dato* obtener_clave2();
        //VINCULOS => POST: Devuelven los nodos vinculados a este, tanto sus hijos como su padre.
        Nodo* obtener_izquierdo();
        Nodo* obtener_derecho();
        Nodo* obtener_medio();
        Nodo* obtener_padre();
        //---------------------------------------------------------------------------------------------------
        //Preguntan si los datos del nodo ya tienen asignado algun valor, en caso afirmativo devuelven true.

        bool hay_clave2();
        bool hay_hijo_izquierdo();
        bool hay_hijo_derecho();
        bool hay_hijo_medio();
        bool hay_padre();
        //---------------------------------------------------------------------------------------------------
        //Se utilizan en la insercion de un nuevo dato

        //Se fija si tiene que agregar el mismo el dato, sus hijos o si debe dividirse y agregarlo su padre
        //PRE: El dato debe estar bien cargado y no existir dentro del arbol.
        //POST: Inserta el dato en el arbol segun su clave.
        void agregar(Dato* nuevo);
        //Se fija a que hijo debe derivar el dato para que lo agregue.
        //PRE: Debe tener hijos.
        //POST: Deriva el dato al hijo para que lo agregue.
        void derivar_agregar_a_hijos(Dato* nuevo);
        //Compara si la clave nueva es menor o mayor que la clave1 ya existente y la agrega correctamente.
        //PRE: -
        //POST: Ambas claves y sus hijos quedan ordenados.
        void agregar_clave2(Dato* clave_nueva);
        //Deriva al padre todos los datos necesarios para que agregue una nueva clave.
        //PRE: -
        //POST: Se hacen todas las modificaciones para que el todos los nodos esten correctamente unidos.
        void agregar_clave_a_padre(Dato* nuevo, Nodo* nodo_izquierdo, Nodo* nodo_derecho);

        //AUXILIAR

        //Divide un nodo correctamente y devuelve un nuevo nodo creado a partir de la clave2.
        //PRE: Debe tener ambas claves.
        //POST: Te queda un nodo con 3 hijos y 1 sola clave.
        Nodo* dividir_nodo();
        //PRE: Debe tener hijos.
        //POST: Desde el padre entra a los hijos y se asigna como su padre.
        void asignar_padre_a_los_hijos();
        //---------------------------------------------------------------------------------------------------
        //ITERADOR
        
        // Verifica si un dato ya esta ingresado en el arbol.
        //PRE: -
        //POST: Devuelve true si el dato ya existe en el arbol.
        bool verificar_existencia_de_la_clave(Clave clave, bool existe);
        //PRE: El dato debe existir en el arbol.
        //POST: Devuelve el dato indicado por la clave.
        Dato* devolver_dato_por_clave(Clave clave);
        //PRE: -
        //POST: Muestra todos los datos del arbol.
        int mostrar_todo(int contador);
        void cuidar_animal_individual_nodo();
        void alimentar_animales();
        void higienizar_animales();
        void modificador_hambre_higiene_animales_nodo();
        void guardar_nodo(ofstream archivo);
        //---------------------------------------------------------------------------------------------------
        //ELIMINADORES
        
        //"Elimina" un dato del arbol, aunque en realidad solamente lo oculta.
        //PRE: El dato debe existir en el arbol.
        //POST: Le modifica el valor del dato existe del dato.
        void baja(Clave clave);
        //Destructor
        ~Nodo();
};


#endif