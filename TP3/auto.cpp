#include "auto.hpp"

Auto::Auto(){
    combustible = 100;
}

void Auto::cargar_combustible_por_accion(){
    if (combustible < 100){
        combustible += 5;
    }
    if (combustible > 100){
        combustible = 100;
    }
}

void Auto::cargar_combustible_por_cantidad(int cantidad){
    int faltante = 100 - combustible;
    combustible += cantidad;
    if (combustible > 100){
        cout << "La cantidad ingresada sobrepasa el limite de combustible" <<endl;
        cout << "Se ha llenado el tanque cargando " << faltante << " litros." <<endl;
    }
}


int Auto::obtener_combustible(){
    return combustible;
}


void Auto::consumir_combustible(int cantidad){
    combustible -= cantidad;
}


Auto::~Auto(){
    
}