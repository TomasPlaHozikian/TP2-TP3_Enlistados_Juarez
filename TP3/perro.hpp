#ifndef PERRO_HPP
#define PERRO_HPP

#include "animal.hpp"


class Perro : public Animal{
    public:
        Perro(string nombre, int edad, string tamanio, char especie, string personalidad);
        void modificador_hambre_higiene();
        void alimentar();
        void higienizar();
        void mostrar();
        void mostrar(bool mostrar_adoptado);
};


#endif //PERRO_HPP