/* Alejandro Gonzalez A01570396
    Reflexion: Esta tarea me ayudo a comprender de una mejor manera el uso de herencias, asi mismo el apoyo del video
    nos apoyo para el desarrollo. El uso de herencias me permite reutilizar codigo de las clases madre en las clases
    hijas. Lo que mas se me dificulto fue el orden del codigo, tambien saber que atributos debia llevar cada 
    clase, y buscar no repetirlas en las clases heredadas.

   Rodolfo Sandoval A01720253
    Reflexion: Durante esta tarea, aprendi a manejar el uso de Herencias dentro de la POO en C++.
    Es una manera sencilla de juntar diferentes clases y objetos para poder utilizar sus atributos
    en otros objetos. Aprendi que las herencias son importantes para organizar tu codigo y para programar
    de manera mas eficiente. Se me dificulto el desarrollo del sintaxis al poner una herencia con ":".
*/


#include <iostream>
#include <stdio.h>
#include <string>
#include "Paquete.hpp"
#include "Sobre.hpp"

using namespace std;


//main 

int main() {

    Cliente lupita, rafa("Rafael", "Itesm", "Mty", "N.L." ,"6502");
    Paquete automovil(lupita, rafa, 500, 500, 500, 500), libro, escritorio(lupita, rafa, 200, 200, 200, 200), pluma(lupita, rafa, 350, 320, 300, 345), jumex(lupita, rafa, 150, 100, 150, 100), raton(lupita, rafa, 300, 400, 600, 600);
    Sobre carta(rafa, lupita, 30, 50), regalo(rafa, lupita, 20, 50), papitas(rafa, lupita, 30, 60), hoja(rafa, lupita, 40, 20), lapiz(rafa, lupita, 30, 20) ;
    cout << "Automovil: " << automovil.str() << "\nCosto total: " << automovil.calculaCosto() << endl << endl;
    cout << "Escritorio: " << escritorio.str() << "\nCosto total: " << escritorio.calculaCosto() << endl << endl;
    cout << "Pluma: " << pluma.str() << "\nCosto total: " << pluma.calculaCosto() << endl << endl;
    cout << "Jumex: " << jumex.str() << "\nCosto total: " << jumex.calculaCosto() << endl << endl;
    cout << "Libro: " << libro.str() << "\nCosto total: " << libro.calculaCosto() << endl << endl;
    cout << "Raton: " << raton.str() << "\nCosto total: " << raton.calculaCosto() << endl << endl;
    cout << "Carta: " << carta.str() << "\nCosto total: " << carta.calculaCosto() << endl << endl;
    cout << "Regalo: " << regalo.str() << "\nCosto total: " << regalo.calculaCosto() << endl << endl;
    cout << "Papitas: " << papitas.str() << "\nCosto total: " << papitas.calculaCosto() << endl << endl;
    cout << "Hoja: " << hoja.str() << "\nCosto total: " << hoja.calculaCosto() << endl << endl;
    cout << "Lapiz: " << lapiz.str() << "\nCosto total: " << lapiz.calculaCosto() << endl << endl;
    return 0;
}
