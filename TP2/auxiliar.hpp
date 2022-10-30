#ifndef AUXILIAR_HPP
#define AUXILIAR_HPP

#include "animal.hpp"
#include "lista.hpp"
#include "perro.hpp"
#include "caballo.hpp"
#include "conejo.hpp"
#include "erizo.hpp"
#include "gato.hpp"
#include "lagartija.hpp"
#include "roedor.hpp"

using namespace std;



//PRE: -
//POST: Convierte un string a minusculas con la primera en mayusculas para hacer mas facil su manejo en el programa.
string correccion_mayusculas(string palabra);
//PRE: -
//POST: Valida que la edad ingresada este entre 0 y 100, y lo devuelve.
int pedir_edad();
//PRE: -
//POST: Valida que el tamanio ingresado este entre las opciones validas y lo devuelve.
string pedir_tamanio();
//PRE: -
//POST: Muestra la lista de tamanios validos.
void mostrar_tamanios();
//PRE: -
//POST: Valida que la especie ingresada este entre las opciones validas y la devuelve.
char pedir_especie();
//PRE: -
//POST: Muestra la lista de especies validas.
void mostrar_especies();
//PRE: -
//POST: Valida que la personalidad ingresadada este entre las opciones validas y la devuelve.
string pedir_personalidad();
//PRE: -
//POST: Muestra la lista de personalidades validas.
void mostrar_personalidades();
//PRE: -
//POST: Verifica si existe un animal ya guardado con ese nombre, si existe el animal devuelve true.
bool existe_animal(Lista* lista, string nombre);
//PRE: El animal debe ser uno de los posibles.
//POST: Crea el animal correspondiente y lo devuelve para cargarlo a la lista.
Animal* creador_animal(string nombre, int edad, string tamanio, char especie, string personalidad);
//PRE: Que el espacio disponible sea un entero positivo
//POST: Muestra la lista de todos los animales que el usuario puede adoptar segun su espacio disponible.
void mostrar_adopciones_posibles(int espacio_disponible, Lista* lista_animales);
//PRE: El nombre debe ser un nombre valido de un animal en la lista.
//POST: Devuelve la posicion en la lista de dicho animal.
int obtener_posicion_animal(Lista* lista, string nombre, int i);
//PRE: -
//POST: Devuelve si el usuario decidio adoptar un animal listado, o cancelar esta opcion.
int adoptar_o_cancelar();

#endif