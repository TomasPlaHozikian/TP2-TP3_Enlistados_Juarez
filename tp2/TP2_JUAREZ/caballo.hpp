#ifndef CABALLO_HPP
#define CABALLO_HPP

#include "animal.hpp"

class Caballo : public animal{
    public:
        Caballo(string nombre, int edad, string tamanio, char especie, string personalidad);
        void modificador_hambre_higiene();
        void mostrar();
        void alimento();
        void higiene();
};

#endif //CABALLO_HPP