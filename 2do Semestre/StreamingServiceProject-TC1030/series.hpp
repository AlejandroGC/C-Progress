#ifndef series_hpp
#define series_hpp
#include "serie.hpp"
#include <stdio.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class Series{
private:
    // Instancia
    Serie *arrPtrSeries[100];
    // Variable
    int iCant;
public:
    // constructor
    Series();

    // metodos
    // Lee los archivos csv archivoSerie y episodio. Y los introduce en los objetos.
    void leerArchivo();
    // Despliega la informacion completa de las series con sus episodios.
    void str();
    // Reporta el listado de todas las series con la calificacion que se introduce al metodo.
    void reporteConCalificacion(double);
    // Reporta el listado de todas las series con el genero que se introduce al metodo.
    void reporteGenero(string);
    // Hace la validacion de si el ID de una serie existe.
    Serie* getPtrSerie(string);
    // Despliega los episodios de una serie, validando que sea el mismo ID y que tenga la calificacion solicitada.
    void consultaEpisodiosConCalificacion(string sID,double dCal);
    // Despliega los episodios de una serie buscando el ID que se le introduce.
    void consultaEpisodios(string sID);
    // Calcula el promedio de una serie en base a sus episodios.
    void calcularPromedioXSerie();
    // Da de alta una serie en la lista de episodios de una serie. Sin embargo NO la despliega en el csv.
    Serie* alta(string, Episodio *);

};

// constructor
Series::Series(){
    iCant = 0;
    for (int i = 0; i < 100; i++) {
        arrPtrSeries[i] = nullptr;
    }
}

void Series::consultaEpisodiosConCalificacion(string ID, double dCal) {
    Serie consulta;
    // Busca entre todas las series la que coincida con el id dado
    for (int iR = 0; iR < iCant; iR++) {
        if (arrPtrSeries[iR]->getId() == ID) {
            // Al tener los episodios de la serie busca entre esos episodios el que coincida con la calificacion dada.
            for (int iEpisodio = 0; iEpisodio < arrPtrSeries[iR]->getCantidadEpisodios(); iEpisodio++) {
                if (arrPtrSeries[iR]->getEpisodio(iEpisodio).getCalificacion() == dCal) {
                    cout << "Episodio: " << iEpisodio+1 << " " << arrPtrSeries[iR]->getEpisodio(iEpisodio).str() << endl;
                }
                
            }
            
        }
        
    }
    
}

void Series::consultaEpisodios(string ID) {
    Serie consulta;
    // Busca entre todas las series la que coincida con el id dado
    for (int iR = 0; iR < iCant; iR++) {
        if (arrPtrSeries[iR]->getId() == ID) {
            for (int iEpisodio = 0; iEpisodio < arrPtrSeries[iR]->getCantidadEpisodios(); iEpisodio++) {
                cout << "Episodio: " << iEpisodio+1 << " " << arrPtrSeries[iR]->getEpisodio(iEpisodio).str() << endl;
            }
            
        }
        
    }
    
}

Serie* Series::alta(string id, Episodio *ptr) {
    for (int i = 0; i < iCant; i++) {
        if (arrPtrSeries[i]->getId() == id) {
            // Da de alta el episodio en la serie con el id dado y returna el pointer de la serie.
            arrPtrSeries[i]->altaEpisodio(ptr);
            return arrPtrSeries[i];
        }
        
    }
    // En caso de que el id no exista imprime
    cout << "No existe!" << endl;
    return nullptr;
}


void Series::leerArchivo(){
    // File pointer
    fstream fin, fon;
    // Variables
    int iEpisodio = 0;

    int arrIdSerie[150];
    // Objetos
    Episodio *arrPtrEpisodio[150];
    Episodio *arrPtrEpi[5];
    
    // Open an existing file
    // Open de los archivos episodios y series.
    fin.open("Episodios.csv", ios::in);
    fon.open("ArchivoSerie.csv", ios::in);
    
    
    // Read the Data from the file
    // as String array
    string row[6];
    string line, word;

    while ( getline(fin, line)) {
        // read an entire row and 
        // store it in a string variable 'line'.
        
        cout << line << endl;
        // used for breaking words.
        stringstream s(line);
        
        // read every column data of a row and
        // store it in a string variable, 'word'
        int iR = 0;
        // extrae caracteres de s  y los almacena en word hasta que encuentra el delimitador ','
        while (getline(s, word, ',')) {
            // add all the column data
            // of a row to a vector
            row[iR++]=word;
        }

        arrPtrEpisodio[iEpisodio] = new Episodio();
        
        cout << "Serie: " << row[0] << "\n";
        cout << "Titulo: " << row[1] << "\n";
        cout << "Temporada: " << row[2] << "\n";
        cout << "Calificacion: " << row[3] << "\n";

        arrIdSerie[iEpisodio] = stoi(row[0]);
        // arrPtrEpisodio[iEpisodio]->setTitulo(row[1]);
        // arrPtrEpisodio[iEpisodio]->setTemporada(stoi(row[2]));
        // arrPtrEpisodio[iEpisodio]->setCalificacion(stod(row[3]));

        for (int iR = 0; iR < 5; iR++) {
           arrPtrEpi[iR] = nullptr;
        }
        //Asigna los valores en el objeto arrtrEpisodio en la posicion iEpisodio
        arrPtrEpisodio[iEpisodio] = new Episodio(row[1], stoi(row[2]), stod(row[3]));

        cout << "***" << arrPtrEpisodio[iEpisodio]->str() << endl;

        iEpisodio++;

    }
    fin.close();

    // imprime todos los episodios de todas las series.
    for (int iR = 0; iR < iEpisodio; iR++) {
        cout << "!" << arrPtrEpisodio[iR]->str() << endl;
    }
    

    cout << "========================================================== Reporte de Series =====================\n";

    iCant = 0;
    
    // Read the Data from the file
    // as String array

    while ( getline(fon, line)) {
        // read an entire row and 
        // store it in a string variable 'line'.
        
        cout << iCant << " : "<< line << endl;
        // used for breaking words.
        stringstream s(line);
        
        // read every column data of a row and
        // store it in a string variable, 'word'
        int iR = 0;
        // extrae caracteres de s  y los almacena en word hasta que encuentra el delimitador ','
        while (getline(s, word, ',')) {
            // add all the column data
            // of a row to a vector
            row[iR++]=word;
        }
        
        cout << "iD: " << row[0] << "\n";
        cout << "Titulo: " << row[1] << "\n";
        cout << "Duracion: " << row[2] << "\n";
        cout << "Genero: " << row[3] << "\n";
        cout << "Calificacion: " << row[4] << "\n";
        cout << "Episodios Totales: " << row[5] << "\n";

        // Asigna el valor del csv al episodio en la posicion del objeto donde va.
        /*
        arrPtrSeries[iCant]->setId(row[0]);
        arrPtrSeries[iCant]->setTitulo(row[1]);
        arrPtrSeries[iCant]->setDuracion(stoi(row[2]));
        arrPtrSeries[iCant]->setGenero(row[3]);
        arrPtrSeries[iCant]->setCalificacion(stoi(row[4]));
        arrPtrSeries[iCant]->setEpisodio(stoi(row[5]));
        */

       for (int iR = 0; iR < 5; iR++) {
           arrPtrEpi[iR] = nullptr;
       }

        // Una mejor manera de representar los sets y asigar los valores.
       arrPtrSeries[iCant] = new Serie(row[0], row[1], stoi(row[2]), row[3], stod(row[4]), stoi(row[5]), arrPtrEpi);
       
       int iE = 0;
       for (int iEpi = 0; (iEpi < iEpisodio) & (iE < 5); iEpi++) {
           if (arrIdSerie[iEpi] == stoi(row[0])) {
               //cout << "Si fue igual\n";
               //arrPtrEpi[iE] = arrPtrEpisodio[iEpi];

               arrPtrSeries[iCant]->setEpisodio(iE, arrPtrEpisodio[iEpi]);
               iE++;
           }
       }
        arrPtrSeries[iCant]->setCantidadEpisodios(iE);
        iCant = iCant + 1;
        
    }
    fon.close();
}


void Series::reporteConCalificacion(double calificacion) {
    for(int  iR = 0; iR < iCant; iR++){
        //validacion de la calificacion de la serie con la calificacion recibida.
        if (arrPtrSeries[iR]->getCalificacion() == calificacion) {
            cout << "Serie: " << arrPtrSeries[iR]->str() << endl;
        }
    }
}

void Series::reporteGenero(string sGenero) {
    for(int  iR = 0; iR < iCant; iR++){
        // validacion del genero de la serie con la recibida.
        if (arrPtrSeries[iR]->getGenero() == sGenero) {
            cout << "Serie: " << arrPtrSeries[iR]->str() << endl;
        }
    }
}

void Series::str() {
    double dPromedio;
    dPromedio = 0;
    for(int  iR = 0; iR < iCant; iR++){
        // Imprime todas las series con sus episodios.
        cout << "Serie: ";
        cout << arrPtrSeries[iR]->str() << endl;
        dPromedio = dPromedio + arrPtrSeries[iR]->getCalificacion();
    }
    cout << "Promedio Series: " << dPromedio / iCant << endl;
}

Serie* Series::getPtrSerie(string iSerie) {
    for (int iR = 0; iR < iCant; iR++) {
        // validacion del id de la serie con el introducido.
        if (arrPtrSeries[iR]->getId() == iSerie) {
            return arrPtrSeries[iR];   
        }
        
    }
    // Si no existe imprime
    cout << "No existe una serie con ese ID!" << endl;
    return nullptr; 
}

void Series::calcularPromedioXSerie() {
    for (int iR = 0; iR < iCant; iR++) {
        // Reasigna en la calificacion de cada una de las series usando calPromedio la cual 
        // obtiene la calificacion del promedio de los episodios.
        arrPtrSeries[iR]->setCalificacion(arrPtrSeries[iR]->calPromedio());
    }
}




#endif // !series_hpp
