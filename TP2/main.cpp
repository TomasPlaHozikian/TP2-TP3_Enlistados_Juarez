#include <iostream>
#include "menu.hpp"

using namespace std;

int main()
{
    Reserva* reserva = new Reserva();
    mostrar_menu_principal();
    int opcion = pedir_opcion(6);
    ejecutar_opcion_principal(reserva, opcion);
    return 0;
}