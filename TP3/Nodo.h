#ifndef GRAFOS_NODO_H
#define GRAFOS_NODO_H
#include <string>

using namespace std;

template < typename Tipo >
class Nodo_l {
/*ATRIBUTOS*/
private:
    Tipo* elemento;
    Nodo_l<Tipo>* siguiente;

/*MÉTODOS*/
public:
    Nodo_l(string nombre);

    //post: devuelve el nodo siguiente.
    Nodo_l<Tipo>* obtenerSiguiente();

    //post: devuelve el nombre del nodo
    string obtenerNombre();

    //post: le asigna como siguiente el nodo recibido
    void asignarSiguiente(Nodo_l<Tipo>* siguiente);

    ~Nodo_l();
};

template<typename Tipo>
Nodo_l<Tipo>::Nodo_l(string nombre) {
    elemento = new Tipo(nombre);
    siguiente = nullptr;
}

template<typename Tipo>
Nodo_l<Tipo> *Nodo_l<Tipo>::obtenerSiguiente() {
    return siguiente;
}

template<typename Tipo>
string Nodo_l<Tipo>::obtenerNombre() {
    return elemento -> obtenerNombre();
}

template<typename Tipo>
void Nodo_l<Tipo>::asignarSiguiente(Nodo_l<Tipo> *siguiente) {
    this -> siguiente = siguiente;
}

template<typename Tipo>
Nodo_l<Tipo>::~Nodo_l() {
    delete elemento;
}


#endif //GRAFOS_NODO_H
