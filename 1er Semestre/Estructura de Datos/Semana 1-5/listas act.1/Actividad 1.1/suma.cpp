// Alejandro Daniel Gonzalez Carrillo A01570396
// El codigo hace una sumatoria factorial en un cierto numero de casos. La sumatoria se hace de manera iterativa, recursiva y directa.
// 24/08/2020
// Programación de estructuras de datos y algoritmos fundamentales (Gpo 14)

#include <iostream>

using namespace std;

// La suma factorial de forma iterativa utilizando un for.
// Complejidad lineal
long sumaIterativa(long k) {
    long acum = 0;
    for (int i = 1; i <= k; i++) {
        acum += i;
    }
    return acum;
}

// La suma factorial de forma recursiva utilizando la misma funcion.
// Complejidad lineal
long sumaRecursiva(long k) {
    if (k <= 1) {
        return 1;
    }
    return k + sumaRecursiva(k-1); 
    
    
}

// La suma factorial de forma directa utilizando una formula.
// Complejidad lineal
long sumaDirecta(long k) {
    k = (k*(k+1)/2);
    return k;
}

int main() {
    int n;
    long k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        cout << sumaIterativa(k) << " " << sumaRecursiva(k) << " " << sumaDirecta(k)<< endl;
    }
    
    
    return 0;
}
