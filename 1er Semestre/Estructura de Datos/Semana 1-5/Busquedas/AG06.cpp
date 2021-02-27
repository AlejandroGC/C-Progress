#include <iostream>
#include <vector>

using namespace std;

int intercambio(vector<int> &vec) {
    int cont = 0, tam = vec.size(), temp;
    for (int i = 0; i < tam-1; ++i) {
        for (int j = i+1; j < tam; ++j) {
            cont++;
            if (vec[i] > vec[j]) {
                temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
    return cont;
}

int burbuja(vector<int> &vec) {
    int cont = 0, tam = vec.size(), temp;
    bool interruptor = true;
    for (int pas = 0; pas < tam-1 && interruptor; ++pas) {
        interruptor = false;
        for (int j = 0; j < tam-1-pas; ++j) {
            cont++;
            if (vec[j+1] < vec[j]) {
                temp = vec[j+1];
                vec[j+1]  = vec[j];
                vec[j] = temp;
                interruptor = true;
            }
        }
    }
    return cont;
}

int selMayor(vector<int> &vec) {
    int indiceMayor, tam = vec.size(), temp, cont = 0;
    for (int i = 0; i < tam; i++) {
        indiceMayor = 0;
        for (int j = 1; i < tam-i; i++) {
            cont++;
            if (vec[j] > vec[indiceMayor]) {
                indiceMayor = j;
            }
        }
        if (indiceMayor != (tam-1-i)) {
            temp = vec[indiceMayor];
            vec[indiceMayor] = vec[tam-1-i];
            vec[tam-1-i] = temp;
        }
        
    }
    return cont;
}

int insercion(vector<int> &vec) {
    int temp, tam = vec.size(), j, cont = 0;
    for (int i = 1; i < tam; i++) {
        j = i;
        temp = vec[i];
        while (j > 0 && temp < vec[j-1]) {
            cont++; // comparacion en verdadero
            vec[j] = vec[j-1];
            j--;
        }
        if (j != 0) {
            cont++;
        }
        vec[j] = temp;
    }
    return cont;
    
}

int print(vector<int> &vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << i << ": " << vec[i] << endl;
    }
    
}

int particion(vector<int> &vec, int ini, int fin, int &pivote) {
    int elempivote = vec[ini], j = ini, cant = 0, temp;
    for (int i = ini+1; i <= fin; i++) {
        cant++;
        if (vec[i] < elempivote) {
            j++;
            temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;
        }
    }
    pivote = j;
    temp = vec[j];
    vec[ini] =vec[pivote];
    vec[pivote] = temp;
    return cant;
}

int quick(vector<int> &v, int ini, int fin) {
    int cant = 0, pivote;
    if (ini < fin) {
        cant += particion(v, ini, fin, pivote);
        cant += quick(v, ini, pivote-1);
        cant += quick(v, pivote+1, fin);
    }
    
}

int main() {
    int n, dato;
    cin >> n;
    vector<int> vec1, vec2, vec3, vec4, vec5;

    for (int i = 0; i < n; i++) {
        cin >> dato;
        vec1.push_back(dato);
        vec2.push_back(dato);
        vec3.push_back(dato);
        vec4.push_back(dato);
        vec5.push_back(dato);
    }
    cout << intercambio(vec1) << endl;
    cout << burbuja(vec2) << endl;
    cout << selMayor(vec3) << endl;
    cout << insercion(vec4) << endl;
    cout << "Intercambio: " << endl;
    cout << print(vec1) << endl;
    cout << "Burbuja: " << endl;
    cout << print(vec2) << endl;
    cout << "Seleccion: " << endl;
    cout << print(vec3) << endl;
    cout << "Insercion: " << endl;
    cout << print(vec4) << endl;
    cout << "Quick: " << endl;
    cout << print(vec5) << endl;
}