#include <iostream>
#define INTERES 0.1875

using namespace std;

int interesIterativo(int n, int c) {
    for (int i = 0; i < n; i++) {
        c += c*INTERES;
    }
    return c;
}

int interesRecursivo(int n, int c) {
    if (n == 0) {
        return 1;
    }
    int son = interesRecursivo(n-1,c);
    return son + (son * INTERES);
    
}

int main() {
    int n,c;
    cin >> n;
    cin >> c;
    cout << "Interes Iterativo: " << interesIterativo(n,c) << endl;
    cout << "Interes Recursivo: " << interesRecursivo(n,c) << endl;
    
    return 0;
}
