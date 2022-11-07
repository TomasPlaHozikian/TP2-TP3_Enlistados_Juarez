#include "lagartija.hpp"


Lagartija::Lagartija(string nombre, int edad, string tamanio, char especie, string personalidad) {
    this->nombre = nombre;
    this->edad = edad;
    this->tamanio = tamanio;
    this->especie = especie;
    this->personalidad = personalidad;
    hambre = 0;
    higiene = 100;
}


void Lagartija::modificador_hambre_higiene() {
    if (hambre < 100 && hambre >= 0) hambre += modificador_alimento_personalidad();
}


void Lagartija::alimentar() {
    hambre = 0;
    cout<<nombre<<" comio insectos."<<endl;
}


void Lagartija::higienizar() {
    higiene = 100;
    cout<<nombre<<" no requiere ducha."<<endl;
    }
    
