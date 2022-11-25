#ifndef AUTO_HPP
#define AUTO_HPP

#include <iostream>
#include <string>
using namespace std;

class Auto{
    private:
        int combustible;
        string terreno;
    public:
        Auto();
        //aumenta el combustible en 5, el limite es 100, el minimo es 0
        void cargar_combustible_por_accion();
        void cargar_combustible_por_cantidad(int cantidad);
        void consumo_combustible();
        int obtener_combustible();
        int modificador_terreno();
        ~Auto();
};

#endif //AUTO_HPP