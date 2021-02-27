#include <iostream>

using namespace std;

int potenciaIterativa(int x, int y) { 
    int acum = 1;
    for (int i = 1; i <= y; i++) {
        acum *= x;
    }
    return acum;
}

int potenciaRecursiva(int x, int y) {
    if (y == 0) {
        return 1;
    }
    return potenciaRecursiva(x, y-1) * x;
}

int potenciaEficiente(int x, int y) {
    int tot = 1;
    while (y > 0) {
        if (y % 0)
        {
            /* code */
        }
        
    }
    
}

int main() {
    int x,y;
    cin >> x;
    cin >> y;
    cout << "Potencia iterativo:" << potenciaIterativa(x,y) << endl;
    cout << "Potencia recursivo:" << potenciaRecursiva(x,y) << endl;

    return 0;
}