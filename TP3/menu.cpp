#include "menu.hpp"

using namespace std;


void mostrar_menu_principal(){
    cout<<endl<<endl<< endl;
    cout<<"MENU DE MANEJO DE RESERVA DE ANIMALES"<<endl<<endl<<endl
    <<"1) Listar animales rescatados."<<endl<<endl
    <<"2) Rescatar animal."<<endl<<endl
    <<"3) Buscar animal." <<endl<<endl
    <<"4) Cuidar animales."<<endl<<endl
    <<"5) Adoptar animal."<<endl<<endl
    <<"6) Cargar combustible."<<endl<<endl
    <<"7) Guardar y salir."<<endl<<endl;
}


int pedir_opcion(int cantidad_opciones){
    int opcion_elegida;
    cout<<endl<<"Ingrese el numero de la opcion elegida: ";
    cin>>opcion_elegida;

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
        //reserva->modificador_hambre_higiene_animales();
        break;
    case RESCATAR_ANIMAL:
        reserva->rescatar_animal();
        //reserva->modificador_hambre_higiene_animales();
        break;
    case CARGAR_COMBUSTIBLE:
        reserva->cargar_combustible();
    case BUSCAR_ANIMAL:
        reserva->buscar_animal();
        //reserva->modificador_hambre_higiene_animales();
        break;
    
    case CUIDAR_ANIMAL:
        reserva->cuidar_animales();
        //reserva->modificador_hambre_higiene_animales();
        break;
    /*
    case ADOPTAR_ANIMAL:
        reserva->adoptar_animal();
        reserva->modificador_hambre_higiene_animales();
        break;
        */
    }
}