#ifndef pelicula_hpp
#define pelicula_hpp
#include "video.hpp"
#include <iostream>
#include <stdio.h>


using namespace std;


class Pelicula : public Video {
private:
    //Variables
    int oscares;
public:
    // constructores
    Pelicula();
    Pelicula(string, string, int, string, double, int);
    // sets y gets
    void setOscares(int);
    int getOscares();
    string str();
    // Realiza la suma de 0.5 en caso de que tenga oscares.
    double calPromedio(double, int);
};
 
//constructores

Pelicula::Pelicula(){
    oscares = 0;
}

Pelicula::Pelicula(string id, string titulo, int duracion, string genero, double cPromedio, int oscares) : Video(id, titulo, duracion, genero, cPromedio){
    this->oscares = oscares;
}

//sets y gets

void Pelicula::setOscares(int oscares){
    this->oscares = oscares;
}

int Pelicula::getOscares(){
    return oscares;
}

string Pelicula::str(){
    // Imprime la base video con los oscares de la pelicula.
    return Video::str() + ", " + to_string(oscares);
}

double Pelicula::calPromedio(double cPromedio, int oscares) {
    // Validacion de que existan oscares
    if (oscares != 0) {
        for (int i = 0; i < oscares; i++) {
            // Verifica que el promedio no sea mayir a 5.
            if (cPromedio < 5.0) {
                cPromedio = cPromedio + 0.5;
                // Al estar sumando se hace otra validacion que nunca se pase de 5. 
                // En caso de que se pase se le asigna el valor 5.
                if (cPromedio > 5.0) {
                    cPromedio = 5.0;
                }
                
            }
        }
        return cPromedio;
    } else {
        // Si no existen oscares se le regresa el valor que ya tenia de calificacion.
        return cPromedio;
    }
}


#endif