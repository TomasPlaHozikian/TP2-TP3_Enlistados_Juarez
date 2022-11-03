#ifndef CABALLO_HPP
#define CABALLO_HPP

#include "animal.hpp"


class Caballo : public Animal{
    public:
        Caballo(string nombre, int edad, string tamanio, char especie, string personalidad);
        void modificador_hambre_higiene();
        void alimentar();
        void higienizar();
};


#endif //CABALLO_HPP