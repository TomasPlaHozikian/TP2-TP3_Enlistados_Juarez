#include "reserva_animales.hpp"
#include <string>
#include <iostream>

using namespace std;


Reserva::Reserva(){
    arbol_animales = new Arbol();
    auto1 = new Auto();
    cargar_arbol_reserva();
}


Arbol* Reserva::obtener_arbol(){
    return arbol_animales;
}


void Reserva::cargar_arbol_reserva(){
    ifstream archivo_reserva("Reserva.csv");

    if(!archivo_reserva.is_open()){
        cout << "No se encontro el archivo \"" << "Reserva.csv" << "\", se creo el archivo" << endl;
        archivo_reserva.open("Reserva.csv", ios::out);
        archivo_reserva.close();
        archivo_reserva.open("Reserva.csv", ios::in);
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
        arbol_animales->alta(animal);
    }
    archivo_reserva.close();
}


void Reserva::listar_animales(){
    arbol_animales->obtener_raiz()->mostrar_todo(1);
}


void Reserva::rescatar_animal(){
    Animal* animal;
    string nombre, tamanio, personalidad;
    bool ya_existe=false, terminar=false;
    char especie;
    int edad, posicion;

    cout<<"Ingrese el nombre del animal: ";
    cin>>nombre;
    nombre = correccion_mayusculas(nombre);
    
    ya_existe = arbol_animales->existe(nombre);

    while (ya_existe && !terminar)
    {
        cout<<"Ya existe un animal rescatado con ese nombre:"<<endl;
        mostrar_animal_por_nombre(nombre);
        cout<<endl<<"Si quiere ingrese otro nombre, en caso contrario ingrese 1: ";
        cin>>nombre;
        nombre = correccion_mayusculas(nombre);

        ya_existe = arbol_animales->existe(nombre);

        if (nombre == "1") terminar = true;
    }
    
    if (!terminar)
    {
        edad=pedir_edad();
        tamanio=pedir_tamanio();
        especie=pedir_especie();
        personalidad=pedir_personalidad();
        animal = creador_animal(nombre,edad,tamanio,especie,personalidad);   
        arbol_animales->alta(animal);
    }   
}


void Reserva::buscar_animal(){
    string ingreso, nombre;
    bool ya_existe=false;

    cout<<"Ingrese el nombre del animal: ";
    cin>>nombre;

    nombre = correccion_mayusculas(nombre); 

    ya_existe = arbol_animales->existe(nombre);

    while(!ya_existe){
        cout << "El nombre no existe." << endl << "Ingrese otro nombre: " << endl;
        cin>>nombre; 
        nombre = correccion_mayusculas(nombre);

        ya_existe = arbol_animales->existe(nombre);
    }
    cout<<endl;
    mostrar_animal_por_nombre(nombre);
}


void Reserva::mostrar_animal_por_nombre(string nombre){
    Animal* animal = arbol_animales->obtener_raiz()->devolver_dato_por_clave(nombre);
    animal->mostrar();
}


void Reserva::cuidar_animal_individual(){
    arbol_animales->obtener_raiz()->cuidar_animal_individual_nodo();
}


void Reserva::alimentar_animales(){
    arbol_animales->obtener_raiz()->alimentar_animales();
}


void Reserva::higienizar_animales(){
    arbol_animales->obtener_raiz()->higienizar_animales();
}


void Reserva::cuidar_animales(){
    int opcion = 0;
    while(opcion != 4){
        cout <<endl<<endl;
        cout<<"Eliga opcion: "<<endl
        <<"1) Elegir individualmente"<<endl
        <<"2) Alimentar a todos"<<endl
        <<"3) Baniar a todos"<<endl
        <<"4) Regresar a inicio"<<endl<<endl;
        cin>>opcion;
        switch(opcion)
        {
            case(1):
                cuidar_animal_individual();
                break;
            case(2):
                alimentar_animales();
                break;
            case(3):
                higienizar_animales();
                break;
            default: cout<<"No entendi, recuerde que su respuesta debe ser 1, 2, 3 o 4."<<endl;
        }
    }
}

/*
void Reserva::adoptar_animal(){
    int espacio_disponible, opcion_elegida;
    string espacio;
    
    cout << "Ingresar tamanio disponible para el animal en metros cuadrados: " << endl;
    getline(cin>>ws,espacio);
    espacio_disponible = stoi(espacio);
    
    while (espacio_disponible <= 0){
        cout << "El tamanio ingresado es invalido." << endl << "Ingresar tamanio disponible para el animal en metros cuadrados: " << endl;
        cin >> espacio_disponible;
    }
    
    mostrar_adopciones_posibles(espacio_disponible, lista_animales);
    cout<<endl<<endl;
    opcion_elegida = adoptar_o_cancelar();

    if (opcion_elegida == 2){
        cout << "Opcion cancelada, no se ha adoptado ningun animal."<< endl;
    }

    else{
        string nombre, ingreso;
        bool existe = false;
        int pos;
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

        pos = obtener_posicion_animal(lista_animales, nombre);
        lista_animales->baja(pos);
    }
}
*/

void Reserva::modificador_hambre_higiene_animales(){
    arbol_animales->obtener_raiz()->modificador_hambre_higiene_animales_nodo();
}


void Reserva::guardar(){
    ofstream archivo("Reserva.csv");
    
    archivo.close();
}



void Reserva::cargar_combustible(){
    int cantidad = 0;
    if(auto1->obtener_combustible() == 100){
        cout<<"El auto ya tiene el tanque lleno"<<endl;
    }
    else{
        cout << "Ingrese la cantidad de combustible que desea cargar: ";
        cin >> cantidad;
        while (cantidad <= 0 || cantidad > 100){
            cout << "La cantidad ingresada es invalida."<<endl;
            cout << "Ingrese la cantidad de combustible que desea cargar: ";
        }
        auto1->cargar_combustible_por_cantidad(cantidad);
        }
}


Reserva::~Reserva(){
    arbol_animales->~Arbol();
}