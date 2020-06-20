#ifndef Paquete_hpp
#define Paquete_hpp
#include <stdio.h>
#include "Cliente.hpp"
#include "Envio.hpp"

using namespace std;

class Paquete : public Envio
{
private:
    int profundidad;
    double peso, costoKg;
public:
    Paquete();
    Paquete(Cliente, Cliente, int, int, int, double);
    double calculaCosto();
    string str();
};

Paquete::Paquete():Envio() {
    profundidad = 100;
    peso = 1;
    costoKg = 10;
}

Paquete::Paquete(Cliente re, Cliente de, int iLargo, int iAncho, int iProfundidad, double dPeso):Envio(re, de, iLargo, iAncho){
    profundidad = iProfundidad;
    peso = dPeso;
    costoKg = 10;
}

double Paquete::calculaCosto(){
    return peso*costoKg + costoEstandar;
}

string Paquete::str(){
    return "\nPaquete:\n" + Envio::str() + "\nProfundidad: " + to_string(profundidad) + "\nPeso: " + to_string(peso) + "\nCosto por Kg: " + to_string(costoKg);
}

#endif