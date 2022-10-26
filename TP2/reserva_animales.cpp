#include "reserva_animales.hpp"
#include "auxiliar.hpp"
#include <string>
#include <iostream>

using namespace std;

Reserva::Reserva(){
    
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
        animal = new Animal(nombre,edad,tamanio,especie,personalidad);
        posicion = lista_animales->obtener_cantidad() + 1;   
        lista_animales->alta(animal, posicion);
    }   
}

void Reserva::listar_animales(){
    lista_animales->iniciar();
    while(lista_animales->hay_siguiente()){
        Animal animal = lista_animales->siguiente();
        cout<<"LISTA DE ANIMALES EN LA RESERVA"<<endl;
        cout<<"Nombre: "<<animal.obtener_nombre()<<
        "Edad: "<<animal.obtener_edad()<<
        "Tamanio: "<<animal.obtener_tamanio()<<
        "Especie: "<<animal.obtener_especie_full()<<
        "Nivel de hambre: "<<animal.obtener_hambre()<<
        "Nivel de higiene: "<<animal.obtener_higiene()<<endl;
    }
}