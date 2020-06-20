#ifndef video_hpp
#define video_hpp
#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Video {
private:
    //Variables
    string id, titulo, genero;
    int duracion;
    double cPromedio;
public:
    // Constructores
    Video();
    Video(string, string, int, string, double);
    
    // Metodos
    string str();
    
    // Sets y Gets
    void setId(string);
    string getId();
    void setTitulo(string);
    string getTitulo();
    void setGenero(string);
    string getGenero();
    void setDuracion(int);
    int getDuracion();
    void setCalificacion(double);
    double getCalificacion();
};

//Constructor
Video::Video() {
    id = "ND";
    titulo = "ND";
    genero = "ND";
    duracion = 0;
    cPromedio = 0.0;
}

//Constructor
Video::Video(string id, string titulo, int duracion,string genero, double cPromedio) {
    this->id=id;
    this->titulo=titulo;
    this->genero=genero;
    this->duracion=duracion;
    this->cPromedio=cPromedio;
}

void Video::setId(string id) {
    this->id = id;
}

string Video::getId(){
    return id;
}

void Video::setTitulo(string titulo) {
    this->titulo=titulo;
}

string Video::getTitulo(){
    return titulo;
}

void Video::setGenero(string genero) {
    this->genero=genero;
}

string Video::getGenero(){
    return genero;
}

void Video::setDuracion(int duracion) {
    this->duracion=duracion;
}

int Video::getDuracion(){
    return duracion;
}

void Video::setCalificacion(double cPromedio) {
    this->cPromedio=cPromedio;
}

double Video::getCalificacion(){
    return cPromedio;
}

// str del cual se van a componer serie y pelicula.
string Video::str() {
    return id + ", " + titulo + ", " + to_string(duracion) + ", " + genero + ", " + to_string(cPromedio);
}


#endif // !video_hpp

