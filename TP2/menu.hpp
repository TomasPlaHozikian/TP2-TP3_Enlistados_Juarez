#ifndef MENU_HPP
#define MENU_HPP

#include "reserva_animales.hpp"

using namespace std;

enum OpcionMenuPrincipal {
    LISTAR_ANIMALES = 1,
    RESCATAR_ANIMAL,
    BUSCAR_ANIMAL,
    CUIDAR_ANIMAL,
    ADOPTAR_ANIMAL,
    SALIR
};

enum OpcionMenuCuidar {
    ELEGIR_INDIVIDUALMENTE = 1,
    ALIMENTAR_TODOS,
    BANIAR_TODOS,
    VOLVER_AL_PRINCIPAL
};


//PRE: -
//POST: Muestra el menu en la consola.
void mostrar_menu_principal();

//PRE: -
//POST: Devuelve una opcion valida.
int pedir_opcion(int cantidad_opciones);

//PRE: Las opciones deben estar entre 1 y 7.
//POST: Ejecuta los metodos necesarios para realizar la tarea.
void ejecutar_opcion_principal(Reserva* reserva, int opcion);

//PRE: -
//POST: Muestra el menu de cuidado en la consola.
void mostrar_menu_cuidar();

//PRE: Las opciones deben estar entre 1 y 4.
//POST: Ejecuta los metodos necesarios para realizar la tarea.
void ejecutar_opcion_cuidar(Reserva* reserva, int opcion);


#endif