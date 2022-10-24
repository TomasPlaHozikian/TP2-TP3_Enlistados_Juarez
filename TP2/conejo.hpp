#ifndef CONEJO_HPP
#define CONEJO_HPP

#include "animal.hpp"

class Conejo : public animal{
    public:
        Conejo(string nombre, int edad, string tamanio, char especie, string personalidad);
        void modificador_hambre_higiene();
        void mostrar();
        void alimento();
        void higiene();
};

#endif //CONEJO_HPP