// Alejandro Daniel González Carrillo A01570396
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

// Descripcion: Manejo de desbordamiento por encadenamiento
// Complejidad: O(1)
void chain(vector<vector<int>> &vi, int cant, int dato) {
  int idx = dato % cant;
  vi[idx].push_back(dato);
}

// Descripcion: Imprime el vector de vectores int.
// Complejidad: O(n^2)
void displayHash(vector<vector<int>> vi, int cant){
  cout << "Chain: " << endl;
  for (int i = 0; i < cant; i++) {
    cout << i;
    for(auto x: vi[i]){
      cout << " --> " << x;
    }
    cout << endl;
  }
}

// Descripcion: El usuario introduce el dato a guardar en la tabla.
// Complejidad: O(n)
void load(int cant, vector<vector<int>> vi) {
  int dato;
  for(int i=0; i<cant; i++){
    cin >> dato;
    chain(vi, cant, dato);
  }
  displayHash(vi,cant);
}

// Descripcion: Identifica si el numero cantidad de datos a ingresar es un numero primo, sino cambia al numero primo siguiente.
// Complejidad: O(n)
void primeNumber(int &n){
  if (n == 0 || n == 1) {
    n++;
    primeNumber(n);
  }
  else {
    for (int i = 2; i <= n / 2; ++i) {
      if (n % i == 0) {
        n++;
        primeNumber(n);
      }
    }
  }

}

int main() {
  int n;
  cin >> n;
  primeNumber(n);
  vector<vector<int>> vi(n);
  load(n,vi);

  
  return 0;
}

/* 
4
100
200
543
123
4
*/