#include <iostream>
#include "menu.hpp"

using namespace std;


int main(){
    int opcion;
    bool terminar = false;
    Reserva* reserva = new Reserva();
    opcion = 1;
    while(opcion != 7 && !terminar){
        //system("clear");
        mostrar_menu_principal();
        opcion = pedir_opcion(7);
        terminar = ejecutar_opcion_principal(reserva, opcion);
    }

    reserva->guardar();
    reserva->~Reserva();
    return 0;
}