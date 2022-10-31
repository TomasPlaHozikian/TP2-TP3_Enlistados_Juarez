#ifndef ROEDOR_HPP
#define ROEDOR_HPP

#include "animal.hpp"

class Roedor : public animal{
    public:
        Roedor(string nombre, int edad, string tamanio, char especie, string personalidad);
        void modificador_hambre_higiene();
        void mostrar();
        void alimento();
        void higiene();
};

#endif //ROEDOR_HPP