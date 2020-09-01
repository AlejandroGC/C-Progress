#include <iostream>
#include <vector>
using namespace std;

int busqSec( vector<int> &v, int dato) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == dato) {
            return i;
        }
    }
    return -1;
    
}

// Complejidad O(log n) Mejor Caso: O(1)
int busqBin(vector<int> &v, int dato) {
    int ini=0, fin = v.size()-1, mit;
    while (ini <= fin) {
        mit = (ini+fin)/2;
        if (v[mit]==dato) {
            return mit;
        }
        if (v[mit] > dato) {
            fin = mit - 1;
        } else {
            ini = mit + 1;
        }
        
        
    }
    
}

int main() {
    vector<int> v;
    int n,q,dato;

    cin >> n;
    for (int i = 0; i < n; i++) {
        v.push_back(dato);
    }

    cin >>q;
    for (int i = 0; i < q; i++) {
        cout << busqSec(v, dato) << endl;
        cout << busqBin(v, dato) << endl;
    }
    
    
}