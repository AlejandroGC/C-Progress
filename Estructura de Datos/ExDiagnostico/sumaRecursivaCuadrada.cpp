// Matricula: A01570396
// Nombre: Alejandro Daniel González Carrillo
#include <iostream>
#include <math.h>

using namespace std;

// Complejidad: O(n) 
int sumaRecursivaCuadrada(int n){
    if (n == 0)
    {
        return 0;
    }
    return sumaRecursivaCuadrada(n-1) + pow(n,2);
    
}

int main(){
	int n;
	cin >> n;
	cout << sumaRecursivaCuadrada(n) << endl;
}