#ifndef MAPA_HPP
#define MAPA_HPP

#include "grafos/Grafo.h"
#include "grafos/colors.h"
#include "auto.hpp"
#include "animal.hpp"

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

    public:
        //PRE: -
        //POST: Se crea el mapa y se carga el grafo con 5 animales de forma aleatoria, el auto y los terrenos.
        Mapa();
        //PRE: -
        //POST: Imprime el estado del mapa en pantalla.
        void imprimir_mapa();
        //PRE: -
        //POST: Devuelve el grafo del mapa.
        Grafo* obtener_grafo();
        //PRE: -
        //POST: Devuelve el auto del mapa.
        //Auto* obtener_auto();
        //PRE: - 
        //POST: Devuelve la cantidad de animales del mapa.
        int obtener_cantidad_animales();
        //PRE: -
        //POST: Pregunta al usuario que animal desea rescatar, mueve el auto a su posicion y lo agrega a la reserva de animales.
        void rescatar_animal_con_auto();
        //PRE: -
        //POST: Muestra los posibles animales para rescatar.
        void mostrar_animales_para_rescatar();
        //PRE: - 
        //POST: Destruye el mapa.
        ~Mapa();

};

#endif // MAPA_HPP