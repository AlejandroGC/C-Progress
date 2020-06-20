// Alejandro Gonzalez A01570396
// Reflexion: En esta tarea aprendi que es posible enviar el mismo metodo a diferentes objetos. Asi como tambien no pueden ser instanceadas.
// La clase hija puede usar los elementos y atributos, de la clase padre. El uso del especificador virtual y las funciones abstractas.
// 

#include <iostream>
#include <stdio.h>
#include <string>
#include "Paquete.hpp"
#include "Sobre.hpp"

using namespace std;


//main 
void leerDatosRemitenteDestinatario(Cliente &datosCliente){
    cout << "Ingresa el nombre: ";
    getline(cin, datosCliente.nombre);
    cout << "Ingresa el direccion: ";
    getline(cin, datosCliente.direccion);
    cout << "Ingresa el ciudad: ";
    getline(cin, datosCliente.ciudad);
    cout << "Ingresa el estado: ";
    getline(cin, datosCliente.estado);
    cout << "Ingresa el codigo postal: ";
    getline(cin, datosCliente.codigoPostal);
}

void leerDatosPaquete(Paquete &datosPaquete){
    Cliente remitente, destinatario;
    string sValor;
    int iValor;
    double dValor;

    cout << " +-+-+-+-+-+ Ingresa Datos del Remitente: ";
    leerDatosRemitenteDestinatario(remitente);
    cout << " +-+-+-+-+-+ Ingresa Datos del Destinatario: ";
    leerDatosRemitenteDestinatario(destinatario);

    datosPaquete.setRemitente(remitente);
    datosPaquete.setDestinatario(destinatario);

    cout << "Ingresa el largo de Paquete: ";
    getline(cin ,sValor);
    datosPaquete.setLargo()


}



int menu() {
    int opcion;
    cout << "Sistema de Paqueteria Rapi\n" <<
    "1. Alta Paquete\n" <<
    "2. Alta Sobre\n" <<
    "0. Salir\n" <<
    "Tecla la opcion: ";
    cin >> opcion;
    cin.ignore();
    return opcion;
}

int main(){
    Cliente lupita, rafa("Rafael", "Itesm", "Mty", "N.L." ,"6502");
    
    Paquete automovil(lupita, rafa, 500, 500, 500, 500), libro, 
    escritorio(lupita, rafa, 200, 200, 200, 200), pluma(lupita, rafa, 350, 320, 300, 345), 
    jumex(lupita, rafa, 150, 100, 150, 100), raton(lupita, rafa, 300, 400, 600, 600);
    
    Sobre carta(rafa, lupita, 30, 50), 
    regalo(rafa, lupita, 20, 50), papitas(rafa, lupita, 30, 60),
    hoja(rafa, lupita, 40, 20), lapiz(rafa, lupita, 30, 20) ;

    Envio reno;
    double sumaT;

    Envio *prtArrEnvios[] = {&reno, &automovil, &libro, &carta, &escritorio, &pluma, &jumex, &raton, &regalo, &papitas, &hoja, &lapiz};
    for (int i = 0; i < 12; i++) {
        cout << i << endl << prtArrEnvios[i]->str() << "\nCosto Total: " << prtArrEnvios[i]->calculaCosto() << endl;
        sumaT += prtArrEnvios[i]->calculaCosto();
    }
    cout << sumaT;

    return 0;
}

void leerDatosSobre(Sobre &datosSobre){
    Cliente remitente, destinatario;
    string sValor;
    int iValor;
    cout << "***** Ingresa Datos del Remitente\n";
    leerDatosRemitenteDestinatario(remitente);

    cout << "***** Ingresa Datos del Destinatario\n";
    leerDatosRemitenteDestinatario(destinatario);



}
