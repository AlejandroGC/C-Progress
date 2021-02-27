#include <iostream>

int main()
{
    using namespace std;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int a = 5;
    int *ptrA = &a, b, *ptrB; 
    b = 10;
    ptrB = &b;

    /*  Pointer
        Almacena la direccion de memoria de una variable. 
        & obtener la direccion de memoria de una variable.
    */ 

    cout << "El valor de a: " << a << endl;
    cout << "El valor de ptrA: " << ptrA << endl;
    cout << "El valor de ptrA: " << *ptrA << endl;
    cout << "El valor de ptrB: " << ptrB << endl;
    cout << "El valor de ptrB: " << *ptrB;
    
    return 0;
}
