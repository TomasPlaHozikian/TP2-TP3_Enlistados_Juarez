#include <iostream>
#include "reserva_animales.hpp"
#include "menu.hpp"

using namespace std;

int main()
{
    Lista* lista = new Lista();
    Reserva* reserva = new Reserva(lista);
    cargar_lista_reserva(reserva);
    mostrar_menu();
    int opcion=pedir_opcion();
    ejecutar_opcion(reserva,opcion);
    return 0;
}