#include <iostream>

using namespace std;

int main(){
    int precio;
    float iva, precioFinal = 0;

    cout<<"Introduce el precio del producto: "<<endl;
    cin>>precio;
    cout<<"Introduce el valor del iva en %: "<<endl;
    cin>>iva;

    iva = iva / 100;
    iva = precio * iva;
    precioFinal = precio + iva;

    cout<<"\nEl precio final con iva es: "<<precioFinal<<endl;

    return 0;
}