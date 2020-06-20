#ifndef peliculas_hpp
#define peliculas_hpp
#include "pelicula.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

class Peliculas : public Pelicula{
    private:
        Pelicula *arrPtrPeliculas[100];
        int iCant; 
    public:
        //constructor
        Peliculas();
        // Lee el csv de peliculas
        void leerArchivo();
        // Reporta el listado de todas las peliculas con la calificacion que se introduce al metodo.
        void reporteConCalificacion(double);
        // Reporta el listado de todas las peliculas con el genero que se introduce al metodo.
        void reporteGenero(string);
        // Imprime la base video con pelicula y con todas las peliculas;
        void str();
        // Reasignar el valor de los oscares ya asigandos desde un inicio.
        void cambiarOscares();
        // Asigna algun cambio a la pelicula recibida.
        void setPtrPelicula(Pelicula *ptr);
        // Verifica que el id de la pelicula exista.
        Pelicula* getPtrPelicula(string);
        // Da de alta la pelicula recibida en el csv.
        void altaPelicula(Pelicula *ptr); 
};

Peliculas::Peliculas(){
    iCant = 0;
    for (int i = 0; i < 100; i++) {
        arrPtrPeliculas[i] = nullptr;
    }
}


void Peliculas::altaPelicula(Pelicula *ptr) {
    // file pointer
    fstream fout;
    
    // opens an existing csv file or creates a new file.
    fout.open("Peliculas.csv", ios::out | ios::app);
    
    
    int duracion, oscares;
    string titulo, genero, id;
    double calificacion;

    // Read the input
        id = ptr->getId();
        titulo = ptr->getTitulo();
        duracion = ptr->getDuracion();
        genero = ptr->getGenero();
        calificacion = ptr->getCalificacion();
        oscares = ptr->getOscares();
        
        
        // Insert the data to file
        fout << id << ", "
        << titulo << ", "
        << duracion << ", "
        << genero << ", "
        << calificacion << ", "
        << oscares
        << "\n";

        cout << "Se dio de alta la pelicula: " << titulo << endl;
    
    fout.close();
}


void Peliculas::leerArchivo(){
    // File pointer
    fstream fin;
    
    // Open an existing file
    fin.open("Peliculas.csv", ios::in);
    
    
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

        arrPtrPeliculas[iCant] = new Pelicula();
        
        
        cout << "iD " << row[0] << " : \n";
        cout << "Titulo: " << row[1] << "\n";
        cout << "Duracion: " << row[2] << "\n";
        cout << "Calificacion: " << row[4] << "\n";
        cout << "Genero: " << row[3] << "\n";
        cout << "Oscares: " << row[5] << "\n";

        // Lee y asigna los valores del csv en el programa dentro del objeto pelicula
        arrPtrPeliculas[iCant]->setId(row[0]);
        arrPtrPeliculas[iCant]->setTitulo(row[1]);
        arrPtrPeliculas[iCant]->setDuracion(stoi(row[2]));
        arrPtrPeliculas[iCant]->setGenero(row[3]);
        arrPtrPeliculas[iCant]->setCalificacion(stod(row[4]));
        arrPtrPeliculas[iCant]->setOscares(stoi(row[5]));
        

        cout << arrPtrPeliculas[iCant]->str() << endl;
        iCant = iCant + 1;
    }
    fin.close();
}

void Peliculas::cambiarOscares(){
        for (int i = 0; i < iCant; i++) {
            int oscar = arrPtrPeliculas[i]->getOscares();
            // Obtiene la pelicula a la cual se le cambiaran los oscares y ha esta le hace cambian 
            // la calificacion en base a la cantidad de oscares.
            if(oscar != 0){
                arrPtrPeliculas[i]->setCalificacion(calPromedio(arrPtrPeliculas[i]->getCalificacion(),oscar));
            }
        }
}

void Peliculas::reporteConCalificacion(double calificacion){
    for(int  iR = 0; iR < iCant; iR++){
        // Valida que la calificacion de la pelicula sea igual a la que se introdujo.
        if (arrPtrPeliculas[iR]->getCalificacion() == calificacion) {
            cout << "Pelicula: " << iR+1 << " ";
            cout << arrPtrPeliculas[iR]->str() << endl;
        }
    }
}

void Peliculas::reporteGenero(string genero) {
    for(int  iR = 0; iR < iCant; iR++){
        // Valida que el genero de la pelicula sea igual que el introducido.
        if (arrPtrPeliculas[iR]->getGenero() == genero) {
            cout << "Pelicula: " << iR+1 << " ";
            cout << arrPtrPeliculas[iR]->str() << endl;
        }   
    }
}

void Peliculas::str(){
    double dPromedio;
    dPromedio = 0;
    cout << "id       titulo      duracion     genero     calificacion     oscares\n";
    cout <<"-------------------------------------------------------------------------\n";
    // Imprime todas las peliculas y el promedio de calificacion de todas las peliculas.
    for(int  iR = 0; iR < iCant; iR++){
        cout << "Pelicula: " << iR+1 << " ";
        cout << arrPtrPeliculas[iR]->str() << endl;
        dPromedio = dPromedio + arrPtrPeliculas[iR]->getCalificacion();    
    }
    cout << "Promedio Peliculas: " << dPromedio / iCant << endl << endl;
}


void Peliculas::setPtrPelicula(Pelicula *ptr){
    // Agrega el pointer de pelicula al arr de ptr de peliculas.
    arrPtrPeliculas[iCant++] = ptr;
}

Pelicula* Peliculas::getPtrPelicula(string id) {
    // Validacion de que el id existe
    for (int i = 0;i < iCant; i++) {
        if (arrPtrPeliculas[i]->getId() == id) {
            return arrPtrPeliculas[i];
        }
        
    }
    // Si no existe imprime
    cout << "No existe el ID!" << endl << endl;
    return nullptr;
    
}


#endif // !peliculas.hpp

