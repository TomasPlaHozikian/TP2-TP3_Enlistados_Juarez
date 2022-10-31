#ifndef ROEDOR_HPP
#define ROEDOR_HPP

#include "animal.hpp"

class Roedor : public Animal{
    public:
        Roedor(string nombre, int edad, string tamanio, char especie, string personalidad);
        void modificador_hambre_higiene();
        void alimentar();
        void higienizar();
};

#endif //ROEDOR_HPP