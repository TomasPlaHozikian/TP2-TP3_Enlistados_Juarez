#include <iostream>
#include "menu.hpp"

using namespace std;


int main(){
    int opcion;
    Reserva* reserva = new Reserva();
    mostrar_menu_principal();
    opcion = pedir_opcion(7);
    while(opcion != 7){
        //system("clear");
        ejecutar_opcion_principal(reserva, opcion);
        mostrar_menu_principal();
        opcion = pedir_opcion(7);
    }
    //reserva->guardar();
    delete reserva->obtener_arbol();
    reserva->~Reserva();
    return 0;
}