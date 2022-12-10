#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class Animal{
    protected:
        string nombre;
        int edad;
        string tamanio;
        char especie;
        string personalidad;
        int hambre;
        int higiene;
        bool existe, escapado;
    public:
        //PRE: -
        //POST: Inicializa animal con los parametros indicados.
        Animal(){};
        //PRE: -
        //POST: Devuelve el nombre del animal.
        string obtener_nombre();
        //PRE: -
        //POST: Perminte cambiar el nombre del animal.
        void cambiar_nombre(string nombre);
        //PRE: -
        //POST: Devuelve la edad del animal.
        int obtener_edad();
        //PRE: -
        //POST: Devuelve el tamanio del animal.
        string obtener_tamanio();
        //PRE: -
        //POST: Devuelve la especie del animal.
        char obtener_especie();
        //PRE: -
        //POST: Devuelve true si el animal existe, false si no.
        bool obtener_existencia();
        //PRE: -
        //POST: Marca al animal como no existente.
        void eliminar_existencia();
        //PRE: -
        //POST: Marca al animal como escapado.
        void animal_escapado();
        //PRE: -
        //POST: Devuelve la especie del animal.
        string obtener_especie_full();
        //PRE: -
        //POST: Devuelve la personalidad del animal.
        string obtener_personalidad();
        //PRE: -
        //POST: Devuelve el hambre del animal.
        int obtener_hambre();
        //PRE: -
        //POST: Devuelve la higiene del animal.
        int obtener_higiene();
        //PRE: -
        //POST: Modifica el hambre e higiene en base a los datos del animal.
        virtual void modificador_hambre_higiene() = 0;
        //PRE: -
        //POST: Muestra todos los datos del animal.
        virtual void mostrar() = 0;
        //PRE: -
        //POST: Muestra todos los datos del animal, incluyendo si fue adoptado o no.
        virtual void mostrar(bool mostrar_adoptado) = 0;
        //PRE: -
        //POST: Actualiza el nivel de hambre de animal al ser alimentado.
        virtual void alimentar() = 0;
        //PRE: - 
        //POST: Actualiza el nivel de higiene del animal al ser baniado.
        virtual void higienizar() = 0;
        //PRE: -
        //POST: Devuelve un float que sera usado como multiplicador para aumentar el hambre en base a personalidad.
        int modificador_alimento_personalidad();
        //PRE: -
        //POST: Devuelve un float que sera usado como multiplicador para reducir la higiene en base a personalidad.
        int modificador_higiene_personalidad();
        //PRE: -
        //POST: Permite al usuario interactuar con el animal para alimentarlo y/o higienizarlo.
        void cuidar_animal();
        //PRE: -
        //POST: Muesta los datos del animal dependiendo de su tamaño.
        int mostrar_adopciones_posibles(int espacio_disponible, int contador);
        //PRE: -
        //POST: Guarda los animales en el archivo csv y termina el programa.
        void guardar(ofstream &archivo);
        //PRE: -
        //POST: Borra el animal.
        virtual ~Animal();
};


#endif //ANIMAL_HPP