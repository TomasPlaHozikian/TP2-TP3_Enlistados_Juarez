#ifndef ERIZO_HPP
#define ERIZO_HPP

#include "animal.hpp"

class Erizo : public Animal{
    public:
        Erizo(string nombre, int edad, string tamanio, char especie, string personalidad);
        void modificador_hambre_higiene();
        void alimentar();
        void higienizar();
};

#endif //ERIZO_HPP