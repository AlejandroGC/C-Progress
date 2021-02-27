// Alejandro Daniel González Carrillo A01570396
// Agustin Blanco Oliver A00828415
// Act 3.4 - Actividad Integral de BST (Evidencia Competencia)

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

#include "BST.h"

// Complejidad: O(n)
// Descripcion: Recibe el ip como string pero regresa el valor long quitandole el puerto y los puntos.
long ipToLong(string ip) {
	int idx = 0;
	long datoFinal = 0, dato = 0;
	while (ip[idx]!=':'){
		if (ip[idx]!= '.'){
			dato = dato*10 + ip[idx]-'0';
		}
		else{
			datoFinal = datoFinal*1000 + dato;
			dato = 0;
		}
		idx++;
	}
	datoFinal = datoFinal*1000 + dato;
	return datoFinal;
}

// Complejidad: O(n)
// Descripcion: Recibe el ip en formato string y le quita el puerto regresando el ip sin puerto en formato string
string ipToString(string ipLong) {
  int pos = ipLong.find(":");
  ipLong.erase(pos);
  return ipLong;
}

// Complejidad: O(n)
// Descripcion: Lee los datos de la bitacora ordenada y les asigna una variable, se envian al nodo del arbol 3 variables el ipAnterior, el contador de ips y el ip sin el puerto pero con su formato.
void leerDatos(BST &tree) {
    ifstream fin;
    string mes, dia, hora, ip, problema;
    int ipCont = 1;
    long ipAnt = 0;
    string ipString = "0";
    fin.open("bitacoraOrdenada.txt");
    while (!fin.eof()) {
        fin >> mes >> dia >> hora >> ip;
        getline(fin,problema);
        long key = ipToLong(ip);
        if(key != ipAnt && ipCont > 0) {
          tree.add(ipAnt,ipCont,ipString);
          ipAnt = key;
          ipCont = 1;
          ipString = ipToString(ip);
        } else {
          ipCont++;
        }
    }
    tree.add(ipAnt,ipCont, ipString);
    fin.close();
}

int main(){

  BST tree;

  leerDatos(tree);

  tree.printIn();
  
  return 0;
}