#include <iostream>

using namespace std;

int main(){
    int saldo_inicial = 1000, opc;
    float extra, saldo = 0, retirar;

    cout<<"\nBienvenido a tu cajero virtual!"<<endl;
    cout<<"1. Ingresa dinero en tu cuenta."<<endl;
    cout<<"2. Retirar dinero de la cuenta."<<endl;
    cout<<"3. Salir"<<endl;
    cout<<"Opcion: "<<endl;
    cin>>opc;

    switch(opc){
        case 1:
            cout<<"Digite la cantidad de dinero a ingresar: ";
            cin>>extra;

            saldo = saldo_inicial + extra;
            cout<<"Dinero en cuenta: "<<saldo;break;
        case 2:
            cout<<"Digite la cantidad de dinero que va retirar: ";
            cin>>retirar;

            if(retirar > saldo_inicial){
                cout<<"NO tiene esa cantidad de dinero.";
            } else {
                saldo = saldo_inicial - retirar;
                cout<<"Dinero en cuenta actual: "<<saldo;

            }
        case 3: break;

    }



    return 0;
}