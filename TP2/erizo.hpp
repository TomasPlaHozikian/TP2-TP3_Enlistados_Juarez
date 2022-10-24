#ifndef ERIZO_HPP
#define ERIZO_HPP

#include "animal.hpp"

class Erizo : public animal{
    public:
        Erizo(string nombre, int edad, string tamanio, char especie, string personalidad);
        void modificador_hambre_higiene();
        void mostrar();
        void alimento();
        void higiene();
};

#endif //ERIZO_HPP