#include "gato.hpp"


Gato::Gato(string nombre, int edad, string tamanio, char especie, string personalidad){
    this->nombre = nombre;
    this->edad = edad;
    this->tamanio = tamanio;
    this->especie = especie;
    this->personalidad = personalidad;
    hambre = 0;
    higiene = 100;
}


void Gato::modificador_hambre_higiene(){
    if(hambre < 100 && hambre >= 0) hambre += modificador_alimento_personalidad();
}

void Gato::alimentar(){
    hambre = 0;
    cout<<nombre<<" comio atun."<<endl;
}

void Gato::higienizar(){
    higiene = 100;
    cout<<nombre<<" no requiere ducha."<<endl;
    }

