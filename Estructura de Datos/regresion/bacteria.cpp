#include <iostream>
#define NACEN 3.78
#define MUERE 2.34
using namespace std;

long long bacteriaIterativa(int n) {
    long long b = 1;
    for (int i = 0; i < n; i++) {
        b += ((b * NACEN) - (b * MUERE));
    }
    return b;
    
}

long long bacteriaRecursiva(int n) {
    if (n == 0) {
        return 1;
    }
    int son = bacteriaRecursiva(n - 1);
    return son + (son * NACEN) - (son * MUERE);

}

int main() {
    int n;
    cin >> n;
    cout << "bacteria iterativo:" << bacteriaIterativa(n) << endl;
    cout << "bacteria recursivo:" << bacteriaRecursiva(n) << endl;

    return 0;
}