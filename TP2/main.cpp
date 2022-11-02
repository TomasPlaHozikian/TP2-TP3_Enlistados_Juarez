#include <iostream>
#include "menu.hpp"

using namespace std;

int main(){
    int opcion;
    Reserva* reserva = new Reserva();
    mostrar_menu_principal();
    opcion = pedir_opcion(6);
    while(opcion != 6){
        ejecutar_opcion_principal(reserva, opcion);
        mostrar_menu_principal();
        opcion = pedir_opcion(6);
    }
    reserva->guardar_y_salir();
    reserva->~Reserva();
    return 0;
}