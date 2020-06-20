#ifndef Sobre_hpp
#define Sobre_hpp

#include <stdio.h>
#include "Envio.hpp"
#include "Cliente.hpp"

using namespace std;

class Sobre : public Envio
{
private:
    double cargoAdicional = 30;
public:
    Sobre();
    Sobre(Cliente, Cliente, int, int);
    double calculaCosto();
    string str();
};

Sobre::Sobre():Envio() {
    cargoAdicional = 30;
}

Sobre::Sobre(Cliente rem, Cliente dest, int iLargo, int iAncho): Envio(rem, dest, iLargo, iAncho) {
    cargoAdicional = 30;
}

double Sobre::calculaCosto(){
    if (largo > 25 && ancho > 30){
        return cargoAdicional + costoEstandar;
    }
    return costoEstandar;
}

string Sobre::str(){
    return "\nSobre:\n" + Envio::str() + "\nCargo Adicional: " + to_string(cargoAdicional);
}


#endif // !Sobre.hpp
