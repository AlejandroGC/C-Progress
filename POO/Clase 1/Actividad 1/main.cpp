#include <iostream>
#include "RelojD.cpp"
#include "Fecha.cpp"
// #include "Evento.h"
#include "Evento.cpp"
#include <conio.h>
using namespace std;


#if defined(__WIN32__) || defined(_WIN32) || defined(WIN32) || defined(__WINDOWS__) || defined(__TOS_WIN__)

#include <windows.h>

#else  /* presume POSIX */

  #include <unistd.h>

#endif
//Despiega las funciones
int menu () {
  //Se establecen variables
  int iOpcion;
  cout << "\nMenú de Opciones \n" <<
  "1.Crear objeto Hora \n" <<
  "2.setHora  \n" <<
  "3.setMinutos  \n" <<
  "4.getHora  \n" <<
  "5.getMinutos  \n" <<
  "6.Incrementar minutos \n" <<
  "7.Desplegar Objeto \n" <<
  "8.Reloj \n" <<
  "9. Incrementa 100 minutos \n" <<
  "10. Crear evento de Fiesta \n" <<
  "11. Introducir fecha \n" <<
  "12. Obtener dias del mes \n" <<
  "13. Obtener nombre del mes \n" <<
  "0.Terminar programa \n" <<
  "Teclea la opcion:";
  //Se pide y regresa la opcion elegida
  cin >> iOpcion;
  return iOpcion;
}

int main () {
  //Se establecen variables
  int iOpcion, iHr, iMin, iD, iM, iY;
  string nombreMes;

  //Construccion del objeto
  RelojD iReloj;
  Evento eventoFiesta;
  Evento evento2;
  Fecha iFecha;
  //Mientras iOpcion no sea 0, se pregunta la funcion a ejecutar
  do {
    //Se manda a llamar la funcion que despliega las funciones
    iOpcion = menu();
    switch (iOpcion) {
      case 0:
        //Se termia el programa
        cout << "\n<<Fin del programa>> \n";
        break;
      case 11:
        cout << "Ingresa el dia:";
        cin >> iD;
        cout << "Ingresa el mes:";
        cin >> iM;
        cout << "Ingresa el year:";
        cin >> iY;
        iFecha = Fecha(iD,iM,iY);
        getch();
        break;
      case 12:
        iFecha.diasMes();
        getch();
        break;
      case 13:
        nombreMes = iFecha.mes();
        cout << nombreMes;
        getch();
        break;
      case 1: // "1.Crear objeto Hora \n"
        //Se indica que el reloj ya habia sido contruido anteriormente
        //Se piden los datos iniciales para construir el objeto
        cout << "Ingresa la Hora:";
        cin >> iHr;
        cout << "Ingresa los minutos:";
        cin >> iMin;
        iReloj = RelojD(iHr,iMin);
       
        break;
      case 2: // 2.setHora
        //El usuario cambia las horas
        cout << "\n**Método modificador setHoras**\n" <<
        "Ingresa la hora:";
        cin >> iHr;
        //Se accede al metodo setHoras de la clase RelojD
        iReloj.setHoras(iHr);
        break;
      case 3:  // 3.setMinutos
        //El usuario cambia los minutos
        cout << "\n**Método modificador setMinutos**\n" <<
        "Ingresa los minutos:";
        cin >> iMin;
        //Se llama al metodo serMinutos de la clase RelojD
        iReloj.setMinutos(iMin);
        break;
      case 4: // 4.getHora
        cout << "Hora:" << iReloj.getHora() << endl;
        break;
      case 5: // 5. getMinutos
        cout << "Minutos:" << iReloj.getMin() << endl;
        break;
      case 6: // 6. Incrementar minutos
        cout << endl << iReloj.str() << endl;
        iReloj.incrementaMinutos();
        cout << endl << iReloj.str() << endl;
        break;
      case 7: // 7.Desplegar Objeto
        cout << endl << iReloj.str() << endl;
        break;
      case 8: // 8.Reloj
       cout << endl << iReloj.str() << endl;
        while (iReloj.getHora() <= 23){
            
            cout << "ya" << endl;
            iReloj.incrementaMinutos();
            cout << endl << iReloj.str() << endl;
        }
        break;
      case 9: // 9. Incrementa 1000 minutos
        for (int iK = 0; iK <= 1000; iK++)
        {
          cout << endl << iReloj.str() << endl;
          iReloj.incrementaMinutos();
        }
        break;
      case 10: // 10. Crear evento de Fiesta
        cout << eventoFiesta.str() << endl;
        eventoFiesta.setDuracion(400);
        eventoFiesta.setAsunto(" 🎄 Fiesta de Navidad 2020 🎄");
        eventoFiesta.setHora(iReloj);
        cout << eventoFiesta.str() << endl;
       break;
      default: // Opcion incorrecta
        //En caso de ingresar una opcion inexistente, se
        //despliega el mensaje
        cout << "\n<<ERROR>> \n" <<
        "Opcion no existente \n";
    }
  } while (iOpcion != 0);
  return 0;
}

