// Alejandro Daniel Gonzalez Carrillo
// A01570396
// Act 1.2 - Algoritmos de Búsqueda y Ordenamiento

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// Complejidad: O(n^2)
int intercambio(vector<int> &vec) {
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

// Complejidad: O(n^2)
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

// Complejidad: O(nlog(n))
int merge(vector<int> &vec, vector<int> &aux, int ini, int fin) {
    int m = (ini+fin)/2;
    int i = ini, j = m+1, k = ini;
    int cant = 0;
    while (i <= m && j <= fin) {
        cant++;
        if (vec[i] <= vec[j]) {
            aux[k++] = vec[i++];
        } else {
            aux[k++] = vec[j++];
        }
    }
    while (i <= m) {
        aux[k++] = vec[i++];
    }
    while (j <= fin) {
        aux[k++] = vec[j++];
    }
    for (int z = ini; z <= fin; z++) {
        vec[z] = aux[z];
    }
    return cant;
}

int mergeSort(vector<int> &vec, vector<int> &aux,int ini, int fin) {
    int cant = 0;
    if (ini < fin) {
        int m = (ini + fin)/2;
        cant += mergeSort(vec,aux,ini,m);
        cant += mergeSort(vec,aux,m+1,fin);
        cant += merge(vec,aux,ini,fin);
    }
    return cant;
}

// Complejidad: O(n)
int busqSecuencial(vector<int> &v, int dato, int &cantBS) {
    cantBS = 0;
    for (int i = 0; i <= v.size()-1; i++) {
        cantBS++;
        if (v[i] == dato) {
            return i;
        }
    }
    return -1;
}
// Complejidad: O(log(n))
int busqBin(vector<int> &v, int dato, int &cantBB) {
    int ini=0, fin = v.size()-1, mit;
    cantBB = 0;
    while (ini <= fin) {
        mit = (ini+fin)/2;
        cantBB++;
        if (v[mit]==dato) {
            return mit;
        }
        if (v[mit] > dato) {
            fin = mit - 1;
        } else {
            ini = mit + 1;
        }
        

    }
    return -1;
}

int main() {
    int n, q, dato, cantBS, cantBB;
    cin >> n;
    vector<int> vec1, vec2, vec3, aux(n);

    for (int i = 0; i < n; i++) {
        cin >> dato;
        vec1.push_back(dato);
        vec2.push_back(dato);
        vec3.push_back(dato);
    }

    cout << intercambio(vec1) << " ";
    cout << burbuja(vec2) << " ";
    cout << mergeSort(vec3,aux,0,n-1) << endl;

    cin >> q;

    for (int i = 0; i < q; i++) {
        cin >> dato;
        if (busqSecuencial(vec1,dato,cantBS) == busqBin(vec1,dato,cantBB)) {
            cout << busqSecuencial(vec1,dato,cantBS) << " " << cantBS << " " << cantBB << endl;
        }
        
    }


    return 0;
}