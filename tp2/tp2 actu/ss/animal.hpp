#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
using namespace std;

class Animal{
    private:
        string nombre;
        int edad;
        int tamanio;//usa funcion aux para pasar del entero al string que indica el tamanio
        char especie;
        string personalidad;
        int hambre;
        int higiene;
    public:
        //PRE: -
        //POST: Inicializa animal con los parametros indicados.
        Animal(string nombre, int edad, string tamanio, char especie, string personalidad){};
        //PRE: -
        //POST: Modifica el hambre e higiene en base a los datos del animal.
        virtual void modificador_hambre_higiene();
        //PRE: -
        //POST: Muestra todos los datos del animal.
        virtual void mostrar();
        //PRE: -
        //POST: Actualiza el nivel de hambre de animal al ser alimentado.
        virtual void alimento();
        //PRE: - 
        //POST: Actualiza el nivel de higiene del animal al ser baniado.
        virtual void higiene();
};

#endif //ANIMAL_HPP