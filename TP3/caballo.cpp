#include "caballo.hpp"


Caballo::Caballo(string nombre, int edad, string tamanio, char especie, string personalidad){
    this->nombre = nombre;
    this->edad = edad;
    this->tamanio = tamanio;
    this->especie = especie;
    this->personalidad = personalidad;
    hambre = 0;
    higiene = 100;
    existe = true;
    escapado = false;
}


void Caballo::modificador_hambre_higiene(){
    if(hambre < 100 && hambre >= 0) hambre += modificador_alimento_personalidad();
    if(higiene <= 100 && higiene > 0) higiene -= modificador_higiene_personalidad();
}


void Caballo::alimentar(){
    hambre = 0;
    cout<<nombre<<" comio manzanas."<<endl;
}



void Caballo::higienizar(){
    higiene = 100;
}
   

void Caballo::mostrar(){
    cout<<" Nombre: "<<nombre
    <<" Edad: "<<edad
    <<" Tamanio: "<<tamanio
    <<" Especie: Caballo"
    <<" Personalidad: "<<personalidad<<endl
    <<" Nivel de Hambre: "<<hambre
    <<" Nivel de Higiene: "<<higiene<<endl;
}


void Caballo::mostrar(bool mostrar_adoptado){
    cout<<" Nombre: "<<nombre
    <<" Edad: "<<edad
    <<" Tamanio: "<<tamanio
    <<" Especie: Caballo"
    <<" Personalidad: "<<personalidad<<endl
    <<" Nivel de Hambre: "<<hambre
    <<" Nivel de Higiene: "<<higiene<<endl;
    if (escapado) cout<<" ESCAPADO"<<endl;
    else if (!existe) cout<<" ADOPTADO"<<endl;
    else cout<<endl;
} 