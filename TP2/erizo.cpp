#include "erizo.hpp"


Erizo::Erizo(string nombre, int edad, string tamanio, char especie, string personalidad){
    this->nombre = nombre;
    this->edad = edad;
    this->tamanio = tamanio;
    this->especie = especie;
    this->personalidad = personalidad;
}


void Erizo::modificador_hambre_higiene(){
    hambre += 10*modificador_alimento_personalidad();
    higiene -= 10*modificador_higiene_personalidad();
}

void Erizo::alimentar(){
    hambre = 0;
    cout<<nombre<<" comio insectos."<<endl;
}

void Erizo::higienizar(){
    higiene = 100;
    }