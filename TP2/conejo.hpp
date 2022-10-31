#ifndef CONEJO_HPP
#define CONEJO_HPP

#include "animal.hpp"

class Conejo : public Animal{
    public:
        Conejo(string nombre, int edad, string tamanio, char especie, string personalidad);
        void modificador_hambre_higiene();
        void alimentar();
        void higienizar();
};

#endif //CONEJO_HPP