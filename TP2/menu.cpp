#include "menu.hpp"

using namespace std;

void mostrar_menu_principal(){
    cout << endl << endl << endl;
    cout << "MENU" << endl
    << '\t' << "1. Listar animales rescatados." << endl
    << '\t' << "2. Rescatar animal." << endl
    << '\t' << "3. Buscar animal." << endl
    << '\t' << "4. Cuidar animales." << endl
    << '\t' << "5. Adoptar animal." << endl
    << '\t' << "6. Guardar y salir." << endl;
}

int pedir_opcion(int cantidad_opciones){
    int opcion_elegida;
    cout << "Ingrese el numero de la opcion elegida: ";
    cin >> opcion_elegida;

    while(opcion_elegida < 1 || opcion_elegida > cantidad_opciones){
        cout << "La opcion elegida no es una opcion valida, por favor ingrese otra opcion: ";
        cin >> opcion_elegida;
    }

    return opcion_elegida;
}

void ejecutar_opcion_principal(Reserva* reserva, int opcion){
    switch (opcion)
    {
    case LISTAR_ANIMALES:
        reserva->listar_animales();
        break;
    
    case RESCATAR_ANIMAL:
        reserva->rescatar_animal();
        break;
    
    case BUSCAR_ANIMAL:
        reserva->buscar_animal();
        break;

    case CUIDAR_ANIMAL:
        reserva->cuidar_animales();
        break;

    case ADOPTAR_ANIMAL:
        reserva->adoptar_animal();
        break;
    
    case SALIR:
        
        break;
    }
}

void mostrar_menu_cuidar(){
    cout << endl << endl << endl;
    cout << "MENU" << endl
    << '\t' << "1. Elegir individualmente." << endl
    << '\t' << "2. Alimentar a todos." << endl
    << '\t' << "3. Baniar a todos." << endl
    << '\t' << "4. Volver al menu principal." << endl;
}