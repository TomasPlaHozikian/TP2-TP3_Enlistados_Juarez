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
    lista_animales->iniciar();
    while(lista_animales->hay_siguiente()){
        Animal* animal = lista_animales->siguiente();
        cout<<"LISTA DE ANIMALES EN LA RESERVA"<<endl;
        cout<<"Nombre: "<<animal->obtener_nombre()<<
        "Edad: "<<animal->obtener_edad()<<
        "Tamanio: "<<animal->obtener_tamanio()<<
        "Especie: "<<animal->obtener_especie_full()<<
        "Nivel de hambre: "<<animal->obtener_hambre()<<
        "Nivel de higiene: "<<animal->obtener_higiene()<<endl;
    }
}