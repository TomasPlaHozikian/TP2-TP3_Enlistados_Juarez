#ifndef LAGARTIJA_HPP
#define LAGARTIJA_HPP

#include "animal.hpp"

class Lagartija : public animal{
    public:
        Lagartija(string nombre, int edad, string tamanio, char especie, string personalidad);
        void modificador_hambre_higiene();
        void mostrar();
        void alimento();
        void higiene();
};

#endif //LAGARTIJA_HPP