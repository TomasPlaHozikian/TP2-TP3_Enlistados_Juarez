#include <iostream>
#include "reserva_animales.hpp"
#include "menu.hpp"

using namespace std;

int main()
{
    Reserva* reserva = new Reserva();
    mostrar_menu_principal();
    int opcion=pedir_opcion(CANTIDAD_OPCIONES_MENU_PRINCIPAL);
    ejecutar_opcion_principal(reserva,opcion);
    return 0;
}