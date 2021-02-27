#include <iostream>
#include <vector>
using namespace std;

// Intercambio:
// Complejidad: O(n^2)
// Descripcion: Ordena los datos con el método de Intercambio.

int ordenaIntercambio(vector <int> &v) {

  int cont = 0;
  int temp;
  int size = v.size();

  for(int i = 0;i < size-1;i++) {
    for(int j = i+1;j < size;j++) {
      cont++;
      if(v[j] < v[i]) {
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
      }
    }
  }

  return cont;
}

// Bubble Sort:
// Complejidad: O(n^2)
// Descripcion: Ordena los datos con el método de Bubble Sort.

int ordenaBurbuja(vector <int> &v) {
  
  int cont = 0;
  int temp;
  int size = v.size();
  bool interruptor = true;

  for(int i = 0;i < size-1 && interruptor;i++) {
    interruptor = false;
    for(int j = 0;j < size-1-i;j++) {
      cont++;
      if(v[j+1] < v[j]) {
        temp = v[j+1];
        v[j+1] = v[j];
        v[j] = temp;
        interruptor = true;
      }
    }
  }

  return cont;
}

// Merge Sort:
// Complejidad: O(n log n)
// Descripcion: Ordena los datos con el método de Merge Sort.

int une(vector <int> &v,vector <int> &va,int ini,int fin) {
  
  int cont = 0;
  int m = (ini+fin)/2;
  int i = ini;
  int j = m+1;
  int k = ini;

  while(i <= m && j <= fin) {
    cont++;
    if(v[i] <= v[j]) {
      va[k++] = v[i++];
    }
    else {
      va[k++] = v[j++];
    }
  }

  while(i <= m) {
    va[k++] = v[i++];
  }

  while(j <= fin) {
    va[k++] = v[j++];
  }

  for(int z = ini;z <= fin;z++) {
    v[z] = va[z];
  }
  
  return cont;
}

int ordenaMerge(vector <int> &v,vector <int> &va,int ini,int fin) {

  int cont = 0;
  int m;

  if(ini < fin) {
    m = (ini+fin)/2;
    cont += ordenaMerge(v,va,ini,m);
    cont += ordenaMerge(v,va,m+1,fin);
    return cont + une(v,va,ini,fin);
  }

  return cont;
}

// Búsqueda Secuencial:
// Complejidad: O(n)
// Descripcion: Busca datos con el método de Búsqueda Secuencial.

int busqSecuencial(vector <int> &v,int clave,int &contBS) {

  contBS = 0;

  for(int i = 0;i < v.size();i++) {
    contBS++;
    if(v[i] == clave) {
      return i;
    }
  }

  return -1;
}

// Búsqueda Binaria:
// Complejidad: O(log n)
// Descripcion: Busca datos con el método de Búsqueda Binaria.

int busqBinaria(vector <int> &v,int clave,int &contBB) {
  
  contBB = 0;

  int ini = 0;
  int fin = v.size()-1;
  int m;

  while(ini <= fin) {
    m = (ini+fin)/2;
    contBB++;
    if(v[m] == clave) {
      return m;
    }
    if(v[m] < clave) {
      ini = m+1;
    }
    if(v[m] > clave) {
      fin = m-1;
    }
  }

  return -1;
}

int main() {

  int n,q,dato,clave,contBS,contBB;
  vector <int> v1,v2,v3,va(n);

  //cout << "N: ";
  cin >> n;

  for(int i = 0;i < n;i++) {

    //cout << "Dato: ";
    cin >> dato;

    v1.push_back(dato);
    v2.push_back(dato);
    v3.push_back(dato);
  }

  cout << ordenaIntercambio(v1) << " ";
  cout << ordenaBurbuja(v2) << " ";
  cout << ordenaMerge(v3,va,0,n-1) << endl;

  //cout << "Q: ";
  cin >> q;

  for(int i = 0;i < q;i++) {

    //cout << "Clave: ";
    cin >> clave;

    if(busqSecuencial(v1,clave,contBS) == busqBinaria(v1,clave,contBB)) {
      cout << busqSecuencial(v1,clave,contBS) << " ";
      cout << contBS << " " << contBB << endl;
    }
  }

  return 0;
}