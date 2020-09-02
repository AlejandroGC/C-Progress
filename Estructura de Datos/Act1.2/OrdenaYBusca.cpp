#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int intercambio(vector<int> vec) {
    int cont = 0, aux, tam = vec.size();
    for (int i = 0; i < tam-1; i++) {
        for (int j = i+1; j < tam; j++) {
            cont++;
            if (vec[i] > vec[j]) {
                aux = vec[i];
                vec[i] = vec[j];
                vec[j] = aux;
            }
        }
    }
    return cont;

}

int burbuja(vector<int> vec) {
    int cont = 0, tam = vec.size(), aux;
    bool interruptor = true;
    for (int i = 0; i < tam-1 && interruptor; i++) {
        interruptor = false;
        for (int j = 0; j < tam-1-i; j++) {
            cont++;
            if (vec[j+1] < vec[j]) {
                aux = vec[j+1];
                vec[j+1] = vec[j];
                vec[j] = aux;
                interruptor = true;
            }
        }
    }
    return cont;
}

int mergeSort(vector<int> vec, int ini, int fin) {
    if (ini < fin) {
        int m = (ini + fin)/2;
        mergeSort(vec,ini,m);
        mergeSort(vec,m+1,fin);
        merge(vec,ini,m,fin);
    }
    return 
}

int merge(vector<int> vec, int ini, int m, int fin) {
    if (/* condition */)
    {
        /* code */
    }
    
}

int main() {
    int n, q, dato;
    cin >> n;
    vector<int> vec1, vec2;

    for (int i = 0; i < n; i++) {
        cin >> dato;
        vec1.push_back(dato);
    }
/*
    for (int i = 0; i < q; i++) {
        cin >> dato;
        vec2.push_back(dato);
    }
*/  
    int ini = 0, fin = vec1.size();
    cout << intercambio(vec1) << " " << burbuja(vec1) << " " << mergeSort(vec1,ini,fin) << endl; 

    return 0;
}