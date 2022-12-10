#ifndef MAPA_HPP
#define MAPA_HPP


#include "Grafo.h"
#include "colors.h"
#include "auto.hpp"
#include "animal.hpp"
#include "perro.hpp"
#include "caballo.hpp"
#include "conejo.hpp"
#include "erizo.hpp"
#include "gato.hpp"
#include "lagartija.hpp"
#include "roedor.hpp"


/*
-Mapa 8 por 8 por el cual el auto se mueve.
-el auto comienza en la esquina superior izquierda.
-en el mapa se generan 5 animales en posiciones aleatoria(los animales seran representados con la inicial de su especie)
 y los mismos pueden ser rescatados.
-para ser rescatados el auto debe llegar a su posicion el auto solo podra hacerlo con el combustible suficiente
y utiliza camino minimo para gastar la minima cantidad de combustible para llegar al animal.
-En el mapa puede haber 4 tipos de terrenos que afectan el consumo de combustible del auto(funcion implementada
en la clase auto con el nombre consumo_combustible()), estos son:
    -Montania: costo de 5 de combustible. 
    -Precipicio: costo de 40 de combustible.
    -Camino: costo de 1 de combustible.
    -Tierra: costo de 2 de combustible.
    *Estos terrenos seran mostrados con distintos colores en consola, los colores se obtienen de colors.h,
    Montania se muestra en color BGND_BROWN_137, precipicio en color TXT_BLACK_16, camino en color TXT_LIGHT_GRAY_246,
    y tierra en color BGND_BROWN_94.
-El auto no puede moverse diagonalmente.
-Si el auto no posee suficiente conbustible para ir a un destino,
 el usuario podra elegir si realiza otra accion o se mueve a otro destino.
*/
class Mapa{
    private:
        Grafo* grafo;
        Auto* auto1;
        int cantidad_animales;
        int posicion_auto;
        Animal* animal1;
        Animal* animal2;
        Animal* animal3;
        Animal* animal4;
        Animal* animal5;
        int animal1_pos;
        int animal2_pos;
        int animal3_pos;
        int animal4_pos;
        int animal5_pos;
        bool rescatado1;
        bool rescatado2; 
        bool rescatado3;
        bool rescatado4; 
        bool rescatado5;

    public:
        //PRE: -
        //POST: Se crea el mapa y se carga el grafo con 5 animales de forma aleatoria, el auto y los terrenos.
        Mapa();
        //PRE: -
        //POST: Se asignan posiciones aleatorias a los animales.
        void asignar_pos_animales();
        //PRE: -
        //POST: Booleano que verifique que haya animal o no en la ubicacion indicada.
        bool hay_animal(int pos);
        //PRE: -
        //POST: Devuelve un animale con datos aleatorios.
        Animal* generar_animal();
        //PRE: -
        //POST: Imprime el estado del mapa en pantalla.
        void imprimir_mapa();
        //PRE: -
        //POST: Devuelve el auto.
        Auto* obtener_auto();
        //PRE: -
        //POST: Devuelve el combustible del auto.
        int obtener_combustible();
        //PRE: -
        //POST: Devuelve posicion del auto.
        int obtener_posicion_auto();
        //PRE: -
        //POST: Consume combustible del auto en base al animal que decide rescatar.
        void mover_auto_consumo(int num);
        //PRE: -
        //POST: Verifica que haya suficiente combustible para ir a la posicion indicada.
        bool suficiente_combustible(int pos);
        //PRE: -
        //POST: Imprime el recorrido del auto.
        void imprimir_recorrido(int origen, int destino);
        //PRE: -
        //POST: Muestra los posibles rescates.
        void mostrar_rescates();
        //PRE: -
        //POST: Devuelve el consumo de un viaje.
        int consumo_viaje(int num);
        //PRE: -
        //POST: Devuelve el animal seleccionado.
        Animal* seleccionar_animal(int num);
        //PRE: -
        //POST: Devuelve el grafo del mapa.
        Grafo* obtener_grafo();
        //PRE: -
        //POST: Marca a un animal como rescatado.
        void marcar_rescatado(int num);
        //PRE: -
        //POST: Devuelve el estado de un animal del mapa.
        bool obtener_estado_animal(int num);
        //PRE: -
        //POST: Verifica si todos los animales fueron rescatdos.
        bool todos_rescatados();
        //PRE: - 
        //POST: Devuelve la cantidad de animales del mapa.
        int obtener_cantidad_animales();
        //PRE: -
        //POST: Pregunta al usuario que animal desea rescatar, mueve el auto a su posicion y lo agrega a la reserva de animales.
        void rescatar_animal_con_auto();
        //PRE: -
        //POST: Devuelve la posicion de los animales.
        void obtener_posicion_animales();
        //PRE: -
        //POST: Devuelve la posicion del animal seleccionado.
        int obtener_posicion_animal(int num);
        //PRE: - 
        //POST: Destruye el mapa.
        ~Mapa();

};

#endif // MAPA_HPP