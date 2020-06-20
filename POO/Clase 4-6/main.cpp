// Alejandro Gonzalez
// A01570396
// Trabajo en Clase SobreCarga

#include <stdio.h>
#include <iostream>
#include "Fracciones.cpp"

using namespace std;

Fracciones suma(Fracciones f1, Fracciones f2) {
    int iNum, iDen;
    if (f1.iDen == f2.iDen) {
        iNum = f1.iNum + f2.iNum;
        iDen = f1.iDen;
    } else {
        iNum = (f1.iNum * f2.iDen + f1.iDen * f2.iDen);
        iDen = (f1.iDen * f1.iDen);
    }

    Fracciones nuevo(iNum, iDen);
    return nuevo;
    
}

int menu(){
    int iOpcion;
    cout << "\n1. Ingresa la Fraccion1:";
    cout << "\n2. Ingresa la fraccion2:";
    cout << "\n3. f1 + f2 ";
    cout << "\n4. f1 - f2 ";
    cout << "\n5. f1 * f2 ";
    cout << "\n6. f1 / f2 ";
    cout << "\n7. f1 < f2 ";
    cout << "\n8. f1++ ";
    cout << "\n9. ++f1 ";
    cout << "\n10. f1 ";
    cout << "\n11. f2 ";
    cout << "\n12. Friend ";
    cout << "\n0. Salir";
    cout << "\nTeclea la opcion:";
    cin >> iOpcion;
    return iOpcion;
}
int main() {
    Fracciones f1(3,5), f2(1,5);
    Fracciones f3(3,5), f4(2,6);
    Fracciones resultado;
    int iOpcion, iNum, iDen;
    // resultado = f1 + f2;
    // cout << f1.show() << " + " << f2.show() << "= " << resultado.show() << endl;
    // resultado = f3 + f4;
    // cout << f3.show() << " + " << f4.show() << "= " << resultado.show() << endl;
    
    // Inicializar la vcc antes del ciclo
    iOpcion = menu();
    while (iOpcion != 0) {
        switch (iOpcion) {
            case 1:
                f1.input();
                f1.output();
                break;
            case 2:
                f2.input();
                f2.output();
                break;
            case 3:
                resultado = f1 + f2;
                cout << f1.show() << " + " << f2.show() << " = " << resultado.show() <<  " = " << resultado.strFlotante()<< endl;
                break;
            case 4:
                resultado = f1 - f2;
                cout << f1.show() << " - " << f2.show() << " = " << resultado.show() <<  " = " << resultado.strFlotante()<< endl;
                break;
            case 5:
                resultado = f1 * f2;
                cout << f1.show() << " * " << f2.show() << " = " << resultado.show() <<  " = " << resultado.strFlotante()<< endl;
                break;
            case 6:
                resultado = f1 / f2;
                cout << "(" << f1.show() << ") / (" << f2.show() << ") = " << resultado.show() <<  " = " << resultado.strFlotante()<< endl;
                break;
            case 7:
                if (f1 == f2){
                  cout << f2.show() << " < " << f1.show() << endl;
                }
            case 8:
                cout << f1++;
                cout << f1;
                break;
            case 9:
                cout << ++f1;
                break;
            case 10:
                cout << f1;
                break;
            case 11:
                cout << f2;
                break;
            case 12:
                cout << suma(f1, f2) << endl;
                break;
            default:
                break;
        }
        // Actualizar la vcc dentro del ciclo
        iOpcion = menu();
    }// fin while
    
    return 0;
}
