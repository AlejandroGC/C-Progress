#ifndef serie_hpp
#define serie_hpp
#include "video.hpp"
#include "episodio.hpp"
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class Serie : public Video{
private:
    // Objetos
    Episodio *ptrEpisodios[5];
    // Variables
    int iCant;
public:
    //Constructor
    Serie();
    Serie(string, string, int, string, double ,int, Episodio *arrPtrEpi[]);
    // Metodo que calcula el promedio dependiendo del la cantidad de episodios y su calificacion.
    // Se usa la sobrecarga del operador + para obtener la calificacion de cada episodio.
    double calPromedio();
    // Set del episodio en caso de decidir cambiar los valores, se introduce el episodio y el ptrEpisodio de una serie.
    void setEpisodio(int, Episodio *);
    // Get del episodio le decimos que posicion y nos returna el episodio.
    Episodio getEpisodio(int);
    // Set de la cantidad de episodios, cambia el valor de iCant de una serie.
    void setCantidadEpisodios(int);
    // Obtiene la cantidad de episodios de una serie.
    int getCantidadEpisodios();
    // Imprime la base video mas la cantidad de episodios y su infor de cada uno.
    string str();
    // Agrega un episodio al arrEpisodio de una serie en base a lo llenado en el main.
    void altaEpisodio(Episodio *ptrEpisodio);
};

// Constructor
Serie::Serie() {
    // Inicializacion
    iCant = 0;
    for (int i = 0; i < 5; i++) {
        ptrEpisodios[i] = nullptr;
    }
    
}

// El orden importa, constructor
Serie::Serie(string id, string titulo, int duracion, string genero, double cPromedio, int iCant, Episodio *arrPtrEpi[]) : Video(id, titulo, duracion, genero, cPromedio){
    this->iCant = iCant;
    *ptrEpisodios = *arrPtrEpi;
}

double Serie::calPromedio() {
    double dPromedio;
    dPromedio = 0;
    // Se suman las calificaciones de los episodios gracias a la sobrecarga +.
    for(int  iR = 0; iR < iCant; iR++){
        dPromedio = *ptrEpisodios[iR] + dPromedio;    
    }
    // Si existen episodios lo divide, si no existen retorna un -1
    if (iCant > 0) {
        return dPromedio/iCant;
    } 
    return -1;
}


void Serie::setEpisodio(int epi, Episodio *arr) {
    ptrEpisodios[epi] = arr;
    epi++;
}


Episodio Serie::getEpisodio(int epi) {
    return *ptrEpisodios[epi];
}

void Serie::setCantidadEpisodios(int iCant) {
    this->iCant = iCant;
}

int Serie::getCantidadEpisodios() {
    return iCant;
}


string Serie::str() {
    string infoEpisodios = "";
    for (int iR = 0; iR < iCant; iR++) {
        // Conecta en un string toda la informacion de un episodio
        infoEpisodios = infoEpisodios + "Episodio: " + to_string(iR+1) + " " +  ptrEpisodios[iR]->str() + "\n";
    }
    
    // Toda la informacion la desplega.
    return Video::str() + ", " + to_string(iCant) + "\n" + infoEpisodios;
}

void Serie::altaEpisodio(Episodio *ptr) {
    // Validacion que la cantidad de episodios tiene que ser menor a 5 para poder añadir un episodio nuevo,
    // si no le despliega esta llena la serie.
    if (iCant < 5) {
        ptrEpisodios[iCant++] = ptr;
    } else
    {
        cout << "Esta llena la serie.";
    }
}

#endif // !serie_hpp


