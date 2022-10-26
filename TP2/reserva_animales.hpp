#ifndef RESERVA_ANIMALES_HPP
#define RESERVA_ANIMALES_HPP

#include "lista.hpp"

class Reserva
{
private:
    Lista* lista_animales;
public:
    //PRE: -
    //POST: Se agregan los animales y sus datos en forma de clases a una lista.
    Reserva();
    //PRE: -
    //POST: Imprime todos los animales con sus datos y se modifica el hambre e higiene de los mismos.
    void listar_animales();
    //PRE: No debe existir el nombre del animal en la lista.
    //POST: Se le piden los datos del animal al usuario, se validan y se agrega el animal a la lista.
    void rescatar_animal();
    //PRE: Debe existir el nombre del animal en la lista.
    //POST: Se muestra la informacion del animal buscado por el usuario.
    void buscar_animal(string nombre);
    //PRE: -
    /*POST: Muestra un menu con opciones (elegir individualmente, alimentar a todos, banar a todos y regresar al inicio)
    y ejecuta la opcion seleccionada por el usuario*/
    void cuidar_animales();
    //PRE: -
    /*POST: Muestra opcion para adoptar animales en base al espacio disponible para el mismo, luego se muestran
    los animales dentro del parametro para que el usuario seleccione un animal y si desea adoptarlo se remueve de la lista*/
    void adoptar_animal();
    //PRE: -
    //POST: Se guarda el archivo animales.csv con las modificaciones realizadas y se cierra el programa.
    void guardar_y_salir();
    //PRE: -
    //POST: Elimina la lista con los animales y sus datos.
    ~Reserva();
};

#endif //RESERVA_ANIMALES_HPP