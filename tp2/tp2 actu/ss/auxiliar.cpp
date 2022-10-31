#include "auxiliar.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

string ARCHIVO_RESERVA = "Reserva.csv";

void cargar_lista(Lista* lista){
    ifstream archivo_reserva(ARCHIVO_RESERVA);

    if(!archivo_reserva.is_open()){
        cout << "No se encontro el archivo \"" << ARCHIVO_RESERVA << "\", se creo el archivo" << endl;
        archivo_reserva.open(ARCHIVO_RESERVA, ios::out);
        archivo_reserva.close();
        archivo_reserva.open(ARCHIVO_RESERVA, ios::in);
    }

    string nombre, tamanio, personalidad, aux1, aux2, aux3, aux4;
    char especie;
    int edad, posicion;

    while (getline(archivo_reserva, nombre, ','))
    {
        getline(archivo_reserva, aux1, ',');
        edad=stoi(aux1);
        getline(archivo_reserva, aux2, ',');
        tamanio=correccion_mayusculas(aux2);
        getline(archivo_reserva, aux3, ',');
        especie=aux3[0];
        getline(archivo_reserva, aux4);
        personalidad=correccion_mayusculas(aux4);

        Animal* animal = new Animal(nombre,edad,tamanio,especie,personalidad);
        posicion = lista->obtener_cantidad() + 1;   
        lista->alta(animal, posicion);
    }
}

string correccion_mayusculas(string palabra){
    string resultado="";
    char letra_correjida=toupper(palabra[0]);
    int tamanio_palabra=palabra.length();

    resultado=resultado+letra_correjida;
    for (int i = 1; i < tamanio_palabra; i++)
    {
        letra_correjida=tolower(palabra[i]);
        resultado=resultado+letra_correjida;
    }

    return resultado;
}

int pedir_edad(){
    string ingreso, limpio;
    int edad, i, tamanio_ingreso;
    bool es_numero, valido=false, cambio;

    while (!valido)
    {  
        es_numero=true;
        i=0;
        limpio="";
        ingreso="";
        cambio=false;

        cout<<"Ingrese la edad del animal: ";
        getline(cin>>ws,ingreso);
        tamanio_ingreso=ingreso.length();
        while (i<tamanio_ingreso && es_numero==true)
        {
            if (ingreso[i]!=' ' && !isdigit(ingreso[i]))
            {
                es_numero=false;
            }
            else if (isdigit(ingreso[i]))
            {
                limpio=limpio+ingreso[i];
                cambio=true;
            }
            i++;
        }

        if (es_numero && cambio)
        {
            edad=stoi(limpio);
            if (edad>=0 && edad<=100)
            {
                valido=true;
            }
        }

        if (!es_numero || !valido)
        {
            cout<<"La edad ingresada es invalida, recuerde que debe ser un numero entero entre 0 y 100."<<endl;
        }
    }
    return edad;
}

string pedir_tamanio(){
    string tamanio,ingreso;
    
    cout<<"Ingrese el tamanio del animal: ";
    getline(cin>>ws,ingreso);
    tamanio=correccion_mayusculas(ingreso);

    while (tamanio != "Diminuto" && tamanio != "Pequenio" && tamanio != "Mediano" && tamanio != "Grande" && tamanio != "Gigante")
    {
        cout<<"El tamanio ingresado no es valido, si quiere saber la lista de tamanios ingrese 1"<<endl
        <<"Ingrese el tamanio del animal: ";
        getline(cin>>ws,ingreso);
        tamanio=correccion_mayusculas(ingreso);

        if (tamanio == "1")
        {
            mostrar_tamanios();
            cout<<"Ingrese el tamanio del animal: ";
            getline(cin>>ws,ingreso);
            tamanio=correccion_mayusculas(ingreso);
        }
    }
    return tamanio;
}

void mostrar_tamanios(){
    cout << "TAMANIOS" << endl
    << '\t' << "Diminuto" << endl
    << '\t' << "Pequenio" << endl
    << '\t' << "Mediano" << endl
    << '\t' << "Grande" << endl
    << '\t' << "Gigante" << endl;
}

char pedir_especie(){
    string ingreso;
    int tamanio_ingreso;
    char especie;

    cout<<"Ingrese la especie del animal: ";
    getline(cin>>ws,ingreso);
    tamanio_ingreso=ingreso.length();
    especie=char(toupper(ingreso[0]));

    while ((especie != 'P' && especie != 'G' && especie != 'C' && especie != 'R' && especie != 'O' && especie != 'E' && especie != 'L') || tamanio_ingreso!=1)
    {
        cout<<"La especie ingresada no es valida, si quiere saber la lista de especies ingrese 1"<<endl;
        cout<<"Ingrese la especie del animal: ";
        getline(cin>>ws,ingreso);
        tamanio_ingreso=ingreso.length();
        especie=char(toupper(ingreso[0]));

        if (especie == '1')
        {
            mostrar_especies();
            cout<<"Ingrese la especie del animal: ";
            getline(cin>>ws,ingreso);
            tamanio_ingreso=ingreso.length();
            especie=char(toupper(ingreso[0]));
        }
    }
    return especie;
}

void mostrar_especies(){
    cout << "ESPECIES" << endl
    << '\t' << "P. Perro." << endl
    << '\t' << "G. Gato." << endl
    << '\t' << "C. Caballo." << endl
    << '\t' << "R. Roedor." << endl
    << '\t' << "O. Conejo." << endl
    << '\t' << "E. Erizo." << endl
    << '\t' << "L. Lagartija." << endl;
}

string pedir_personalidad(){
    string tamanio,ingreso;
    
    cout<<"Ingrese la personalidad del animal: ";
    getline(cin>>ws,ingreso);
    tamanio=correccion_mayusculas(ingreso);

    while (tamanio != "Dormilon" && tamanio != "Jugueton" && tamanio != "Sociable" && tamanio != "Travieso")
    {
        cout<<"La personalidad ingresada no es valida, si quiere saber la lista de personalidades ingrese 1"<<endl
        <<"Ingrese la personalidad del animal: ";
        getline(cin>>ws,ingreso);
        tamanio=correccion_mayusculas(ingreso);

        if (tamanio == "1")
        {
            mostrar_personalidades();
            cout<<"Ingrese la personalidad del animal: ";
            getline(cin>>ws,ingreso);
            tamanio=correccion_mayusculas(ingreso);
        }
    }
    return tamanio;
}

void mostrar_personalidades(){
    cout << "PERSONALIDADES" << endl
    << '\t' << "Dormilon" << endl
    << '\t' << "Jugueton" << endl
    << '\t' << "Sociable" << endl
    << '\t' << "Travieso" << endl;
}