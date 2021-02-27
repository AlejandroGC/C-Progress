// Matricula: A01570396
// Nombre: Alejandro Daniel González Carrillo
#include <iostream>
using namespace std;
// Complejidad: O(n)
int cuantos(int inf, int sup) {
    int acum = 0;
    for (int i = inf; i <= sup; i++)
    {
        if (i % 15 == 0)
        {
            acum++;
        }
    }
    return acum;
    
    
}

int cuantos2(int inf, int sup) {
    int cont = 0;
    int inicio = (inf%15==0 ? inf : inf + 15 - inf%15);
    for (int i = inicio; i <= sup; i+=15) {
        cont++
    }
    return cont;
    

}

int cuantos3(int inf, int sup) {
    return (sup/15 - inf/15) + (inf%15==0 ? 1 : 0);
}

int main() {

    int inf, sup;

    cin >> inf >> sup;

    cout << cuantos(inf, sup) << endl;
}
