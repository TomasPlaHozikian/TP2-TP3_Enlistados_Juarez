#include "mapa.hpp"


Mapa::Mapa()
{
    grafo = new Grafo();
    for (int i = 1; i <= 64; i++)
    {
        string nombre = to_string(i);
        grafo->agregarVertice(nombre);
    }
    for(int i = 1; i <= 64; i++){
        grafo->conectar_vertices(i);
    }
    cantidad_animales = 5;
    auto1 = new Auto();
    posicion_auto = 0;
    animal1 = generar_animal();
    animal2 = generar_animal();
    animal3 = generar_animal();
    animal4 = generar_animal();
    animal5 = generar_animal();
    asignar_pos_animales();
    rescatado1 = false;
    rescatado2 = false;
    rescatado3 = false;
    rescatado4 = false;
    rescatado5 = false;
}


Animal *crear_animal(string nombre, int edad, string tamanio, char especie, string personalidad)
{
    Animal *animal;
    if (especie == 'P')
    {
        animal = new Perro(nombre, edad, tamanio, especie, personalidad);
    }
    else if (especie == 'G')
    {
        animal = new Gato(nombre, edad, tamanio, especie, personalidad);
    }
    else if (especie == 'C')
    {
        animal = new Caballo(nombre, edad, tamanio, especie, personalidad);
    }
    else if (especie == 'R')
    {
        animal = new Roedor(nombre, edad, tamanio, especie, personalidad);
    }
    else if (especie == 'O')
    {
        animal = new Conejo(nombre, edad, tamanio, especie, personalidad);
    }
    else if (especie == 'E')
    {
        animal = new Erizo(nombre, edad, tamanio, especie, personalidad);
    }
    else if (especie == 'L')
    {
        animal = new Lagartija(nombre, edad, tamanio, especie, personalidad);
    }
    return animal;
}


Animal *Mapa::generar_animal()
{
    // Arreglo de 10 nombres.
    string nombre_base = "N/A";
    // Arreglo de especies de animales.
    char especies[7] = {'R', 'C', 'O', 'E', 'L', 'G', 'P'};
    // Arreglo de tamanios de animales.
    string tamanios[5] = {"Diminuto", "Pequenio", "Mediano", "Grande", "Gigante"};
    // Arreglo de personalidades de animales.
    string personalidades[4] = {"Dormilon", "Jugueton", "Travieso", "Sociables"};

    Animal *animal = crear_animal(nombre_base, rand() % 100,
            tamanios[rand() % 5], especies[rand() % 7], personalidades[rand() % 4]);
    return animal;
}


void Mapa::asignar_pos_animales(){
    int pos1 = animal1_pos;
    int pos2 = animal2_pos;
    int pos3 = animal3_pos;
    int pos4 = animal4_pos;
    int pos5 = animal5_pos;
    pos1 = rand() % 64 + 2;
    pos2 = rand() % 64 + 2;
    while(pos2 == pos1) pos2 = rand() % 64 + 2;
    pos3 = rand() % 64 + 2;
    while(pos3 == pos1 || pos3 == pos2) pos3 = rand() % 64 + 2;
    pos4 = rand() % 64 + 2;
    while(pos4 == pos1 || pos4 == pos2 || pos4 == pos3) pos4 = rand() % 64 + 2;
    pos5 = rand() % 64 + 2;
    while(pos5 == pos1 || pos5 == pos2 || pos5 == pos3 || pos5 == pos4) pos5 = rand() % 64 + 2;
    if(pos1 % 8 == 7 || pos1 % 8 == 0) pos1 += 2;
    if(pos2 % 8 == 7 || pos2 % 8 == 0) pos2 += 2;
    if(pos3 % 8 == 7 || pos3 % 8 == 0) pos3 += 2;
    if(pos4 % 8 == 7 || pos4 % 8 == 0) pos4 += 2;
    if(pos5 % 8 == 7 || pos5 % 8 == 0) pos5 += 2;
    animal1_pos = pos1;
    animal2_pos = pos2;
    animal3_pos = pos3;
    animal4_pos = pos4;
    animal5_pos = pos5;
}


Grafo *Mapa::obtener_grafo(){
    return grafo;
}


Auto* Mapa::obtener_auto(){
    return auto1;
}


int Mapa::obtener_combustible(){
    return auto1->obtener_combustible();
}


int Mapa::obtener_cantidad_animales(){
    return cantidad_animales;
}


void Mapa::obtener_posicion_animales(){
    cout<<animal1_pos<<endl;
    cout<<animal2_pos<<endl;
    cout<<animal3_pos<<endl;
    cout<<animal4_pos<<endl;
    cout<<animal5_pos<<endl;
}


bool Mapa::hay_animal(int pos){
    bool hay_animal = false;
    int pos1 = animal1_pos;
    int pos2 = animal2_pos;
    int pos3 = animal3_pos;
    int pos4 = animal4_pos;
    int pos5 = animal5_pos;
    int arreglo[5] = {pos1, pos2, pos3, pos4, pos5};
    for(int i = 0; i < 5; i++){
        if(arreglo[i] == pos){
            hay_animal = true;
        }
    }
    return hay_animal;
}


void mostrar_ubicacion(int pos){
    if(pos != 999){
        pos += 1;
        int x;
        int y;
        if(pos % 8 == 0){
            y = pos / 8;
        }
        else{
            y = (pos / 8) + 1;
        }
        x = pos % 8;
        if(pos % 8 == 0) x = 8;
        cout<<endl<<"posicion: "<<x<<", "<<y<<endl; 
    }
    
}


void Mapa::marcar_rescatado(int num){
    if(num == 1){
        rescatado1 = true;
        animal1_pos = 999;
    }
    if(num == 2){
        rescatado2 = true;
        animal2_pos = 999;
    }
    if(num == 3){
        rescatado3 = true;
        animal3_pos = 999;
    }
    if(num == 4){
        rescatado4 = true;
        animal4_pos = 999;
    }
    if(num == 5){
        rescatado5 = true;
        animal5_pos = 999;
    }
}


bool Mapa::obtener_estado_animal(int num){
    bool rescatado;
    if(num == 1) rescatado = rescatado1;
    if(num == 2) rescatado = rescatado2;
    if(num == 3) rescatado = rescatado3;
    if(num == 4) rescatado = rescatado4;
    if(num == 5) rescatado = rescatado5;
    return rescatado;
}


bool Mapa::todos_rescatados(){
    bool rescatados = true;
    for(int i = 1; i <= 5; i++){
        if(obtener_estado_animal(i) == false){
            rescatados = false;
        }
    }
    return rescatados;
}


void Mapa::mostrar_rescates(){
    cout<<"Posibles rescates: "<<endl;
    if(!rescatado1){
        cout<<"1) "<<animal1->obtener_especie_full();
        mostrar_ubicacion(animal1_pos);
    }
    if(!rescatado2){
        cout<<"2) "<<animal2->obtener_especie_full();
        mostrar_ubicacion(animal2_pos);
    }
    if(!rescatado3){
        cout<<"3) "<<animal3->obtener_especie_full();
        mostrar_ubicacion(animal3_pos);
    }
    if(!rescatado4){
        cout<<"4) "<<animal4->obtener_especie_full();
        mostrar_ubicacion(animal4_pos);
    }
    if(!rescatado5){
        cout<<"5) "<<animal5->obtener_especie_full();
        mostrar_ubicacion(animal5_pos);
    }
}


Animal* Mapa::seleccionar_animal(int num){
    Animal* animal;
    switch(num){
        case(1):
            animal = animal1;
            break;
        case(2):
            animal = animal2;
            break;
        case(3):
            animal = animal3;
            break;
        case(4):
            animal = animal4;
            break;
        case(5):
            animal = animal5;
            break;   
    }
    return animal;
}


void Mapa::imprimir_mapa(){
    
    string terrenos[64] = {"C", "P", "T", "T", "T", "T", "T" , "T", "C", "T", "T", "T", "P",
     "P", "P", "P", "C", "C", "C", "C", "C", "T", "M", "M", "T", "T", "T", "T", "C", "T", "M"
    , "M", "M", "M", "M", "T", "C", "T", "M", "M", "T", "T", "T", "T", "C", "T", "M", "M", "T"
    , "P", "P", "P", "C", "T", "M", "M", "T", "T", "T", "T", "C", "C", "C", "C"};
    for(int i = 0; i <= 63; i++){
        if(i % 8 == 0){
            cout << endl;
        }
        if(terrenos[i] == "C"){
            if(i == posicion_auto && !hay_animal(i)) cout << BGND_GRAY_245<< " A \e[0m";
            if(i != posicion_auto && !hay_animal(i)) cout << BGND_GRAY_245<< "   \e[0m";
            if(i != posicion_auto && i == animal1_pos) cout << BGND_GRAY_245<<" "<< animal1->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal2_pos) cout << BGND_GRAY_245<<" "<< animal2->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal3_pos) cout << BGND_GRAY_245<<" "<< animal3->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal4_pos) cout << BGND_GRAY_245<<" "<< animal4->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal5_pos) cout << BGND_GRAY_245<<" "<< animal5->obtener_especie() <<" "<<"\e[0m";
        }
        if(terrenos[i] == "T"){
            if(i == posicion_auto && !hay_animal(i)) cout << BGND_ORANGE_208<< " A \e[0m";
            if(i != posicion_auto && !hay_animal(i)) cout << BGND_ORANGE_208<< "   \e[0m";
            if(i != posicion_auto && i == animal1_pos) cout << BGND_ORANGE_208<<" "<< animal1->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal2_pos) cout << BGND_ORANGE_208<<" "<< animal2->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal3_pos) cout << BGND_ORANGE_208<<" "<< animal3->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal4_pos) cout << BGND_ORANGE_208<<" "<< animal4->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal5_pos) cout << BGND_ORANGE_208<<" "<< animal5->obtener_especie() <<" "<<"\e[0m";

        }
        if(terrenos[i] == "M"){
            if(i == posicion_auto && !hay_animal(i)) cout << BGND_DARK_RED_52<< " A \e[0m";
            if(i != posicion_auto && !hay_animal(i)) cout << BGND_DARK_RED_52<< "   \e[0m";
            if(i != posicion_auto && i == animal1_pos) cout << BGND_DARK_RED_52<<" "<< animal1->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal2_pos) cout << BGND_DARK_RED_52<<" "<< animal2->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal3_pos) cout << BGND_DARK_RED_52<<" "<< animal3->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal4_pos) cout << BGND_DARK_RED_52<<" "<< animal4->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal5_pos) cout << BGND_DARK_RED_52<<" "<< animal5->obtener_especie() <<" "<<"\e[0m";

        }
        if(terrenos[i] == "P"){
            if(i == posicion_auto && !hay_animal(i)) cout << BGND_BLACK_16<< " A \e[0m";
            if(i != posicion_auto && !hay_animal(i)) cout << BGND_BLACK_16<< "   \e[0m";
            if(i != posicion_auto && i == animal1_pos) cout << BGND_BLACK_16<<" "<< animal1->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal2_pos) cout << BGND_BLACK_16<<" "<< animal2->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal3_pos) cout << BGND_BLACK_16<<" "<< animal3->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal4_pos) cout << BGND_BLACK_16<<" "<< animal4->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal5_pos) cout << BGND_BLACK_16<<" "<< animal5->obtener_especie() <<" "<<"\e[0m";

        }

    }
    cout<<endl<<endl;
}


int Mapa::obtener_posicion_auto(){
    return posicion_auto + 1;
}


int Mapa::obtener_posicion_animal(int num){
    int pos;
    if(num == 1) pos = animal1_pos;
    if(num == 2) pos = animal2_pos;
    if(num == 3) pos = animal3_pos;
    if(num == 4) pos = animal4_pos;
    if(num == 5) pos = animal5_pos;
    return pos;
}


void Mapa::mover_auto_consumo(int num){
    int distancia = grafo->obtenerCaminoMinimo()->costoViaje(posicion_auto, obtener_posicion_animal(num));
    auto1->consumir_combustible(distancia);
}

int Mapa::consumo_viaje(int num){
    int consumo;
    consumo = grafo->obtenerCaminoMinimo()->costoViaje(posicion_auto, obtener_posicion_animal(num));
    return consumo;
}

bool Mapa::suficiente_combustible(int pos){
    bool suficiente = true;
    int distancia = grafo->obtenerCaminoMinimo()->costoViaje(posicion_auto, obtener_posicion_animal(pos));
    if(distancia > auto1->obtener_combustible()){
        suficiente = false;
    }
    return suficiente;
}

bool enArrego(string arreglo[], int largo, int num){
    bool esta = false;
    for(int i = 0; i < largo || arreglo[i] == ""; i++){
        if(arreglo[i] == to_string(num)) esta = true;
    }
    return esta;
}


void Mapa::imprimir_recorrido(int origen, int destino){
    origen -= 1;
    destino -= 1;
    int** matrizCaminos = grafo->obtenerMatrizCaminos();
    CaminoMinimo* floyd = grafo->obtenerCaminoMinimo();
    Lista<Vertice>* vertices = floyd->obtenerVertices();
    string camino[16] = {"", "","","","","","","","","","","","","","",""};
    cout<<endl;
    int num = 0;
    do{
        origen = matrizCaminos[origen][destino];
        camino[num] += vertices->obtenerNombre(origen);
        num++;
        }while(origen != destino);

    
    string terrenos[64] = {"C", "P", "T", "T", "T", "T", "T" , "T", "C", "T", "T", "T", "P",
     "P", "P", "P", "C", "C", "C", "C", "C", "T", "M", "M", "T", "T", "T", "T", "C", "T", "M"
    , "M", "M", "M", "M", "T", "C", "T", "M", "M", "T", "T", "T", "T", "C", "T", "M", "M", "T"
    , "P", "P", "P", "C", "T", "M", "M", "T", "T", "T", "T", "C", "C", "C", "C"};
    for(int i = 0; i <= 63; i++){
        if(i % 8 == 0){
            cout << endl;
        }
        if(terrenos[i] == "C"){
            if(i == posicion_auto && !hay_animal(i) && !enArrego(camino, 16, i)) cout << BGND_GRAY_245<< " A \e[0m";
            if(i != posicion_auto && !hay_animal(i) && !enArrego(camino, 16, i)) cout << BGND_GRAY_245<< "   \e[0m";
            if(i != posicion_auto && i == animal1_pos && !enArrego(camino, 16, i)) cout << BGND_GRAY_245<<" "<< animal1->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal2_pos && !enArrego(camino, 16, i)) cout << BGND_GRAY_245<<" "<< animal2->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal3_pos && !enArrego(camino, 16, i)) cout << BGND_GRAY_245<<" "<< animal3->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal4_pos && !enArrego(camino, 16, i)) cout << BGND_GRAY_245<<" "<< animal4->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal5_pos && !enArrego(camino, 16, i)) cout << BGND_GRAY_245<<" "<< animal5->obtener_especie() <<" "<<"\e[0m";
            if(enArrego(camino, 16, i)) cout << BGND_GRAY_245<<" "<< "X" <<" "<<"\e[0m";
        }
        if(terrenos[i] == "T"){
            if(i == posicion_auto && !hay_animal(i) && !enArrego(camino, 16, i)) cout << BGND_ORANGE_208<< " A \e[0m";
            if(i != posicion_auto && !hay_animal(i) && !enArrego(camino, 16, i)) cout << BGND_ORANGE_208<< "   \e[0m";
            if(i != posicion_auto && i == animal1_pos && !enArrego(camino, 16, i)) cout << BGND_ORANGE_208<<" "<< animal1->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal2_pos && !enArrego(camino, 16, i)) cout << BGND_ORANGE_208<<" "<< animal2->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal3_pos && !enArrego(camino, 16, i)) cout << BGND_ORANGE_208<<" "<< animal3->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal4_pos && !enArrego(camino, 16, i)) cout << BGND_ORANGE_208<<" "<< animal4->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal5_pos && !enArrego(camino, 16, i)) cout << BGND_ORANGE_208<<" "<< animal5->obtener_especie() <<" "<<"\e[0m";
            if(enArrego(camino, 16, i)) cout << BGND_ORANGE_208<<" "<< "X" <<" "<<"\e[0m";
        }
        if(terrenos[i] == "M"){
            if(i == posicion_auto && !hay_animal(i) && !enArrego(camino, 16, i)) cout << BGND_DARK_RED_52<< " A \e[0m";
            if(i != posicion_auto && !hay_animal(i) && !enArrego(camino, 16, i)) cout << BGND_DARK_RED_52<< "   \e[0m";
            if(i != posicion_auto && i == animal1_pos && !enArrego(camino, 16, i)) cout << BGND_DARK_RED_52<<" "<< animal1->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal2_pos && !enArrego(camino, 16, i)) cout << BGND_DARK_RED_52<<" "<< animal2->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal3_pos && !enArrego(camino, 16, i)) cout << BGND_DARK_RED_52<<" "<< animal3->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal4_pos && !enArrego(camino, 16, i)) cout << BGND_DARK_RED_52<<" "<< animal4->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal5_pos && !enArrego(camino, 16, i)) cout << BGND_DARK_RED_52<<" "<< animal5->obtener_especie() <<" "<<"\e[0m";
            if(enArrego(camino, 16, i)) cout << BGND_DARK_RED_52<<" "<< "X" <<" "<<"\e[0m";
        }
        if(terrenos[i] == "P"){
            if(i == posicion_auto && !hay_animal(i) && !enArrego(camino, 16, i)) cout << BGND_BLACK_16<< " A \e[0m";
            if(i != posicion_auto && !hay_animal(i) && !enArrego(camino, 16, i)) cout << BGND_BLACK_16<< "   \e[0m";
            if(i != posicion_auto && i == animal1_pos && !enArrego(camino, 16, i)) cout << BGND_BLACK_16<<" "<< animal1->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal2_pos && !enArrego(camino, 16, i)) cout << BGND_BLACK_16<<" "<< animal2->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal3_pos && !enArrego(camino, 16, i)) cout << BGND_BLACK_16<<" "<< animal3->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal4_pos && !enArrego(camino, 16, i)) cout << BGND_BLACK_16<<" "<< animal4->obtener_especie() <<" "<<"\e[0m";
            if(i != posicion_auto && i == animal5_pos && !enArrego(camino, 16, i)) cout << BGND_BLACK_16<<" "<< animal5->obtener_especie() <<" "<<"\e[0m";
            if(enArrego(camino, 16, i)) cout << BGND_BLACK_16<<" "<< "X" <<" "<<"\e[0m";
        }

    }
    cout<<endl;    
}

Mapa::~Mapa(){
    delete animal1;
    delete animal2;
    delete animal3;
    delete animal4;
    delete animal5;
    auto1->~Auto();
    grafo->~Grafo();
}