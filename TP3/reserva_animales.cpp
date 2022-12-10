#include "reserva_animales.hpp"
#include <string>
#include <iostream>

using namespace std;


Reserva::Reserva(){
    arbol_animales = new Arbol();
    mapa = new Mapa();
    escapados = 0;
    cargar_arbol_reserva();
}


Arbol* Reserva::obtener_arbol(){
    return arbol_animales;
}


Mapa* Reserva::obtener_mapa(){
    return mapa;
}


int Reserva::obtener_escapados(){
    return escapados;
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
    int edad;

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
    if(mapa->obtener_combustible() <= 95){
        mapa->obtener_auto()->cargar_combustible_por_cantidad(5);
    }
    arbol_animales->obtener_raiz()->mostrar_todo(1);
}


void Reserva::rescatar_animal(){
    if(mapa->obtener_combustible() <= 95){
        mapa->obtener_auto()->cargar_combustible_por_cantidad(5);
    }
    
    mapa->imprimir_mapa();
    if(mapa->todos_rescatados()) return;
    mapa->mostrar_rescates();
    mapa->obtener_grafo()->usarFloyd();
    string nombre;
    bool ya_existe = false, terminar = false;
    int opcion;

    cout<<endl<<endl<<"Combustible en el auto: "<<mapa->obtener_combustible()<<endl;
    opcion = pedir_opcion(5);
    if(mapa->todos_rescatados()){
        cout<<"Todos los animales han sido rescatados"<<endl;
        return;
    }
    while(mapa->obtener_estado_animal(opcion)){
        cout<<"El animal ya fue rescatado"<<endl;
        opcion = pedir_opcion(5);
    }
    while(!mapa->suficiente_combustible(opcion)){
        cout<<"No hay suficiente combustible para llegar al animal seleccionado"<<endl;
        cout<<"Ingrese otro animal o termine la funcion con la opcion 6"<<endl;
        opcion = pedir_opcion(6);
    }
    if(opcion == 6){
        return;
    }
    Animal* animal = mapa->seleccionar_animal(opcion);
    int consumo = mapa->consumo_viaje(opcion) + mapa->consumo_viaje(opcion);
    if(consumo > mapa->obtener_combustible()){
        cout<<"No hay suficiente combustible, seleccione la opcion de cargar combustible"<<endl;
        return;
    }
    mapa->mover_auto_consumo(opcion);
    mapa->mover_auto_consumo(opcion);
    cout<<"El auto consumio "<<(mapa->obtener_grafo()->costoViaje(mapa->obtener_posicion_auto(), 
    mapa->obtener_posicion_animal(opcion)))*2<<" de combustible al rescatar al animal y volver a la reserva."<<endl;


    mapa->imprimir_recorrido(mapa->obtener_posicion_auto(), mapa->obtener_posicion_animal(opcion));
    cout<<endl<<"Nombre del animal rescatado: ";
    cin>>nombre;
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
    if (!terminar){
        mapa->marcar_rescatado(opcion);
        //animal->cambiar_nombre(nombre);
        Animal* animal1 = creador_animal(nombre, animal->obtener_edad(), animal->obtener_tamanio()
        , animal->obtener_especie(), animal->obtener_personalidad());  
        arbol_animales->alta(animal1);
    }
    
}


void Reserva::buscar_animal(){
    if(mapa->obtener_combustible() <= 95){
        mapa->obtener_auto()->cargar_combustible_por_cantidad(5);
    }
    string ingreso, nombre;
    bool ya_existe=false;

    cout<<"Ingrese el nombre del animal: ";
    cin>>nombre;

    nombre = correccion_mayusculas(nombre); 

    ya_existe = arbol_animales->existe(nombre);

    while(!ya_existe){
        cout << "No existe ningun animal con ese nombre." << endl << "Ingrese otro nombre: " << endl;
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


void Reserva::cuidar_animales(){
    if(mapa->obtener_combustible() <= 95){
        mapa->obtener_auto()->cargar_combustible_por_cantidad(5);
    }
    int opcion = 0;
    while(opcion != 2){
        cout <<endl<<endl;
        cout<<"Eliga opcion: "<<endl
        <<"1) Elegir individualmente"<<endl
        <<"2) Regresar a inicio"<<endl<<endl;
        cin>>opcion;
        switch(opcion)
        {
            case(1):
                cuidar_animal_individual();
                break;
            default: cout<<"No entendi, recuerde que su respuesta debe ser 1 o 2"<<endl;
        }
    }
}


void Reserva::adoptar_animal(){
    if(mapa->obtener_combustible() <= 95){
        mapa->obtener_auto()->cargar_combustible_por_cantidad(5);
    }
    int espacio_disponible, opcion_elegida;
    string espacio;
    
    cout << "Ingresar tamanio disponible para el animal en metros cuadrados: " << endl;
    getline(cin>>ws,espacio);
    espacio_disponible = stoi(espacio);
    
    while (espacio_disponible <= 0){
        cout << "El tamanio ingresado es invalido." << endl << "Ingresar tamanio disponible para el animal en metros cuadrados: " << endl;
        getline(cin>>ws,espacio);
        espacio_disponible = stoi(espacio);
    }
    
    arbol_animales->obtener_raiz()->mostrar_adopciones_posibles_nodo(espacio_disponible, 1);
    cout<<endl<<endl;
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
        existe = arbol_animales->existe(nombre);

        while (!existe){
            cout << "No se encontro un animal con ese nombre, por favor vuelva a intentarlo: ";
            getline(cin>>ws,ingreso);
            nombre = correccion_mayusculas(ingreso);
            existe = arbol_animales->obtener_raiz()->verificar_existencia_de_la_clave(nombre, false);
        }

        arbol_animales->baja(nombre);
    }
}


void Reserva::modificador_hambre_higiene_animales(){
    escapados += arbol_animales->obtener_raiz()->modificador_hambre_higiene_animales_nodo(0);
}


void Reserva::guardar(){
    ofstream archivo("Reserva.csv");
    arbol_animales->obtener_raiz()->guardar_nodo(archivo);
    archivo.close();
}


void Reserva::mostrar_adopciones_posibles(int espacio_disponible){
    arbol_animales->obtener_raiz()->mostrar_adopciones_posibles_nodo(espacio_disponible, 1);
}


void Reserva::cargar_combustible(){
    int cantidad = 0;
    if(mapa->obtener_auto()->obtener_combustible() == 100){
        cout<<"El auto ya tiene el tanque lleno"<<endl;
    }
    else{
        cout<<endl<<endl<<"Combustible en el auto: "<<mapa->obtener_combustible()<<endl;
        cout << "Ingrese la cantidad de combustible que desea cargar: ";
        cin >> cantidad;
        while (cantidad <= 0 || cantidad > 100){
            cout << "La cantidad ingresada es invalida."<<endl;
            cout << "Ingrese la cantidad de combustible que desea cargar: ";
        }
        mapa->obtener_auto()->cargar_combustible_por_cantidad(cantidad);
        }
}


Reserva::~Reserva(){
    arbol_animales->~Arbol();
    mapa->~Mapa();
}