#include <iostream>
#include "menu.hpp"

using namespace std;


int main(){
    int opcion;
    Reserva* reserva = new Reserva();
    mostrar_menu_principal();
    opcion = pedir_opcion(6);
    while(opcion != 6){
        system("clear");
        ejecutar_opcion_principal(reserva, opcion);
        mostrar_menu_principal();
        opcion = pedir_opcion(6);
    }
    reserva->guardar();
    delete reserva->obtener_lista();
    reserva->~Reserva();
    return 0;
}