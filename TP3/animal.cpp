#include "animal.hpp"
#include <string>


string Animal::obtener_nombre(){
    return nombre;
}


int Animal::obtener_edad(){
    return edad;
}


string Animal::obtener_tamanio(){
    return tamanio;
}


char Animal::obtener_especie(){
    return especie;
}


bool Animal::obtener_existencia(){
    return existe;
}


void Animal::eliminar_existencia(){
    existe = false;
}


string Animal::obtener_especie_full(){
    string especie_full;
    if(especie == 'O') especie_full = "Conejo";
    if(especie == 'C') especie_full = "Caballo";
    if(especie == 'P') especie_full = "Perro";
    if(especie == 'G') especie_full = "Gato";
    if(especie == 'R') especie_full = "Roedor";
    if(especie == 'L') especie_full = "Lagartija";
    if(especie == 'E') especie_full = "Erizo";
    return especie_full;
}


string Animal::obtener_personalidad(){
    return personalidad;
}


int Animal::obtener_hambre(){
    return hambre;
}


int Animal::obtener_higiene(){
    return higiene;
}


void Animal::mostrar(){
    cout<<" Nombre: "<<nombre
    <<" Edad: "<<edad
    <<" Tamanio: "<<tamanio
    <<" Especie: "<<obtener_especie_full()
    <<" Personalidad: "<<personalidad<<endl
    <<" Nivel de Hambre: "<<hambre
    <<" Nivel de Higiene: "<<higiene<<endl<<endl;
}


int Animal::modificador_alimento_personalidad(){
    int modificador = 10;
    if(personalidad == "Dormilon") modificador = 5;
    if(personalidad == "Jugueton") modificador = 20;
    return modificador;
}


int Animal::modificador_higiene_personalidad(){
    int modificador = 10;
    if(personalidad == "Sociable") modificador = 5;
    if(personalidad == "Travieso") modificador = 20;
    return modificador;
}


void Animal::cuidar_animal(){
    int opcion_de_animal = 0;
    while (opcion_de_animal != 3)
    {
        mostrar();
        cout<<"Seleccione opcion de cuidado: "<<endl
        <<"1) Baniar"<<endl<<"2) Alimentar"<<endl<<"3) Saltear"<<endl;
        cin>>opcion_de_animal;
        switch(opcion_de_animal)
        {
        case(1):
            higienizar();
            break;
        case(2):                    
            alimentar();
            break;
        case(3):
            cout<<"Se salteo al animal"<<endl;
            break;
        default: cout<<"No entendi, recuerde que su respuesta debe ser 1, 2 o 3."<<endl;
        }
    }
}


int Animal::mostrar_adopciones_posibles(int espacio_disponible, int contador){
    if (espacio_disponible <= 10){
        if (tamanio == "Pequenio"){
            cout<<contador<<")";
            mostrar();
            contador ++;
        } 
        else if (espacio_disponible <= 2 && tamanio == "Diminuto"){
            cout<<contador<<")";
            mostrar();
            contador ++;
        }
    }
    if (espacio_disponible >= 10){
        if (tamanio == "Mediano"){
            cout<<contador<<")";
            mostrar();
            contador ++;
        } 
        else if (espacio_disponible >= 20 && tamanio == "Grande"){
            cout<<contador<<")";
            mostrar();
            contador ++;
        }
        else if (espacio_disponible >= 50 && tamanio == "Gigante"){
            cout<<contador<<")";
            mostrar();
            contador ++;
        }
    }
    return contador;
}


void Animal::guardar(ofstream &archivo){
    archivo << nombre <<','
            <<edad<<','
            <<tamanio<<','
            <<especie<<','
            <<personalidad<<endl;
}


Animal::~Animal(){

}