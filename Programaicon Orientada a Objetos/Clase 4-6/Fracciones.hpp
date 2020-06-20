#ifndef Fracciones_hpp
#define Fracciones_hpp

#include <string>
using namespace std;

#include <stdio.h>
class Fracciones{
private:
    int iNum, iDen;
public:
    // Constructor default : 0/1  2/4 debe ser 1/2
    Fracciones();
    
    // Constructor con parámetros :todos positivos
    Fracciones(int,int);
    // método set cambia el valor del numerador
    void setNum(int);
    // get retorna el valor del numerador
    int getNum();
    // set cambia el valor del denominador
    void setDen(int);
    // get retorna el valor del denominador
    int getDen();
    // str retorna iNum/iDen
    string show();
    // strPtoFlotante la forma en punto flotante ? 1/2 = "0"
    double strFlotante();
    // Lee una fraccion
    void input();
    // despliega la fraccion
    void output(); 
    
    friend Fracciones suma(Fracciones, Fracciones);
    
    // - Sobrecarga de operadores aritméticos -
   
    // Suma de dos Fracciones
     Fracciones operator +(Fracciones f2){
        Fracciones resp;
         if (iDen == f2.iDen) {
             resp.setNum(iNum + f2.iNum);
             resp.setDen(iDen);
        } else {
             resp.setNum(iNum * f2.iDen + iDen * f2.iNum);
             resp.setDen(iDen * f2.iDen);
        }
         return resp;
     }
    
    // Resta de dos Fracciones
    Fracciones operator-(Fracciones f2){
        Fracciones resp;
        if (iDen == f2.iDen)
        {
            resp.iNum = iNum - f2.iNum;
            resp.iDen = iDen;
        } else {
            resp.iNum = iNum * f2.iDen - iDen * f2.iNum;
            resp.iDen = iDen * f2.iDen;
        }
        return resp;
    }

    Fracciones operator*(Fracciones f2){
        Fracciones resp;
            resp.iNum = iNum * f2.iNum;
            resp.iDen = iDen * f2.iDen;
        return resp;
    }

    Fracciones operator/(Fracciones f2){
        Fracciones resp;
            resp.iNum = iNum * f2.iDen;
            resp.iDen = iDen * f2.iNum;
        return resp;
    }
   
   bool operator <(Fracciones f2) {
       if ((double(iNum) / f2.iNum) < (double(iDen) / f2.iDen)) {
           return true;
       }

       return false; 
   }

    bool operator >(Fracciones f2) {
       if ((double(iNum) / f2.iNum) > (double(iDen) / f2.iDen)) {
           return true;
       }

       return false; 
   }
    
    bool operator ==(Fracciones f2) {
       if ((double(iNum) / f2.iNum) == (double(iDen) / f2.iDen)) {
           return true;
       }

       return false; 
   }

   Fracciones & operator ++ ();
    Fracciones operator++(int);
    friend ostream & operator << (ostream &out, const Fracciones &f);

   
};

#endif /* Fracciones_hpp */

