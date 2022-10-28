#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include "perro.hpp"
#include "caballo.hpp"
#include "conejo.hpp"
#include "erizo.hpp"
#include "gato.hpp"
#include "lagartija.hpp"
#include "roedor.hpp"

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
        //POST: Devuelve la edad del animal.
        int obtener_edad();
        //PRE: -
        //POST: Devuelve el tamanio del animal.
        string obtener_tamanio();
        //PRE: -
        //POST: Devuelve la especie del animal.
        char obtener_especie();
        //PRE: -
        //POST: Devuelve la especie del animal.
        string obtener_especie_full();
        //PRE: -
        //POST: Devuelve la personalidad del animal.
        string obtener_personalidad();
        //PRE: -
        //POST: Devuelve el hambre del animal.
        int obtener_hambre();
        //PRE: -
        //POST: Devuelve la higiene del animal.
        int obtener_higiene();
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

//PRE: El animal debe ser uno de los posibles.
//POST: Crea el animal correspondiente y lo devuelve para cargarlo a la lista.
Animal* creador_animal(string nombre, int edad, string tamanio, char especie, string personalidad);

#endif //ANIMAL_HPP