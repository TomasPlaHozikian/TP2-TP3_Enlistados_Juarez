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
    cout<<"Nombre: "<<nombre
    <<"Edad: "<<edad
    <<"Tamanio: "<<tamanio
    <<"Especie: "<<especie
    <<"Personalidad: "<<personalidad<<endl;
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
