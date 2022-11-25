#include "nodoarbol.hpp"


Nodo::Nodo(Dato* d){
    clave1 = d;
    clave2 = 0;
    padre = 0;
    hijo_izquierdo = 0;
    hijo_medio = 0;
    hijo_derecho = 0;
}


Dato* Nodo::obtener_clave1(){
    return clave1;
}


Dato* Nodo::obtener_clave2(){
    return clave2;
}


void Nodo::cambiar_clave1(Dato* nuevo){
    clave1 = nuevo;
}


void Nodo::eliminar_clave2(){
    clave2 = 0;
}


void Nodo::eliminar_hijo_izquierdo(){
    hijo_izquierdo = 0;
}


void Nodo::eliminar_hijo_medio(){
    hijo_medio = 0;
}


void Nodo::eliminar_hijo_derecho(){
    hijo_derecho = 0;
}


bool Nodo::hay_izquierdo(){
    return  hijo_izquierdo != 0;
}


bool Nodo::hay_derecho(){
    return  hijo_derecho != 0;
}


bool Nodo::hay_medio(){
    return  hijo_medio != 0;
}


bool Nodo::hay_padre(){
    return padre != 0;
}


bool Nodo::hay_clave2(){
    return  clave2 != 0;
}


void Nodo::asignar_padre(Nodo* padre_nuevo){
    padre = padre_nuevo;
}


Nodo* Nodo::obtener_izquierdo(){
    return hijo_izquierdo;
}


Nodo* Nodo::obtener_derecho(){
    return hijo_derecho;
}


Nodo* Nodo::obtener_medio(){
    return hijo_medio;
}


Nodo* Nodo::obtener_padre(){
    return padre;
}


void Nodo::asignar_clave1(Dato* nueva_clave1){
    clave1 = nueva_clave1;
}


void Nodo::asignar_clave2(Dato* nueva_clave2){
    clave2 = nueva_clave2;
}



void Nodo::asignar_hijo_derecho(Nodo* hijo_derecho_nuevo){
    hijo_derecho = hijo_derecho_nuevo;
}


void Nodo::asignar_hijo_medio(Nodo* hijo_medio_nuevo){
    hijo_medio = hijo_medio_nuevo;
}


void Nodo::asignar_hijo_izquierdo(Nodo* hijo_izquierdo_nuevo){
    hijo_izquierdo = hijo_izquierdo_nuevo;
}


void Nodo::crear_hijos(Animal* izquierdo, Animal* medio, Animal* derecho){
    hijo_izquierdo = new Nodo(izquierdo);
    hijo_medio = new Nodo(derecho);
    clave1 = medio;
    hijo_izquierdo->asignar_padre(this);
    hijo_medio->asignar_padre(this);
    clave2 = 0;
}


void Nodo::derivar_agregar_a_hijos(Dato* nuevo){
    if (!hay_clave2())
    {
        if (clave1->obtener_nombre() > nuevo->obtener_nombre())
        {
            hijo_izquierdo->agregar(nuevo);
        }
        else hijo_derecho->agregar(nuevo);
    }
    else
    {
        if (clave1->obtener_nombre() > nuevo->obtener_nombre())
        {
            hijo_izquierdo->agregar(nuevo);
        }
        else if (clave1->obtener_nombre() < nuevo->obtener_nombre() && nuevo->obtener_nombre()< clave2->obtener_nombre())
        {
            hijo_medio->agregar(nuevo);
        }
        else
        {
            hijo_derecho->agregar(nuevo);
        }
    }
}


void Nodo::agregar_clave2(Animal* clave_nueva){
    if (clave1->obtener_nombre() > clave_nueva->obtener_nombre()) {
            clave2 = clave1;
            clave1 = clave_nueva;
        }
        else clave2 = clave_nueva;
}


void Nodo::agregar_clave_a_padre(Animal* medio, Nodo* nodo_izquierdo, Nodo* nodo_derecho){
    //Si no tiene nodo padre
    if (!nodo_izquierdo->hay_padre())
    {
        Nodo* padre_nuevo = new Nodo(medio);
        nodo_izquierdo->asignar_padre(padre_nuevo);
        padre_nuevo->asignar_hijo_izquierdo(nodo_izquierdo);
        padre->asignar_hijo_medio(nodo_derecho);
    }
    //Si tiene nodo padre
    else {
        Nodo* nodo_padre = nodo_izquierdo->obtener_padre();
        //Si el nodo padre no tiene clave 2
        if (!nodo_padre->hay_clave2())
        {   
            if (nodo_padre->obtener_clave1()->obtener_nombre() < medio->obtener_nombre())
            {
                nodo_padre->agregar_clave2(medio);
                nodo_padre->asignar_hijo_derecho(nodo_derecho);
                nodo_padre->asignar_hijo_medio(nodo_izquierdo);
            }
            else
            {
                nodo_padre->agregar_clave2(medio);
                nodo_padre->asignar_hijo_derecho(nodo_padre->obtener_medio());
                nodo_padre->asignar_hijo_izquierdo(nodo_izquierdo);
                nodo_padre->asignar_hijo_medio(nodo_derecho);
            }
        }
        //Si el nodo padre tiene clave 2
        else
        {
            Dato* medio_padre;
            Nodo* nuevo_nodo;
            if (nodo_padre->obtener_clave1()->obtener_nombre() > medio->obtener_nombre())
            {
                nodo_padre->eliminar_hijo_izquierdo();
                medio_padre = nodo_padre->obtener_clave1();
                nodo_padre->asignar_clave1(medio);
                nuevo_nodo = new Nodo(nodo_padre->obtener_clave2());
                nuevo_nodo->asignar_hijo_medio(nodo_padre->obtener_derecho());
                nuevo_nodo->asignar_hijo_izquierdo(nodo_padre->obtener_medio());
                nodo_padre->eliminar_clave2();
                nodo_padre->eliminar_hijo_derecho();
                nodo_padre->asignar_hijo_medio(nodo_derecho);
                nodo_padre->asignar_hijo_izquierdo(nodo_izquierdo);
                agregar_clave_a_padre(medio_padre, nodo_padre, nuevo_nodo);
            }
            else if (nodo_padre->obtener_clave1()->obtener_nombre() < medio->obtener_nombre() && medio->obtener_nombre()< nodo_padre->obtener_clave2()->obtener_nombre())
            {
                nodo_padre->eliminar_hijo_medio();
                nuevo_nodo = new Nodo(nodo_padre->obtener_clave2());
                nuevo_nodo->asignar_hijo_medio(nodo_padre->obtener_derecho());
                nuevo_nodo->asignar_hijo_izquierdo(nodo_derecho);
                nodo_padre->eliminar_clave2();
                nodo_padre->eliminar_hijo_derecho();
                nodo_padre->asignar_hijo_medio(nodo_izquierdo);
                agregar_clave_a_padre(medio, nodo_padre, nuevo_nodo);
            }
            else
            {
                medio_padre = nodo_padre->obtener_clave2();
                nodo_padre->asignar_clave2(medio);
                nuevo_nodo = new Nodo(nodo_padre->obtener_clave2());
                nuevo_nodo->asignar_hijo_medio(nodo_derecho);
                nuevo_nodo->asignar_hijo_izquierdo(nodo_izquierdo);
                nodo_padre->eliminar_clave2();
                nodo_padre->eliminar_hijo_derecho();
                agregar_clave_a_padre(medio_padre, nodo_padre, nuevo_nodo);
            }
        } 
    }
}


void Nodo::agregar(Dato* nuevo){
    //Si tiene hijos
    if (hay_medio())
    {
        derivar_agregar_a_hijos(nuevo);
    }
    //Si no tiene clave2 ni hijos
    else if (!hay_clave2())
    {
        agregar_clave2(nuevo);
    }
    //Si tiene clave2 pero no hijos
    else 
    {
        Dato* medio;
        Nodo* nuevo_nodo;
        if (clave1->obtener_nombre() > nuevo->obtener_nombre())
        {
            medio = clave1;
            clave1 = nuevo;
            nuevo_nodo = dividir_nodo();
            agregar_clave_a_padre(medio, this, nuevo_nodo);
        }
        else if (clave1->obtener_nombre() < nuevo->obtener_nombre() && nuevo->obtener_nombre()< clave2->obtener_nombre())
        {
            nuevo_nodo = dividir_nodo();
            eliminar_clave2();
            agregar_clave_a_padre(nuevo, this, nuevo_nodo);
        }
        else
        {
            medio = clave2;
            clave2 = nuevo;
            nuevo_nodo = dividir_nodo();
            agregar_clave_a_padre(medio, this, nuevo_nodo);
        }
    }
}

Nodo* Nodo::dividir_nodo(){
    Dato* clave_nuevo_nodo = clave2;
    Nodo* nuevo_nodo_derecho = new Nodo(clave_nuevo_nodo);
    clave2 = 0;
    return nuevo_nodo_derecho;
}

bool Nodo::verificar_existencia_de_la_clave(Clave clave){
    bool existe = false;
    if (clave1->obtener_nombre() == clave && clave1->obtener_existencia()) existe = true;
    else if (!hay_clave2())
    {
        if (clave1->obtener_nombre() > clave) existe = hijo_izquierdo->verificar_existencia_de_la_clave(clave);
        else existe = hijo_medio->verificar_existencia_de_la_clave(clave);
    }
    else
    {
        if (clave2->obtener_nombre() == clave && clave1->obtener_existencia()) existe = true;
        else if (clave1->obtener_nombre() > clave) existe = hijo_izquierdo->verificar_existencia_de_la_clave(clave);
        else if (clave1->obtener_nombre() < clave && clave < clave2->obtener_nombre()) existe = hijo_medio->verificar_existencia_de_la_clave(clave);
        else existe = hijo_derecho->verificar_existencia_de_la_clave(clave);
    }
    return existe;
}


void Nodo::baja(Clave clave){
    if (clave1->obtener_nombre() == clave) clave1->eliminar_existencia();
    else if (!hay_clave2())
    {
        if (clave1->obtener_nombre() > clave) hijo_izquierdo->baja(clave);
        else hijo_medio->baja(clave);
    }
    else
    {
        if (clave2->obtener_nombre() == clave) clave1->eliminar_existencia();
        else if (clave1->obtener_nombre() > clave) hijo_izquierdo->baja(clave);
        else if (clave1->obtener_nombre() < clave && clave < clave2->obtener_nombre()) hijo_medio->baja(clave);
        else hijo_derecho->baja(clave);
    }
}


Dato* Nodo::devolver_dato_por_clave(Clave clave){
    Dato* dato_buscado;
    if (clave1->obtener_nombre() == clave) dato_buscado = clave1;
    else if (!hay_clave2())
    {
        if (clave1->obtener_nombre() > clave) dato_buscado = hijo_izquierdo->devolver_dato_por_clave(clave);
        else dato_buscado = hijo_medio->devolver_dato_por_clave(clave);
    }
    else
    {
        if (clave2->obtener_nombre() == clave) dato_buscado = clave2;
        else if (clave1->obtener_nombre() > clave) dato_buscado = hijo_izquierdo->devolver_dato_por_clave(clave);
        else if (clave1->obtener_nombre() < clave && clave < clave2->obtener_nombre()) dato_buscado = hijo_medio->devolver_dato_por_clave(clave);
        else dato_buscado = hijo_derecho->devolver_dato_por_clave(clave);
    }
    return dato_buscado;
}


void Nodo::mostrar_siguiente(){
    if (hay_izquierdo()){

        hijo_izquierdo->mostrar_siguiente();
        clave1->mostrar();
        hijo_medio->mostrar_siguiente();
        if(hay_derecho()){
            clave2->mostrar();
            hijo_derecho->mostrar_siguiente();
        }
    } 
    else{
        clave1->mostrar();
        if(hay_clave2()){
            clave2->mostrar();
        }
    }
}


void Nodo::eliminarse_completo(){
    if (hay_izquierdo())
    {
        hijo_izquierdo->eliminarse_completo();
        delete hijo_izquierdo;
    }
    if (hay_medio())
    {
        hijo_medio->eliminarse_completo();
        delete hijo_medio;
    }
    if (hay_derecho())
    {
        hijo_derecho->eliminarse_completo();
        delete hijo_derecho;
    }
    delete clave1;
    delete clave2;
}