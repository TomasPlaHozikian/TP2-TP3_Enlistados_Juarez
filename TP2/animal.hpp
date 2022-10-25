#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
using namespace std;

class Animal{
    protected:
        string nombre;
        int edad;
        string tamanio;
        char especie;
        string personalidad;
        int hambre;
        int higiene;
    public:
        //PRE: -
        //POST: Inicializa animal con los parametros indicados.
        Animal(){};
        //PRE: -
        //POST: Devuelve el nombre del animal.
        string obtener_nombre();
        //PRE: -
        //POST: Modifica el hambre e higiene en base a los datos del animal.
        virtual void modificador_hambre_higiene();
        //PRE: -
        //POST: Muestra todos los datos del animal.
        void mostrar();
        //PRE: -
        //POST: Actualiza el nivel de hambre de animal al ser alimentado.
        virtual void alimentar();
        //PRE: - 
        //POST: Actualiza el nivel de higiene del animal al ser baniado.
        virtual void higienizar();
        //PRE: -
        //POST: Devuelve un float que sera usado como multiplicador para aumentar el hambre en base a personalidad.
        int modificador_alimento_personalidad();
        //PRE: -
        //POST: Devuelve un float que sera usado como multiplicador para reducir la higiene en base a personalidad.
        int modificador_higiene_personalidad();
};

#endif //ANIMAL_HPP