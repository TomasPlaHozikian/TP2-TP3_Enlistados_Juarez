#ifndef CONEJO_HPP
#define CONEJO_HPP

#include "animal.hpp"


class Conejo : public Animal{
    public:
        Conejo(string nombre, int edad, string tamanio, char especie, string personalidad);
        void modificador_hambre_higiene();
        void alimentar();
        void higienizar();
        void mostrar();
        void mostrar(bool mostrar_adoptado);
};


#endif //CONEJO_HPP