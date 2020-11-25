// Alejandro Daniel González Carrillo A01570396
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

// Descripcion: Manejo de desbordamiento por dirección abierta
// Complejidad: O(n)
void open(vector<int> &vi, int cant, int dato) {
  int idx = dato % cant;
  if(vi[idx] == -1){
    vi[idx] = dato;
  } else {
    while(vi[idx] != -1){
      if(idx + 1 == cant){
        idx = (idx+1) % cant;
      }
      idx++;
      if(vi[idx] == -1){
        vi[idx] = dato;
        return;
      }
    }
  }
}

// Descripcion: Imprime el vector de integers.
// Complejidad: O(n)
void displayHash(vector<int> vi, int cant){
  for (int i = 0; i < cant; i++) {
    cout << i << " " << vi[i] << endl;
  }
}

// Descripcion: Carga el vector con valores -1, despues el usuario introduce el valor que sera introducido al vector.
// Complejidad: O(n)
void load(int cant, vector<int> &vi) {
  for (int i = 0; i < cant; i++) {
    vi.push_back(-1);
  }
  int dato;
  for (int i = 0; i < cant; i++) {
    cin >> dato;
    open(vi, cant, dato);
  }
  displayHash(vi, cant);
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
  vector<int> vi;
  cin >> n;
  primeNumber(n);
  load(n,vi);

  
  return 0;
}

/* 
5
100
200
543
123
4
*/