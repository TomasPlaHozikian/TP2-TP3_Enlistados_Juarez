#include "menu.hpp"

using namespace std;

void mostrar_menu(){
    cout << endl << endl << endl;
    cout << "MENU" << endl
    << '\t' << "1. Listar animales rescatados." << endl
    << '\t' << "2. Rescatar animal." << endl
    << '\t' << "3. Buscar animal." << endl
    << '\t' << "4. Cuidar animales." << endl
    << '\t' << "5. Adoptar animal." << endl
    << '\t' << "6. Guardar y salir." << endl;
}

int pedir_opcion(){
    int opcion_elegida;
    cout << "Ingrese el numero de la opcion elegida: ";
    cin >> opcion_elegida;

    while(opcion_elegida < 1 || opcion_elegida > 6){
        cout << "La opcion elegida no es una opcion valida, por favor ingrese otra opcion: ";
        cin >> opcion_elegida;
    }

    return opcion_elegida;
}

void ejecutar_opcion(Reserva* reserva, int opcion){
    switch (opcion)
    {
    case LISTAR_ANIMALES:
        reserva->listar_animales();
        break;
    
    case RESCATAR_ANIMAL:
        reserva->rescatar_animal();
        break;
    
    case BUSCAR_ANIMAL:
        
        break;

    case CUIDAR_ANIMAL:
            
        break;

    case ADOPTAR_ANIMAL:
        
        break;
    
    case SALIR:
        
        break;
    }
}