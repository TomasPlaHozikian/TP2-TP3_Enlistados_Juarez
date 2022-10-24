#ifndef PERRO_HPP
#define PERRO_HPP

#include "animal.hpp"

class Perro : public animal{
    public:
        Perro(string nombre, int edad, string tamanio, char especie, string personalidad);
        void modificador_hambre_higiene();
        void mostrar();
        void alimento();
        void higiene();
};

#endif //PERRO_HPP