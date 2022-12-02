#include "nodoarbol.hpp"


Nodo::Nodo(Dato* d){
    clave1 = d;
    clave2 = 0;
    padre = 0;
    hijo_izquierdo = 0;
    hijo_medio = 0;
    hijo_derecho = 0;
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


void Nodo::asignar_padre(Nodo* padre_nuevo){
    padre = padre_nuevo;
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


Dato* Nodo::obtener_clave1(){
    return clave1;
}


Dato* Nodo::obtener_clave2(){
    return clave2;
}


bool Nodo::hay_clave2(){
    return  clave2 != 0;
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


bool Nodo::hay_hijo_izquierdo(){
    return  hijo_izquierdo != 0;
}


bool Nodo::hay_hijo_derecho(){
    return  hijo_derecho != 0;
}


bool Nodo::hay_hijo_medio(){
    return  hijo_medio != 0;
}


bool Nodo::hay_padre(){
    return padre != 0;
}


void Nodo::agregar(Dato* nuevo){
    if (hay_hijo_medio()) derivar_agregar_a_hijos(nuevo);
    else if (!hay_clave2()) agregar_clave2(nuevo);
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
        else if (clave1->obtener_nombre() < nuevo->obtener_nombre() && nuevo->obtener_nombre() < clave2->obtener_nombre())
        {
            nuevo_nodo = dividir_nodo();
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


void Nodo::derivar_agregar_a_hijos(Dato* nuevo){
    if (clave1->obtener_nombre() > nuevo->obtener_nombre()) hijo_izquierdo->agregar(nuevo);
    else
    {
        if (!hay_clave2()) hijo_medio->agregar(nuevo);
        else 
        {
            if (nuevo->obtener_nombre() < clave2->obtener_nombre()) hijo_medio->agregar(nuevo);
            else hijo_derecho->agregar(nuevo);
        }
    }
}


void Nodo::agregar_clave2(Animal* clave_nueva){
    if (clave1->obtener_nombre() > clave_nueva->obtener_nombre()) 
    {
        clave2 = clave1;
        clave1 = clave_nueva;
    }
    else clave2 = clave_nueva;
}


void Nodo::agregar_clave_a_padre(Animal* medio, Nodo* nodo_izquierdo, Nodo* nodo_derecho){
    if (!nodo_izquierdo->hay_padre())
    {
        Nodo* padre_nuevo = new Nodo(medio);
        padre_nuevo->asignar_hijo_izquierdo(nodo_izquierdo);
        padre_nuevo->asignar_hijo_medio(nodo_derecho);
        padre_nuevo->asignar_padre_a_los_hijos();
    }
    else {
        Nodo* nodo_padre = nodo_izquierdo->obtener_padre();
        if (!nodo_padre->hay_clave2())
        {
            if (nodo_padre->obtener_clave1()->obtener_nombre() > medio->obtener_nombre())
            {
                nodo_padre->agregar_clave2(medio);
                nodo_padre->asignar_hijo_derecho(nodo_padre->obtener_medio());
                nodo_padre->asignar_hijo_izquierdo(nodo_izquierdo);
                nodo_padre->asignar_hijo_medio(nodo_derecho);
                nodo_padre->asignar_padre_a_los_hijos();
            }
            else
            {
                nodo_padre->agregar_clave2(medio);
                nodo_padre->asignar_hijo_derecho(nodo_derecho);
                nodo_padre->asignar_hijo_medio(nodo_izquierdo);
                nodo_padre->asignar_padre_a_los_hijos();
            }
        }
        else
        {
            Dato* medio_padre;
            Nodo* nuevo_nodo;
            if (nodo_padre->obtener_clave1()->obtener_nombre() > medio->obtener_nombre())
            {
                nodo_padre->eliminar_hijo_izquierdo();
                medio_padre = nodo_padre->obtener_clave1();
                nodo_padre->asignar_clave1(medio);
                nuevo_nodo = nodo_padre->dividir_nodo();
                nuevo_nodo->asignar_hijo_medio(nodo_padre->obtener_derecho());
                nuevo_nodo->asignar_hijo_izquierdo(nodo_padre->obtener_medio());
                nuevo_nodo->asignar_padre_a_los_hijos();
                nodo_padre->eliminar_hijo_derecho();
                nodo_padre->asignar_hijo_medio(nodo_derecho);
                nodo_padre->asignar_hijo_izquierdo(nodo_izquierdo);
                nodo_padre->asignar_padre_a_los_hijos();
                nodo_padre->agregar_clave_a_padre(medio_padre, nodo_padre, nuevo_nodo);
            }
            else if (nodo_padre->obtener_clave1()->obtener_nombre() < medio->obtener_nombre() && medio->obtener_nombre()< nodo_padre->obtener_clave2()->obtener_nombre())
            {
                nodo_padre->eliminar_hijo_medio();
                nuevo_nodo = new Nodo(nodo_padre->obtener_clave2());
                nuevo_nodo->asignar_hijo_medio(nodo_padre->obtener_derecho());
                nuevo_nodo->asignar_hijo_izquierdo(nodo_derecho);
                nuevo_nodo->asignar_padre_a_los_hijos();
                nodo_padre->eliminar_clave2();
                nodo_padre->eliminar_hijo_derecho();
                nodo_padre->asignar_hijo_medio(nodo_izquierdo);
                nodo_padre->asignar_padre_a_los_hijos();
                agregar_clave_a_padre(medio, nodo_padre, nuevo_nodo);
            }
            else
            {
                medio_padre = nodo_padre->obtener_clave2();
                nodo_padre->asignar_clave2(medio);
                nuevo_nodo = new Nodo(nodo_padre->obtener_clave2());
                nuevo_nodo->asignar_hijo_medio(nodo_derecho);
                nuevo_nodo->asignar_hijo_izquierdo(nodo_izquierdo);
                nuevo_nodo->asignar_padre_a_los_hijos();
                nodo_padre->eliminar_clave2();
                nodo_padre->eliminar_hijo_derecho();
                agregar_clave_a_padre(medio_padre, nodo_padre, nuevo_nodo);
            }
        } 
    }
}


Nodo* Nodo::dividir_nodo(){
    Dato* clave_nuevo_nodo = clave2;
    Nodo* nuevo_nodo_derecho = new Nodo(clave_nuevo_nodo);
    nuevo_nodo_derecho->asignar_padre(obtener_padre());
    clave2 = 0;
    return nuevo_nodo_derecho;
}


void Nodo::asignar_padre_a_los_hijos(){
    hijo_izquierdo->asignar_padre(this);
    hijo_medio->asignar_padre(this);
    if (hay_hijo_derecho()) hijo_derecho->asignar_padre(this);
}


bool Nodo::verificar_existencia_de_la_clave(Clave clave, bool existe){
    if (!existe && clave == clave1->obtener_nombre()) existe = true;
    else if (!existe && hay_clave2()) if (clave == clave2->obtener_nombre()) existe = true;
    else if (!existe && hay_hijo_medio())
    {
        if (!existe && clave < clave1->obtener_nombre()) existe = hijo_izquierdo->verificar_existencia_de_la_clave(clave, existe);
        else if (hay_clave2()) 
        {
            if (clave < clave2->obtener_nombre()) existe = hijo_medio->verificar_existencia_de_la_clave(clave, existe);
            else existe = hijo_derecho->verificar_existencia_de_la_clave(clave, existe);
        }
        else existe = hijo_medio->verificar_existencia_de_la_clave(clave, existe);
    }
    return existe;
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


int Nodo::mostrar_todo(int contador){
    if (hay_hijo_izquierdo()) contador = hijo_izquierdo->mostrar_todo(contador);
    if (clave1->obtener_existencia())
    {
        cout<<contador<<")";
        clave1->mostrar();
        contador ++;
    }
    if (hay_hijo_medio()) contador = hijo_medio->mostrar_todo(contador);
    if (hay_clave2() && clave2->obtener_existencia())
    {
        cout<<contador<<")";
        clave2->mostrar();
        contador ++;
    }
    if (hay_hijo_derecho()) contador = hijo_derecho->mostrar_todo(contador);
    return contador;
}


void Nodo::cuidar_animal_individual_nodo(){
    if (hay_hijo_izquierdo()) hijo_izquierdo->cuidar_animal_individual_nodo();
    if (clave1->obtener_existencia()) clave1->cuidar_animal();
    if (hay_hijo_medio()) hijo_medio->cuidar_animal_individual_nodo();
    if (hay_clave2()) if (clave2->obtener_existencia()) clave2->cuidar_animal();
    if (hay_hijo_derecho()) hijo_derecho->cuidar_animal_individual_nodo();
}


void Nodo::alimentar_animales(){
    if (hay_hijo_izquierdo()) hijo_izquierdo->alimentar_animales();
    if (clave1->obtener_existencia()) clave1->alimentar();
    if (hay_hijo_medio()) hijo_medio->alimentar_animales();
    if (hay_clave2()) if (clave2->obtener_existencia()) clave2->alimentar();
    if (hay_hijo_derecho()) hijo_derecho->alimentar_animales();
}


void Nodo::higienizar_animales(){
    if (hay_hijo_izquierdo()) hijo_izquierdo->higienizar_animales();
    if (clave1->obtener_existencia()) clave1->higienizar();
    if (hay_hijo_medio()) hijo_medio->higienizar_animales();
    if (hay_clave2()) if (clave2->obtener_existencia()) clave2->higienizar();
    if (hay_hijo_derecho()) hijo_derecho->higienizar_animales();
}


void Nodo::modificador_hambre_higiene_animales_nodo(){
    if (hay_hijo_izquierdo()) hijo_izquierdo->modificador_hambre_higiene_animales_nodo();
    if (clave1->obtener_existencia()) clave1->modificador_hambre_higiene();
    if (hay_hijo_medio()) hijo_medio->modificador_hambre_higiene_animales_nodo();
    if (hay_clave2()) if (clave2->obtener_existencia()) clave2->modificador_hambre_higiene();
    if (hay_hijo_derecho()) hijo_derecho->modificador_hambre_higiene_animales_nodo();
}


void Nodo::guardar_nodo(ofstream archivo){
    if (hay_hijo_izquierdo()) hijo_izquierdo->guardar_nodo(archivo);
    if (clave1->obtener_existencia()) clave1->guardar(archivo);
    if (hay_hijo_medio()) hijo_medio->guardar_nodo(archivo);
    if (hay_clave2()) if (clave2->obtener_existencia()) clave2->guardar(archivo);
    if (hay_hijo_derecho()) hijo_derecho->guardar_nodo(archivo);
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


Nodo::~Nodo(){
    if (hay_hijo_izquierdo()) delete hijo_izquierdo;
    if (hay_hijo_medio()) delete hijo_medio;
    if (hay_hijo_derecho()) delete hijo_derecho;
    delete clave1;
    delete clave2;
}