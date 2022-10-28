#include "lagartija.hpp"


Lagartija::Lagartija(string nombre, int edad, string tamanio, char especie, string personalidad){
    this->nombre = nombre;
    this->edad = edad;
    this->tamanio = tamanio;
    this->especie = especie;
    this->personalidad = personalidad;
}


void Lagartija::modificador_hambre_higiene(){
    hambre += 10*modificador_alimento_personalidad();
}

void Lagartija::alimentar(){
    hambre = 0;
    cout<<nombre<<" comio insectos."<<endl;
}

void Lagartija::higienizar(){
    higiene = 100;//SACAR?
    }

