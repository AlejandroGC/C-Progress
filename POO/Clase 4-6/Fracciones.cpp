#include <iostream>
#include "Fracciones.hpp"
using namespace std;


Fracciones::Fracciones() {
    iNum = 0;
    iDen = 1;
}

Fracciones::Fracciones(int num, int den) {
    if (num >= 0) {
        iNum = num;
    } else {
        iNum = - num;
    };

    if (den > 0) {
        iDen = den;
    }
    if (den < 0) {
        iDen = - den;
    }
    
}
void Fracciones::setNum(int num) {
    iNum = num;
}

int Fracciones::getNum() {
    return iNum;
}

void Fracciones::setDen(int den) {
    iDen = den;
}

int Fracciones::getDen() {
    return iDen;
}

string Fracciones::show() {
    if(iDen == 1){
		return to_string(iNum) + " / " + to_string(iDen);
	} else {
	int b=2;
	while(b <= iNum){
		if(iDen%b==0 && iNum%b==0){
			iDen = iDen / b;
			iNum = iNum / b;
            b = 2;
		} else {
		    b++;
		}
	}
	
	}
    return to_string(iNum) + " / " + to_string(iDen);
}

double Fracciones::strFlotante() {
    return double(iNum) / double(iDen);
}

void Fracciones::input() {
    cout << "Ingresa el numerador: ";
    cin >> iNum;
    cout << "Ingresa el denominador: ";
    cin >> iDen;
}

void Fracciones::output() {
    cout << iNum + " / " + iDen << endl;
}

ostream & operator << (ostream &out, const Fracciones &f){
  out << f.iNum << endl;
  out << "____" << endl << f.iDen << endl;
  return out;
}

Fracciones & Fracciones::operator ++(){
  cout << "++Prefijo" << endl;
  iNum++;
  iDen++;
  return *this;
}

Fracciones Fracciones::operator ++(int iF){
  cout << "Sufijo" << endl;
  Fracciones f1(iNum, iDen);
  iNum++; iDen++;
  return f1;
}

