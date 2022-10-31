#include "reserva_animales.hpp"
#include <string>
#include <iostream>

using namespace std;

Reserva::Reserva(){
    lista_animales=new Lista();
    cargar_lista_reserva();
}

Lista* Reserva::obtener_lista(){
    return lista_animales;
}

void Reserva::cargar_lista_reserva(){
    ifstream archivo_reserva(ARCHIVO_RESERVA);

    if(!archivo_reserva.is_open()){
        cout << "No se encontro el archivo \"" << ARCHIVO_RESERVA << "\", se creo el archivo" << endl;
        archivo_reserva.open(ARCHIVO_RESERVA, ios::out);
        archivo_reserva.close();
        archivo_reserva.open(ARCHIVO_RESERVA, ios::in);
    }

    string nombre, tamanio, personalidad, aux1, aux2, aux3, aux4, aux5;
    char especie;
    int edad, posicion;

    while (getline(archivo_reserva, aux1, ','))
    {
        nombre=correccion_mayusculas(aux1);
        getline(archivo_reserva, aux2, ',');
        edad=stoi(aux2);
        getline(archivo_reserva, aux3, ',');
        tamanio=correccion_mayusculas(aux3);
        getline(archivo_reserva, aux4, ',');
        especie=aux4[0];
        getline(archivo_reserva, aux5);
        personalidad=correccion_mayusculas(aux5);

        Animal* animal = creador_animal(nombre, edad, tamanio, especie, personalidad);
        posicion = lista_animales->obtener_cantidad() + 1;   
        lista_animales->alta(animal, posicion);
    }
}

void Reserva::rescatar_animal(){
    Animal* animal;
    string nombre, tamanio, personalidad, ingreso;
    bool ya_existe=false, terminar=false;
    char especie;
    int edad, posicion;

    cout<<"Ingrese el nombre del animal: ";
    getline(cin>>ws,ingreso);
    nombre = correccion_mayusculas(ingreso);

    ya_existe = existe_animal(lista_animales,nombre);

    while (ya_existe && !terminar)
    {
        cout<<"Ya existe un animal rescatado con ese nombre:"<<endl;
        buscar_animal(nombre);
        cout<<endl<<"Si quiere ingrese otro nombre, en caso contrario ingrese 1: ";
        getline(cin>>ws,ingreso);
        nombre = correccion_mayusculas(ingreso);

        ya_existe = existe_animal(lista_animales,nombre);

        if (nombre == "1")
        {
            terminar = true;
        }        
    }

    if (!terminar)
    {
        edad=pedir_edad();
        tamanio=pedir_tamanio();
        especie=pedir_especie();
        personalidad=pedir_personalidad();
        animal = creador_animal(nombre,edad,tamanio,especie,personalidad);
        posicion = lista_animales->obtener_cantidad() + 1;   
        lista_animales->alta(animal, posicion);
    }   
}


void Reserva::listar_animales(){
    int i = 0;
    lista_animales->iniciar();
    cout<<"LISTA DE ANIMALES EN LA RESERVA"<<endl;
    while(lista_animales->hay_siguiente()){
        Animal* animal = lista_animales->siguiente();
        cout<<i<<") Nombre: "<<animal->obtener_nombre()<<
        "Edad: "<<animal->obtener_edad()<<
        "Tamanio: "<<animal->obtener_tamanio()<<
        "Especie: "<<animal->obtener_especie_full()<<
        "Nivel de hambre: "<<animal->obtener_hambre()<<
        "Nivel de higiene: "<<animal->obtener_higiene()<<
        "Personalidad: "<<animal->obtener_personalidad()<<endl;
        i++;
    }
}

void Reserva::buscar_animal(string nombre){
    Animal* animal;
    int pos;
    string ingreso;
    bool ya_existe=false;

    cout<<"Ingrese el nombre del animal: ";
    getline(cin>>ws,ingreso);
    nombre = correccion_mayusculas(ingreso);

    ya_existe = existe_animal(lista_animales,nombre);

    while(!ya_existe){
        cout << "El nombre no existe." << endl << "Ingrese otro nombre: " << endl;
        getline(cin>>ws,ingreso);
        nombre = correccion_mayusculas(ingreso);

        ya_existe = existe_animal(lista_animales,nombre);
    }

    pos = obtener_posicion_animal(lista_animales, nombre);
    animal -> mostrar();
    
}

void Reserva::cuidar_animal_indivudal(){
    int opcion_de_animal;
    lista_animales->iniciar();
    while(lista_animales->hay_siguiente()){
        Animal* animal = lista_animales->siguiente();
        animal->mostrar();
        cout<<"Seleccione opcion de cuidado: "<<endl
        <<"1) Baniar"<<endl<<"2) Alimentar"<<endl<<"3) Saltear"<<endl;
        cin>>opcion_de_animal;
        switch(opcion_de_animal){
            case(1):
                animal->higienizar();
                break;
            case(2):                    
                animal->alimentar();
                break;
            case(3):
                cout<<"Se salteo al animal"<<endl;
                break;
            }
    }
}

void Reserva::alimentar_animales(){
    lista_animales->iniciar();
    while(lista_animales->hay_siguiente()){
        lista_animales->siguiente()->alimentar();
    }
}

void Reserva::higienizar_animales(){
    lista_animales->iniciar();
    while(lista_animales->hay_siguiente()){
        lista_animales->siguiente()->higienizar();
    }
}

void Reserva::cuidar_animales(){
    int opcion = 0;
    while(opcion != 4){
        cout<<"Eliga opcion: "<<endl
        <<"1) Elegir individualmente"<<endl
        <<"2) Alimentar a todos"<<endl
        <<"3) Baniar a todos"<<endl
        <<"4) Regresar a inicio"<<endl;
        cin>>opcion;
        switch(opcion){
            case(1):
                cuidar_animal_indivudal();
                break;
            case(2):
                alimentar_animales();
                break;
            case(3):
                higienizar_animales();
                break;
            }
        }
}

void Reserva::adoptar_animal(){
    int espacio_disponible, opcion_elegida, pos;
    
    cout << "Ingresar tamanio disponible para el animal en metros cuadrados: " << endl;
    cin >> espacio_disponible;
    
    while (espacio_disponible <= 0){
        cout << "El tamanio ingresado es invalido." << endl << "Ingresar tamanio disponible para el animal en metros cuadrados: " << endl;
        cin >> espacio_disponible;
    }
    
    mostrar_adopciones_posibles(espacio_disponible, lista_animales);

    opcion_elegida = adoptar_o_cancelar();

    if (opcion_elegida == 2){
        cout << "Opcion cancelada, no se ha adoptado ningun animal."<< endl;
    }

    else{
        string nombre, ingreso;
        bool existe = false;

        cout << "GENIAL! Ingrese el nombre del animal que desea adoptar: ";
        getline(cin>>ws,ingreso);
        nombre = correccion_mayusculas(ingreso);
        existe = existe_animal(lista_animales, nombre);

        while (!existe){
            cout << "No se encontro un animal con ese nombre, por favor vuelva a intentarlo: ";
            getline(cin>>ws,ingreso);
            nombre = correccion_mayusculas(ingreso);
            existe = existe_animal(lista_animales, nombre);
        }

        obtener_posicion_animal(lista_animales, nombre);
        lista_animales->baja(pos);
    }
}