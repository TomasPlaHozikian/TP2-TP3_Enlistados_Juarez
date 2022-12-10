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


bool ejecutar_opcion_principal(Reserva* reserva, int opcion){
    bool terminar = false;
    switch (opcion)
    {
    case LISTAR_ANIMALES:
        reserva->listar_animales();
        reserva->modificador_hambre_higiene_animales();
        break;
    case RESCATAR_ANIMAL:
        reserva->rescatar_animal();
        reserva->modificador_hambre_higiene_animales();
        break;
    case CARGAR_COMBUSTIBLE:
        reserva->cargar_combustible();
        break;
    case BUSCAR_ANIMAL:
        reserva->buscar_animal();
        reserva->modificador_hambre_higiene_animales();
        break;
    
    case CUIDAR_ANIMAL:
        reserva->cuidar_animales();
        reserva->modificador_hambre_higiene_animales();
        break;
    case ADOPTAR_ANIMAL:
        reserva->adoptar_animal();
        reserva->modificador_hambre_higiene_animales();
        break;
    default: cout<<"Ha finalizado el programa."<<endl;
    }
    if (reserva->obtener_escapados() >= 3)
    {
        cout<<"Su partida se termino porque se escaparon 3 o mas animales."<<endl;
        terminar = true;
    }
    return terminar;
}