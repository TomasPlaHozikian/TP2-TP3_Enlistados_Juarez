#ifndef ERIZO_HPP
#define ERIZO_HPP

#include "animal.hpp"


class Erizo : public Animal{
    public:
        Erizo(string nombre, int edad, string tamanio, char especie, string personalidad);
        void modificador_hambre_higiene();
        void alimentar();
        void higienizar();
        void mostrar();
        void mostrar(bool mostrar_adoptado);
};


#endif //ERIZO_HPP