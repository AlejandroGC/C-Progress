/*
Alejandro Daniel Gonzalez Carrillo
A01570396
Proyecto Integrado Servicio de Streaming
*/

#include <string>
#include <iostream>
#include "peliculas.hpp"
#include "series.hpp"
// Desarrollo: 25 horas

using namespace std;

// Se hace input de los datos de una pelicula y estos se mantiene en una referencia.
void leerDatosPelicula(Pelicula &datosPelicula){
    int oscares;
    string id;
    string titulo;
    int duracion;
    string genero;
    double cPromedio;

    cout << "---Ingresa los datos de la pelicula---\n";
    cout << "Ingresa el iD: ";
    cin >> id;
    datosPelicula.setId(id);

    cin.ignore();
    cout << "\nIngresa el titulo: ";
    getline(cin,titulo);
    datosPelicula.setTitulo(titulo);
    cout << titulo << endl;

    cout << "\nIngresa la Duracion en minutos: ";
    cin >> duracion;
    while (duracion < 0) {
        cout << "\nIngresa un numero mas alto";
        cout << "\nIngresa la Duracion en minutos: ";
        cin >> duracion;
    }
    datosPelicula.setDuracion(duracion);



    cout << "\nIngresa Genero: ";
    cin >> genero;
    while (genero != "Drama" && genero != "Accion" && genero != "Misterio") {
        
        cout << "\nNo existe ese genero";
        cout << "\nIngresa otro genero: ";
        cin >> genero;
    }
    datosPelicula.setGenero(genero);

    cout << "\nIngresa Calificacion: ";
    cin >> cPromedio;
    while(cPromedio > 5 || cPromedio < 0) {
        cout << "\nTiene que ser un numero entre 0 y 5. \nVuelva a ingresar la calificacion: ";
        
        cin >> cPromedio;
    }
    datosPelicula.setCalificacion(cPromedio);

    cout << "\nIngresa Oscares: ";
    cin >> oscares;
    while (oscares < 0) {
        cout << "\nIngresa un numero mas alto";
        cout << "\nIngresa Oscares: ";
        cin >> oscares;
    }
    datosPelicula.setOscares(oscares);
}

// Se hace input de los datos de un episodio y estos se mantiene en una referencia.
void leerDatosEpisodio(Episodio &datosEpisodio){
    string titulo;
    int temporada;
    double calificacion;


    cout << "---Ingresa los datos de la pelicula---\n";
    cin.ignore();
    cout << "\nIngresa el titulo: ";
    getline(cin,titulo);
    datosEpisodio.setTitulo(titulo);
    cout << titulo << endl;
    

    cout << "\nIngresa la temporada: ";
    cin >> temporada;
    while (temporada < 0) {
        cout << "\nIngresa un numero mayor";
        cout << "\nIngresa la temporada: ";
        cin >> temporada;
    }
    datosEpisodio.setTemporada(temporada);

    cout << "\nIngresa Calificacion: ";
    cin >> calificacion;
    while(calificacion > 5 || calificacion < 0) {
        cout << "\nTiene que ser un numero entre 0 y 5. \nVuelva a ingresar la calificacion: ";
        cin >> calificacion;
    }
    datosEpisodio.setCalificacion(calificacion);
}

// Se correra el menu de presentacion de la plataforma de streaming
int menuPeliculas(){
    int iOpcion;
    cout << ".*.*.*.*.*.*Peliculas.*.*.*.*.*.*"
    << "\n1. Leer Peliculas desde Archivo" //listo
    << "\n2. Alta Pelicula"  //listo
    << "\n3. Reporte de todas las peliculas" //listo
    << "\n4. Reporte con Calificacion" //listo
    << "\n5. Reporte por genero (Drama, Accion, Misterio)" // listo
    << "\n6. Cambiar Oscares de la Pelicula (cantOscares)" // listo
    << "\n\n.*.*.*.*.*.*Series.*.*.*.*.*.*" 
    << "\n7. Leer Series desde Archivo" // listo
    << "\n8. Reporte de todas las series" // listo
    << "\n9. Reporte de series con Calificacion" // listo
    << "\n10. Reporte de series por genero (Drama, Accion, Comedia, Suspenso, Misterio, Fantasia)" //listo
    << "\n11. Agregar un episodio de una serie (idSerie)" // listo
    << "\n12. Calcular calificacion de serie en base a la calificacion de los episodios - (sobrecargar +)" // listo
    << "\n\n.*.*.*.*.*.*Episodios.*.*.*.*.*.*"
    << "\n13. Consulta todos los Episodios de una Serie (idSerie)" // listo
    << "\n14. Consulta todos los Episodios de una Serie con calificacion (idSerie, calificacion)" // listo
    << "\n\n0. Salir"
    << "\n\nTeclea la opcion: ";
    cin >> iOpcion;
    return iOpcion;
}

// Donde se corre todo nuestro codigo. Todo surge de aqui.
int main(){
    // Objetos de las Clases
    Peliculas peliculas;
    Pelicula *ptrPelicula;
    Series series;
    Episodio *ptrEpisodio;

    // Variables
    int iOpcion, iOscares;
    double iCal;
    string genero, iD;
    
    // Se leen series y peliculas.
    peliculas.leerArchivo();
    series.leerArchivo();
    cout << "Se leyeron los archivos." << endl << endl;
    // Inicio del menu
    iOpcion = menuPeliculas();
    while(iOpcion != 0){
        cout << "A01570396 - Alejandro Daniel Gonzalez Carrillo" << endl;
        switch (iOpcion){
            case 1:
                // Lee el csv de peliculas y registra todas las peliculas dentro del codigo.
                peliculas.leerArchivo();
                break;
            case 2:
                // Damos de alta una nueva pelicula, generamos una desde cero, la llenamos enviando el pointer a leerDatosPelicula
                // La agregamos al arr de peliculas y la damos de alta con altapelicula.
                ptrPelicula = new Pelicula();
                leerDatosPelicula(*ptrPelicula);
                peliculas.setPtrPelicula(ptrPelicula);
                peliculas.altaPelicula(ptrPelicula);
                break;
            case 3:
                // Obtenemos un reporte completo de todas las peliculas con su calificacion.
                peliculas.str();
                break;
            case 4:
                // Es un filtro el cual le damos un valor de calificacion entre 0 y 5 y nos devuelve las peliculas que su
                // calificacion sea igual a la calificacion dada.
                cout << "Ingresa la calificacion: ";
                cin >> iCal;
                // Validacion de que calificacion sea un numero entre 0 y 5
                while (iCal > 5 || iCal < 0)
                {
                    cout << "Ingresa un valor entre 0 y 5";
                    cout << "Ingresa la calificacion de nuevo: ";
                    cin >> iCal;
                }
                peliculas.reporteConCalificacion(iCal);
                break;
            case 5:
                // Es un filtro al cual le damos un genero y esta los valida si existe o no y nos regresa 
                // las peliculas que tengan ese mismo genero.
                cout << "Ingresa el genero: ";
                cin >> genero;
                while (genero != "Drama" && genero != "Accion" && genero != "Misterio") {
                    cout << "\nNo existe ese genero. Las opciones son: Drama, Accion y Misterio";
                    cout << "\nIngresa otro genero: ";
                    cin >> genero;
                }
                peliculas.reporteGenero(genero);
                break;
            case 6:
                // Este caso nos permite cambiar la cantidad de oscares dependiendo del id y la cantidad que le demos.
                cout << "Ingrese id de la pelicula: ";
                cin >> iD;
                cout << "Ingresa la cantidad de oscares: ";
                cin >> iOscares;
                while (peliculas.getPtrPelicula(iD)->getOscares() > iOscares) {
                    cout << "Es menor la cantidad de oscares de los que ya tenia Ingresa de nuevo la cantidad de oscares: ";
                    cin >> iOscares;
                }
                
            
                // Se hace una validacion de si el id existe o no.
                if (peliculas.getPtrPelicula(iD) != nullptr) {
                    // Nos muestra la cantidad de oscares antes
                    cout << "Cantidad de oscares actuales del ID: " << iD << endl << "Oscares antes: " << peliculas.getPtrPelicula(iD)->getOscares() << endl;
                    // Cambia la cantidad de oscares
                    cout << peliculas.getPtrPelicula(iD)->str() << endl;
                    peliculas.getPtrPelicula(iD)->setOscares(iOscares);
                    // Nos muestra la cantidad de oscares despues
                    cout << "Oscares despues: " << peliculas.getPtrPelicula(iD)->getOscares() << endl;
                    peliculas.cambiarOscares();
                    peliculas.str();
                }
                break;
            case 7:
                // Lee el csv de las series y el de los episodios. Estos son cargados en objetos las clases.
                series.leerArchivo();
                break;
            case 8:
                // Imprime un reporte que muestra todas las peliculas con sus epidosios.
                series.str();
                break;
            case 9:
                // Es un filtro para mostrar las peliculas que tengan las calificacion dada por el usuario.
                cout << "Ingresa la calificacion: ";
                cin >> iCal;
                // Validacion tiene que ser un numero entre 0 y 5.
                while (iCal > 5 || iCal < 0) {
                    cout << "Ingresa un valor entre 0 y 5";
                    cout << "Ingresa la calificacion: ";
                    cin >> iCal;
                }
                series.reporteConCalificacion(iCal);
                break;
            case 10:
                // Es un filtro que en base al genero que le introduzcas se muestran nomas las series que tienen ese genero.
                cout << "Ingresa el genero: ";
                cin >> genero;
                // Validacion solo se pueden introducir las opciones validadas por el if.
                while (genero != "Drama" && genero != "Accion" && genero != "Misterio" && genero != "Suspenso" && genero != "Comedia" && genero != "Fantasia") {
                    cout << "\nNo existe ese genero, las opciones son: Drama, Accion, Misterio, Suspenso, Fantasia y Comedia.";
                    cout << "\nIngresa otro genero: ";
                    cin >> genero;
                }
                series.reporteGenero(genero);
                break;
            case 11:
                // Este caso es muy similar al de dar de alta un episodio
                // Le introducimos un id en el cual se va a agregar el episodio.
                cout << "Ingresa el id de la serie: ";
                cin >> iD;
                // Validacion del id que exista.
                if (series.getPtrSerie(iD) != nullptr) {
                    // creamos un nuevo episodio
                    ptrEpisodio = new Episodio();
                    // lo cargamos con los valores que conlleva hacer un episodio.
                    leerDatosEpisodio(*ptrEpisodio);
                    // Se da de alta la serie en el arr de la serie del id que introducimos.
                    series.alta(iD,ptrEpisodio);
                    cout << "Se actualizo la serie. " << endl;
                    series.str();
                }
                break;
            case 12:
                // Calcula el promedio correcto de las series en base a sus episodios.
                // ES NECESARIO CORRER ESTE CODIGO CADA VEZ QUE HAGAMOS UN CAMBIO EN LOS EPISODIOS.
                // Se utiliza la sobrecarga del operador +.
                series.calcularPromedioXSerie();
                series.str();
                break;
            case 13:
                // Este caso muestra todos los episodios de un id que nosotros le introduzcamos.
                cout << "Ingresa el ID: ";
                cin >> iD;
                // Validacion de que el id exista.
                if (series.getPtrSerie(iD) != nullptr) {
                    series.consultaEpisodios(iD);
                }
                
                break;
            case 14:
                // Este caso muestra todos los episodios de un id y una calificacion que nosotros le introduzcamos.
                cout << "Ingresa el ID: ";
                cin >> iD;
                cout << "Ingresa la calificacion: ";
                cin >> iCal;
                // Validacion de la calificacion que le demos, entre 0 y 5.
                while (iCal > 5 || iCal < 0) {
                    cout << "Ingresa un valor entre 0 y 5";
                    cout << "Ingresa la calificacion: ";
                    cin >> iCal;
                }
                // Validacion del id de una serie para checar que exista.
                if (series.getPtrSerie(iD) != nullptr) {
                    series.consultaEpisodiosConCalificacion(iD,iCal);
                }
                break;
            default:
                cout << "Error, opcion no existe. \n";
                break;
        }
        iOpcion = menuPeliculas();
    }
    return 0;
}
