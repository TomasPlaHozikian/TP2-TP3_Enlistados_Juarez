#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include <fstream>

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
        bool existe;
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
        bool obtener_existencia();
        void eliminar_existencia();
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
        virtual void modificador_hambre_higiene() = 0;
        //PRE: -
        //POST: Muestra todos los datos del animal.
        void mostrar();
        //PRE: -
        //POST: Actualiza el nivel de hambre de animal al ser alimentado.
        virtual void alimentar() = 0;
        //PRE: - 
        //POST: Actualiza el nivel de higiene del animal al ser baniado.
        virtual void higienizar() = 0;
        //PRE: -
        //POST: Devuelve un float que sera usado como multiplicador para aumentar el hambre en base a personalidad.
        int modificador_alimento_personalidad();
        //PRE: -
        //POST: Devuelve un float que sera usado como multiplicador para reducir la higiene en base a personalidad.
        int modificador_higiene_personalidad();
        void cuidar_animal();
        void guardar(ofstream archivo);
        virtual ~Animal();
};


#endif //ANIMAL_HPP