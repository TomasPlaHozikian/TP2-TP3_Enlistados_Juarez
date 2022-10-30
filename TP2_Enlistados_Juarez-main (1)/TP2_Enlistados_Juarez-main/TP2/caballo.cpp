#include "caballo.hpp"


Caballo::Caballo(string nombre, int edad, string tamanio, char especie, string personalidad){
    this->nombre = nombre;
    this->edad = edad;
    this->tamanio = tamanio;
    this->especie = especie;
    this->personalidad = personalidad;
}


void Caballo::modificador_hambre_higiene(){
    hambre += 10*modificador_alimento_personalidad();
    higiene -= 10*modificador_higiene_personalidad();
}

void Caballo::alimentar(){
    hambre = 0;
    cout<<nombre<<" comio manzanas."<<endl;
}

void Caballo::higienizar(){
    higiene = 100;
    }
