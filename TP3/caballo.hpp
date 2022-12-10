#ifndef CABALLO_HPP
#define CABALLO_HPP

#include "animal.hpp"


class Caballo : public Animal{
    public:
        Caballo(string nombre, int edad, string tamanio, char especie, string personalidad);
        void modificador_hambre_higiene();
        void alimentar();
        void higienizar();
        void mostrar();
        void mostrar(bool mostrar_adoptado);
};


#endif //CABALLO_HPP