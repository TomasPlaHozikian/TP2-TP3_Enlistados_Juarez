#include <iostream>
#include "lista.h"

using namespace std;

int main()
{
    Lista p;
    p.alta('H', 1);
    p.alta('O', 2);
    p.alta('L', 3);
    p.alta('A', 4);
    cout<<"recorrido con cursor: " <<endl;
    p.iniciar();
    while(p.hay_siguiente()){
        cout<<p.siguiente()<<endl;
    }
    return 0;
}