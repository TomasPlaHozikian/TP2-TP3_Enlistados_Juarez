#include "auxiliar.hpp"

using namespace std;


string correccion_mayusculas(string palabra) {
    string resultado = "";
    char letra_correjida = char(toupper(palabra[0]));
    long unsigned int tamanio_palabra = palabra.length();
    resultado=resultado+letra_correjida;
    for (long unsigned int i = 1; i < tamanio_palabra; i++) {
        letra_correjida = char(tolower(palabra[i]));
        resultado = resultado+letra_correjida;
    }
    return resultado;
}


int pedir_edad() {
    string ingreso, limpio;
    int edad;
    long unsigned int tamanio_ingreso, i;
    bool es_numero, valido = false, cambio;
    while (!valido) {  
        es_numero = true;
        i = 0;
        limpio = "";
        ingreso = "";
        cambio = false;
        cout<<"Ingrese la edad del animal: ";
        getline(cin>>ws,ingreso);
        tamanio_ingreso = ingreso.length();
        while (i<tamanio_ingreso && es_numero == true) {
            if (ingreso[i] != ' ' && !isdigit(ingreso[i])) {
                es_numero = false;
            }
            else if (isdigit(ingreso[i])) {
                limpio = limpio + ingreso[i];
                cambio = true;
            }
            i++;
        }
        if (es_numero && cambio) {
            edad=stoi(limpio);
            if (edad >= 0 && edad <= 100) {
                valido = true;
            }
        }
        if (!es_numero || !valido) {
            cout<<"La edad ingresada es invalida, recuerde que debe ser un numero entero entre 0 y 100."<<endl;
        }
    }
    return edad;
}


string pedir_tamanio() {
    string tamanio,ingreso; 
    cout<<"Ingrese el tamanio del animal: ";
    getline(cin>>ws,ingreso);
    tamanio = correccion_mayusculas(ingreso);
    while (tamanio != "Diminuto" && tamanio != "Pequenio" && tamanio != "Mediano" && tamanio != "Grande" && tamanio != "Gigante" && tamanio != "Pequeño") {
        cout<<"El tamanio ingresado no es valido, si quiere saber la lista de tamanios ingrese 1"<<endl
        <<"Ingrese el tamanio del animal: ";
        getline(cin>>ws,ingreso);
        tamanio = correccion_mayusculas(ingreso);

        if (tamanio == "1") {
            mostrar_tamanios();
            cout<<"Ingrese el tamanio del animal: ";
            getline(cin>>ws,ingreso);
            tamanio = correccion_mayusculas(ingreso);
        }
    } 
    if (tamanio == "Pequeño") {
        tamanio = "Pequenio";
    }
    return tamanio;
}


void mostrar_tamanios() {
    cout<<"TAMANIOS"<<endl
    <<'\t'<<"Diminuto"<<endl
    <<'\t'<<"Pequenio"<<endl
    <<'\t'<<"Mediano"<<endl
    <<'\t'<<"Grande"<<endl
    <<'\t'<<"Gigante"<<endl;
}


char pedir_especie() {
    string ingreso;
    long unsigned int tamanio_ingreso;
    char especie;
    cout<<"Ingrese la especie del animal: ";
    getline(cin>>ws,ingreso);
    tamanio_ingreso = ingreso.length();
    especie = char(toupper(ingreso[0]));
    while ((especie != 'P' && especie != 'G' && especie != 'C' && especie != 'R' && especie != 'O' && especie != 'E' && especie != 'L') || tamanio_ingreso!=1) {
        cout<<"La especie ingresada no es valida, si quiere saber la lista de especies ingrese 1"<<endl;
        cout<<"Ingrese la especie del animal: ";
        getline(cin>>ws,ingreso);
        tamanio_ingreso = ingreso.length();
        especie = char(toupper(ingreso[0]));
        if (especie == '1') {
            mostrar_especies();
            cout<<"Ingrese la especie del animal: ";
            getline(cin>>ws,ingreso);
            tamanio_ingreso = ingreso.length();
            especie = char(toupper(ingreso[0]));
        }
    }
    return especie;
}


void mostrar_especies() {
    cout<<"ESPECIES"<<endl
    <<'\t'<<"P. Perro."<<endl
    <<'\t'<<"G. Gato."<<endl
    <<'\t'<<"C. Caballo."<<endl
    <<'\t'<<"R. Roedor."<<endl
    <<'\t'<<"O. Conejo."<<endl
    <<'\t'<<"E. Erizo."<<endl
    <<'\t'<<"L. Lagartija."<<endl;
}


string pedir_personalidad() {
    string tamanio,ingreso; 
    cout<<"Ingrese la personalidad del animal: ";
    getline(cin>>ws,ingreso);
    tamanio = correccion_mayusculas(ingreso);
    while (tamanio != "Dormilon" && tamanio != "Jugueton" && tamanio != "Sociable" && tamanio != "Travieso") {
        cout<<"La personalidad ingresada no es valida, si quiere saber la lista de personalidades ingrese 1"<<endl
        <<"Ingrese la personalidad del animal: ";
        getline(cin>>ws,ingreso);
        tamanio = correccion_mayusculas(ingreso);
        if (tamanio == "1") {
            mostrar_personalidades();
            cout<<"Ingrese la personalidad del animal: ";
            getline(cin>>ws,ingreso);
            tamanio = correccion_mayusculas(ingreso);
        }
    }
    return tamanio;
}


void mostrar_personalidades() {
    cout<<"PERSONALIDADES"<<endl
    <<'\t'<<"Dormilon"<<endl
    <<'\t'<<"Jugueton"<<endl
    <<'\t'<<"Sociable"<<endl
    <<'\t'<<"Travieso"<<endl;
}


bool existe_animal(Lista* lista, string nombre) {
    bool resultado = false;
    Animal* animal;
    int cantidad_animales = lista->obtener_cantidad(), i = 1;
    while(!resultado && i <= cantidad_animales) {
        animal = lista->consulta(i);

        if (nombre == animal->obtener_nombre())
        {
            resultado = true;
        }

        i++;
    }
    return resultado;
}


Animal* creador_animal(string nombre, int edad, string tamanio, char especie, string personalidad) {
    Animal* animal;
    if(especie == 'P') {
        animal = new Perro(nombre, edad, tamanio, especie, personalidad);
    }
    else if(especie == 'G') {
        animal = new Gato(nombre, edad, tamanio, especie, personalidad);
    }
    else if(especie == 'C') {
        animal = new Caballo(nombre, edad, tamanio, especie, personalidad);
    }
    else if(especie == 'R') {
        animal = new Roedor(nombre, edad, tamanio, especie, personalidad);
    }
    else if(especie == 'O') {
        animal = new Conejo(nombre, edad, tamanio, especie, personalidad);
    }
    else if(especie == 'E') {
        animal = new Erizo(nombre, edad, tamanio, especie, personalidad);
    }
    else if(especie == 'L') {
        animal = new Lagartija(nombre, edad, tamanio, especie, personalidad);
    }
    return animal;
}


void mostrar_adopciones_posibles(int espacio_disponible, Lista* lista_animales) {
    lista_animales->iniciar();
    cout<<"LISTA DE ANIMALES QUE PUEDES ADOPTAR SEGUN TU ESPACIO DISPONIBLE"<<endl;
    int i = 1;
    while(lista_animales->hay_siguiente()) {
        Animal* animal = lista_animales->siguiente();    
        if(animal->obtener_tamanio() == "Diminuto" || animal->obtener_tamanio() == "Pequenio") {
            cout<<i<<") Nombre: "<<animal->obtener_nombre()<<endl<<
            "Edad: "<<animal->obtener_edad()<<endl<<
            "Tamanio: "<<animal->obtener_tamanio()<<endl<<
            "Especie: "<<animal->obtener_especie_full()<<endl<<
            "Personalidad: "<<animal->obtener_personalidad()<<endl;
        }    
        else if (espacio_disponible >= 10 && animal->obtener_tamanio() == "Mediano") {
            cout<<i<<") Nombre: "<<animal->obtener_nombre()<<endl<<
            "Edad: "<<animal->obtener_edad()<<endl<<
            "Tamanio: "<<animal->obtener_tamanio()<<endl<<
            "Especie: "<<animal->obtener_especie_full()<<endl<<
            "Personalidad: "<<animal->obtener_personalidad()<<endl;
        }     
        else if (espacio_disponible >= 20 && animal->obtener_tamanio() == "Grande") {
            cout<<i<<") Nombre: "<<animal->obtener_nombre()<<endl<<
            "Edad: "<<animal->obtener_edad()<<endl<<
            "Tamanio: "<<animal->obtener_tamanio()<<endl<<
            "Especie: "<<animal->obtener_especie_full()<<endl<<
            "Personalidad: "<<animal->obtener_personalidad()<<endl;
        }
        else if (espacio_disponible >= 50 && animal->obtener_tamanio() == "Gigante") {
            cout<<i<<") Nombre: "<<animal->obtener_nombre()<<endl<<
            "Edad: "<<animal->obtener_edad()<<endl<<
            "Tamanio: "<<animal->obtener_tamanio()<<endl<<
            "Especie: "<<animal->obtener_especie_full()<<endl<<
            "Personalidad: "<<animal->obtener_personalidad()<<endl;
        }
        i++;
    }
}


int obtener_posicion_animal(Lista* lista, string nombre) {
    bool resultado = false;
    Animal* animal;
    int i = 0;
    int cantidad_animales = lista->obtener_cantidad();
    while(!resultado && i <= cantidad_animales) {
        animal = lista->consulta(i);
        if (nombre == animal->obtener_nombre()) {
            resultado = true;
        }
        else i++;
    }
    return i;
}


int adoptar_o_cancelar() {
    char opcion_elegida;
    string ingreso;
    int respuesta;
    cout<<"Desea adoptar uno de los animales listados?"<<endl
    <<"1: Adoptar animal."<<endl
    <<"2: Cancelar."<<endl;
    getline(cin>>ws,ingreso);
    opcion_elegida = ingreso[0];
    long unsigned int tam_ingreso = ingreso.length();
    while ((opcion_elegida != '1' && opcion_elegida != '2') || tam_ingreso != 1) {
        cout<<"La opcion elegida no es valida"<<endl
       <<"1: Adoptar animal."<<endl
       <<"2: Cancelar."<<endl;
        getline(cin>>ws,ingreso);
        opcion_elegida = ingreso[0];
        tam_ingreso = ingreso.length();
    }
    respuesta = stoi(ingreso);
    return respuesta;
}


int pedir_tamanio_adoptar() {
    string ingreso, limpio;
    int tamanio;
    long unsigned int tamanio_ingreso, i;
    bool es_numero, valido=false, cambio;
    while (!valido) {
        es_numero=true;
        i = 0;
        limpio = "";
        ingreso = "";
        cambio = false;
        cout<<"Ingresar tamanio disponible para el animal en metros cuadrados: ";
        getline(cin>>ws,ingreso);
        cout<<endl;
        tamanio_ingreso = ingreso.length();
        while (i < tamanio_ingreso && es_numero == true) {
            if (ingreso[i] != ' ' && !isdigit(ingreso[i])) {
                es_numero=false;
            }
            else if (isdigit(ingreso[i])){
                limpio = limpio+ingreso[i];
                cambio = true;
            }
            i++;
        }
        if (es_numero && cambio) {
            tamanio = stoi(limpio);
            if (tamanio>0) {
                valido = true;
            }
        }
        if (!es_numero || !valido) {
            cout<<"El tamanio ingresado es invalido, recuerde que debe ser un numero entero mayor a 0."<<endl;
        }
    }
    return tamanio;
}