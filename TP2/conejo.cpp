#include "conejo.hpp"


Conejo::Conejo(string nombre, int edad, string tamanio, char especie, string personalidad){
    this->nombre = nombre;
    this->edad = edad;
    this->tamanio = tamanio;
    this->especie = especie;
    this->personalidad = personalidad;
    hambre = 0;
    higiene = 100;
}


void Conejo::modificador_hambre_higiene(){
    hambre += 10*modificador_alimento_personalidad();
    higiene -= 10*modificador_higiene_personalidad();
}

void Conejo::alimentar(){
    hambre = 0;
    cout<<nombre<<" comio lechuga."<<endl;
}

void Conejo::higienizar(){
    higiene = 100;
    }

