// Alejandro Daniel González Carrillo A01570396
// Agustin Blanco Oliver A00828415
// Act 5.2 - Actividad Integral sobre el uso de códigos hash (Evidencia Competencia)
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <unordered_map>

using namespace std;

struct ipStruct{
  string fecha;
  string problema;
};

// Complejidad: O(1)
// Descripcion: Convierte el IP de int a string.

string ipToString(string ipLong) {
  int pos = ipLong.find(":");
  ipLong.erase(pos);
  return ipLong;
}

// Complejidad: O(n)
// Descripcion: Lee los datos del archivo y los mete al unordered map.

void leerDatos(unordered_map<string,vector<ipStruct>> &hashmap) {
  ifstream fin;
  string mes, dia, hora, ip;
  ipStruct ipIdeal;
  fin.open("bitacoraACT5_2.txt");
  while (!fin.eof()) {
    fin >> mes >> dia >> hora >> ip;
    fin.ignore();
    getline(fin,ipIdeal.problema);
    ip = ipToString(ip);
    ipIdeal.fecha = mes + " " + dia + " " + hora;
    hashmap[ip].push_back(ipIdeal);
  }
  fin.close();
}

// Complejidad: O(n)
// Descripcion: Imprime el unordered map.

void print(unordered_map<string,vector<ipStruct>> hashmap, string ip) {
  cout << "Existen: " << hashmap[ip].size() << " accesos." << endl;
  for(auto i : hashmap[ip]){
    cout << ip << " " << i.fecha << " " << i.problema << endl;
  }
}

int main(){
  unordered_map<string,vector<ipStruct>> hashmap;
  leerDatos(hashmap);
  cout << "Procesando...." << endl;
  string ip;
  while(ip != "0"){
    cout << "Exit: 0" << endl;
    cout << "IP: ";
    cin >> ip;
    if(ip != "0") {
      print(hashmap, ip);
    }
  }

  return 0;
}