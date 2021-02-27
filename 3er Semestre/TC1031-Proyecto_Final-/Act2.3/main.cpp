// Alejandro Daniel González Carrillo A01570396
// Agustin Blanco Oliver A00828415
// Act 2.3 - Actividad Integral Estructura de Datos Lineales (Evidencia Competencia)

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;

#include "DoublyLinkedList.h"

// Complejidad: O(n)
// Descripcion: Le da una estructura de tipo long long a la IP.
long ipToLong(string ip) {
	int idx = 0;
	long datoFinal= 0, dato = 0;
	while (idx < ip.size()){
		if (ip[idx]!= '.' && ip[idx]!=':'){
			dato = dato*10 + ip[idx]-'0';
		}
		else{
			datoFinal = datoFinal*1000 + dato;
			dato = 0;
		}
		idx++;
	}
	datoFinal = datoFinal*10000 + dato;
	return datoFinal;
}

// Complejidad: O(n)
// Descripcion: Lee datos de un archivo de texto y los almacena dentro de la Double Linked List.
void leerDatos(DoublyLinkedList &Lista) {
    ifstream fin;
    datos temp;
    fin.open("bitacora.txt");
    while (!fin.eof()) {
        fin >> temp.mes >> temp.dia >> temp.hora >> temp.ip;
        getline(fin,temp.problema);
        temp.key = ipToLong(temp.ip);
        Lista.addLast(temp);
    }
    fin.close();
}


int main() {
  // Creamos la double linked List
  DoublyLinkedList Lista;
  // Llenamos la DLL de los datos de la bitacora.txt
  leerDatos(Lista);
  // Ordena los datos dentro de la DLL utilizando bubble sort
  Lista.sort();

  // Variable inicial y final que se introducen en el ipToLong
  string ipIni, ipFin;
  // Variables donde se guardaran los valores del ipToLong
  long ipInicial, ipFinal;

  cout << "Introducir IP Inicial: ";
  cin >> ipIni;
  ipInicial = ipToLong(ipIni);
  cout << "Introducir IP Final: ";
  cin >> ipFin;
  ipFinal = ipToLong(ipFin);

  // Busca, filtra, imprime y guarda en el nuevo archivo ordena.txt los valores dentro del rango mencionado anteriormente
  Lista.search(ipInicial, ipFinal);

  return 0;
}