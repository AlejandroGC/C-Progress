#ifndef Envio_hpp
#define Envio_hpp
#include <stdio.h>
#include "Cliente.hpp"

using namespace std;

class Envio: public Cliente
{
private:
    Cliente remitente, destinario;
public:
    int costoEstandar, largo, ancho;
    Envio();
    Envio(Cliente, Cliente, int, int);
    virtual double calculaCosto();
    virtual string str();
};

Envio::Envio(){
    costoEstandar = 100;
    largo = 0;
    ancho = 0; 
}

Envio::Envio(Cliente rem, Cliente des, int l, int a){
    remitente = rem;
    destinario = des;
    costoEstandar = 100;
    largo = l;
    ancho = a;
}
 
double Envio::calculaCosto(){
    return costoEstandar;
}

string Envio::str(){
    return "Remitente:\n" + remitente.str() + "\nDestinario:\n" + destinario.str() + "\nLargo: " + to_string(largo) + "\nAncho: " + to_string(ancho);
}


#endif // !Envio_hpp


