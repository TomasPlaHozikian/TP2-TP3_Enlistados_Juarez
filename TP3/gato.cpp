#include "gato.hpp"


Gato::Gato(string nombre, int edad, string tamanio, char especie, string personalidad){
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


void Gato::mostrar(){
    cout<<" Nombre: "<<nombre
    <<" Edad: "<<edad
    <<" Tamanio: "<<tamanio
    <<" Especie: Gato"
    <<" Personalidad: "<<personalidad<<endl
    <<" Nivel de Hambre: "<<hambre
    <<" Nivel de Higiene: "<<higiene<<endl;
}


void Gato::mostrar(bool mostrar_adoptado){
    cout<<" Nombre: "<<nombre
    <<" Edad: "<<edad
    <<" Tamanio: "<<tamanio
    <<" Especie: Gato"
    <<" Personalidad: "<<personalidad<<endl
    <<" Nivel de Hambre: "<<hambre
    <<" Nivel de Higiene: "<<higiene<<endl;
    if (escapado) cout<<" ESCAPADO"<<endl;
    else if (!existe) cout<<" ADOPTADO"<<endl;
    else cout<<endl;
} 
