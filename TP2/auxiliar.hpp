#ifndef AUXILIAR_HPP
#define AUXILIAR_HPP

#include <string>
#include "lista.hpp"
#include "animal.hpp"

using namespace std;

//PRE: -
//POST: Carga la lista con todos los animales del archivo.
void cargar_lista(Lista* lista);
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

#endif