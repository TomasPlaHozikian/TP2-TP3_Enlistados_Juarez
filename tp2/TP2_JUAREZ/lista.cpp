#include "lista.h"

Lista::Lista(){
    primero = 0;
    cantidad = 0;
    actual = primero;
}

Nodo* Lista::obtener_nodo(int pos){
    Nodo* aux = primero;
    for(int i = 1; i < pos; i++){
        aux = aux->obtener_siguiente();
    }
    return aux;
}

void Lista::alta(Dato d, int pos){
    Nodo* nuevo = new Nodo(d);
    Nodo* siguiente = primero;
    if(pos == 1){
        primero = nuevo;
    }
    else{  
        Nodo* anterior = obtener_nodo(pos-1);
        siguiente = anterior->obtener_siguiente();
        anterior->cambiar_siguiente(nuevo);
    }
    nuevo->cambiar_siguiente(siguiente);
    cantidad++;
    }


Dato Lista::consulta(int pos){
    Nodo* nodo = obtener_nodo(pos);
    return nodo->obtener_dato();
}

void Lista::baja(int pos){
    Nodo* borrar = primero;
    if(pos == 1){
        primero = borrar->obtener_siguiente();
    } 
    else{
        Nodo* anterior = obtener_nodo(pos - 1);
        borrar = anterior->obtener_siguiente();
    }
    delete borrar;
    cantidad--;
}


bool Lista::vacia(){
    return (primero == 0);
}


int Lista::obtener_cantidad(){
    return cantidad;
}

//ITERADOR
bool Lista::hay_siguiente(){
    return actual != 0;
}

Dato Lista::siguiente(){
    Dato dato = actual->obtener_dato();
    actual = actual->obtener_siguiente();
    return dato;
}

void Lista::iniciar(){
    actual = primero;
}

Lista::~Lista(){
    while (! vacia())
        baja(1);
}
//**************************EJERCICIO LISTA*********************
void Lista::intercambio_dato(int pos1, int pos2){
    Dato dato1 = consulta(pos1);
    baja(pos1);
    Dato dato2 = consulta(pos2);
    baja(pos2);
    alta(dato2, pos1);
    alta(dato1, pos2);
}

void Lista::union_listas(Lista nueva_lista){
    int i = 0;
    nueva_lista.iniciar();
    while(nueva_lista.hay_siguiente()){
        Dato dato1 = nueva_lista.siguiente();
        alta(dato1, cantidad-1);
        cantidad++;
    }
}

Lista* Lista::union_listas_a_nueva(Lista nueva_lista){
    Lista* nueva_lista_union = &nueva_lista;
    int i = 0;
    iniciar();
    while(hay_siguiente()){
        Dato dato = siguiente();
        nueva_lista.alta(dato, i);
        i++;
    }
    return nueva_lista_union;
}

void Lista::invertir_lista(){
    int i = cantidad - 1;
    Dato dato_fin;
    Dato dato_inicio;
for(int x = 0; x < i; x++){
    dato_inicio = consulta(x);
    baja(x);
    dato_fin = consulta(i);
    baja(i);
    alta(dato_fin, x);
    alta(dato_inicio, i);
    i--;
}
}

Lista* Lista::invertir_lista_nueva(Lista lista_nueva){
    Lista lista_nueva_aux = lista_nueva;
    Lista* lista_nueva_invertida = &lista_nueva_aux;
    lista_nueva_aux.invertir_lista();
    return lista_nueva_invertida;
}

void Lista::union_listas_ordenada_sin_repetidos(Lista nueva_lista){
    nueva_lista.iniciar();
    
}