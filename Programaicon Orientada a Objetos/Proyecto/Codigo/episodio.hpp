#ifndef episodio_hpp
#define episodio_hpp
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class Episodio {
protected:
    // variables
    string sTitulo;
    int iTemporada;
    double dCalificacion;
public:
    // constructores
    Episodio();
    Episodio(string,int,double);
    string str();
    // sets y gets
    void setTitulo(string);
    string getTitulo();
    void setTemporada(int);
    int getTemporada();
    void setCalificacion(double);
    double getCalificacion();
    // sobrecarga operador  +
    double operator +(double dPuntuacion) {
    return dPuntuacion + dCalificacion;
    }   
};

Episodio::Episodio() {
    sTitulo = "NDA";
    iTemporada = 0;
    dCalificacion = 0;
}

Episodio::Episodio(string sTitulo, int iTemporada, double dCalificacion) {
    this->sTitulo = sTitulo;
    this->iTemporada = iTemporada;
    this->dCalificacion= dCalificacion;
}

string Episodio::str() {
    return sTitulo + ", " + to_string(iTemporada) + ", " + to_string(dCalificacion);
}

void Episodio::setTitulo(string sTitulo) {
    this->sTitulo=sTitulo;
}

string Episodio::getTitulo() {
    return sTitulo;
}

void Episodio::setTemporada(int iTemporada) {
    this->iTemporada=iTemporada;
}

int Episodio::getTemporada() {
    return iTemporada;
}

void Episodio::setCalificacion(double dCalificacion) {
    this->dCalificacion = dCalificacion;
}

double Episodio::getCalificacion() {
    return dCalificacion;
}


#endif // !episodio_hpp
