#ifndef LAGARTIJA_HPP
#define LAGARTIJA_HPP

#include "animal.hpp"


class Lagartija : public Animal{
    public:
        Lagartija(string nombre, int edad, string tamanio, char especie, string personalidad);
        void modificador_hambre_higiene();
        void alimentar();
        void higienizar();
        void mostrar();
        void mostrar(bool mostrar_adoptado);
};


#endif //LAGARTIJA_HPP