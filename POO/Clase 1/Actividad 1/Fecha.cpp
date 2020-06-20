#include "Fecha.h"


//	👩‍🏭👨‍🏭 Constructor default
Fecha::Fecha(){
  iDia = 1;
  iMes = 1;
  iYear = 1900;
}

//	👩‍🏭👨‍🏭 Constructor con parámetros
Fecha::Fecha(int iD, int iM, int iY){
  iDia = iD;
  iMes = iM;
  iYear = iY;
}

// 🎮 🔏 Metodos modificadores 
void Fecha::setDia(int iD){
  iDia = iD;
}
void Fecha::setMes(int iM){
  iMes = iM;
}
void Fecha::setYear(int iY){
  iYear = iY;
}

//💳 🔓  Metodos de acceso
int Fecha::getDia (){
  return iDia;
}
int Fecha::getMes(){
  return iMes;
}
int Fecha::getYear(){
  return iYear;
}

//	💃🏻🕺🏽 Otros métodos
void Fecha::diaSiguiente(){
     iDia = 10;
     iMes = 10;
     iYear = 2010;
}

string Fecha::str(){
  string a(30,'-');
  a = "\n"+ a + "\n";
  return a;
}

// Programar el método que retorna la cantidad de dias que tiene el mes actual
void Fecha::diasMes(){
  if(iMes == 1 || iMes == 3 || iMes == 5 || iMes == 7 || iMes == 8 || iMes == 10 || iMes == 12) {
    cout << "El mes " << iMes << " tiene " << "31 dias.";
  } else if (iMes == 2 && iYear % 4 == 0 && (iYear % 100 != 0 || iYear % 400 == 0)) {
    cout << "El mes " << iMes << " tiene " << "29 dias.";
  } else if (iMes == 2) {
    cout << "El mes " << iMes << " tiene " << "28 dias.";
  } else {
    cout << "El mes " << iMes << " tiene " << "30 dias.";
  }
}
// Programar el método que retorna el nombre del mes en string
string Fecha::mes(){
  string meses[12] = {"Enero","Febrero","Marzo","Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
  return meses[iMes - 1];
}
