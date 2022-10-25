#include "animal.hpp"

string Animal::obtener_nombre(){
    return nombre;
}

void Animal::mostrar(){
    cout<<"Nombre: "<<nombre<<"Edad: "<<edad<<"Tamanio: "<<tamanio<<"Especie: "<<especie<<
    "Personalidad: "<<personalidad<<endl;
}

int Animal::modificador_alimento_personalidad(){
    float modificador = 1;
    if(this->personalidad == "Dormilon") modificador = 0.5;
    if(this->personalidad == "Jugueton") modificador = 2;
    return modificador;
}

int Animal::modificador_higiene_personalidad(){
    float modificador = 1;
    if(this->personalidad == "Sociable") modificador = 0.5;
    if(this->personalidad == "Travieso") modificador = 2;
    return modificador;
}