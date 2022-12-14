#ifndef RESERVA_ANIMALES_HPP
#define RESERVA_ANIMALES_HPP

#include <fstream>
#include "auxiliar.hpp"


class Reserva{
private:
    Lista* lista_animales;
public:
    //PRE: -
    //POST: Se crea la reserva y su lista, y se carga esa lista con los animales del archivo.
    Reserva();
    //PRE: -
    //POST: Devuelve la lista de animales.
    Lista* obtener_lista();
    //PRE: -
    //POST: Carga la lista con todos los animales del archivo.
    void cargar_lista_reserva();
    //PRE: -
    //POST: Imprime todos los animales con sus datos y se modifica el hambre e higiene de los mismos.
    void listar_animales();
    //PRE: No debe existir el nombre del animal en la lista.
    //POST: Se le piden los datos del animal al usuario, se validan y se agrega el animal a la lista.
    void rescatar_animal();
    //PRE: Debe existir el nombre del animal en la lista.
    //POST: Se muestra la informacion del animal ingresado por parametro.
    void mostrar_animal_por_nombre(string nombre);
    //PRE: -
    //POST: Se muestra la informacion del animal buscado por el usuario.
    void buscar_animal();
    //PRE: -
    //POST: Alimenta a todos los animales.
    void alimentar_animales();
    //PRE: -
    //POST: Higieniza a todos los animales.
    void higienizar_animales();
    //PRE: -
    //POST: Solicita al usuario opciones de cuidado para un animal de forma individual.
    void cuidar_animal_individual();
    //PRE: -
    //POST: Muestra un menu con opciones (elegir individualmente, alimentar a todos, baniar a todos y regresar al inicio)
    //      y ejecuta la opcion seleccionada por el usuario
    void cuidar_animales();
    //PRE: -
    //POST: Muestra opcion para adoptar animales en base al espacio disponible para el mismo, luego se muestran
    //      los animales dentro del parametro para que el usuario seleccione un animal y si desea adoptarlo se remueve de la lista.
    void adoptar_animal();
    //PRE: -
    //POST: Modifica la higiene y hambre de los animales luego de una funcion.
    void modificador_hambre_higiene_animales();
    //PRE: -
    //POST: Se guarda el archivo animales.csv con las modificaciones realizadas y se cierra el programa.
    void guardar();
    //PRE: -
    //POST: Elimina la lista con los animales y sus datos.
    ~Reserva();
};

#endif //RESERVA_ANIMALES_HPP
