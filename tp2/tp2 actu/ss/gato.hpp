#ifndef GATO_HPP
#define GATO_HPP

#include "animal.hpp"

class Gato : public Animal{
    public:
        Gato(string nombre, int edad, string tamanio, char especie, string personalidad);
        void modificador_hambre_higiene();
        void mostrar();
        void alimento();
        void higiene();
};

#endif //GATO_HPP