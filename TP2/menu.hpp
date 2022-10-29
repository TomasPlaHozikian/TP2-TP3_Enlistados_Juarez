#ifndef MENU_HPP
#define MENU_HPP

#include "reserva_animales.hpp"

using namespace std;

enum OpcionMenu {
    LISTAR_ANIMALES = 1,
    RESCATAR_ANIMAL,
    BUSCAR_ANIMAL,
    CUIDAR_ANIMAL,
    ADOPTAR_ANIMAL,
    SALIR
};

//Precondiciones:
//Postcondiciones: Muestra el menu en la consola.
void mostrar_menu();

//Precondiciones:
//Postcondiciones: Devuelve una opcion valida.
int pedir_opcion();

//Realiza la opcion ingresada por el usuario.
//Precondiciones: Las opciones deben estar entre 1 y 7.
//Postcondiciones: Ejecuta los metodos necesarios para realizar la tarea.
void ejecutar_opcion(Reserva* reserva, int opcion);

#endif