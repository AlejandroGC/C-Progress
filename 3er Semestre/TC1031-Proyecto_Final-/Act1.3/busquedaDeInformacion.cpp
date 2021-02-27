#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura base de cada bitacora
struct datos {
    int key;
    string mes;
    int dia;
    string hora;
    string ip;
    string problema;
};

void imprimir(vector<datos> bitacora) {
  for(int i = 0; i < bitacora.size(); i++) {
      cout << bitacora[i].mes << " ";
      cout << bitacora[i].dia << " ";
      cout << bitacora[i].hora << " ";
      cout << bitacora[i].ip;
      cout << bitacora[i].problema << endl;
    }
}

// Cambia el mes a un valor para lograr despues ordenarlo.
int mesValor(string mes, int dia) {
  
  int mesInt;
  
  if (mes == "Jan") {
    mesInt = 100;
  } else if (mes == "Feb") {
    mesInt = 200;
  } else if (mes == "Mar") {
    mesInt = 300;
  } else if (mes == "Apr") {
    mesInt = 400;
  } else if (mes == "May") {
    mesInt = 500;
  } else if (mes == "Jun") {
    mesInt = 600;
  } else if (mes == "Jul") {
    mesInt = 700;
  } else if (mes == "Aug") {
    mesInt = 800;
  } else if (mes == "Sep") {
    mesInt = 900;
  } else if (mes == "Oct") {
    mesInt = 1000;
  } else if (mes == "Nov") {
    mesInt = 1100;
  } else {
    mesInt = 1200;
  }

  mesInt += dia;
  
  return mesInt;
}

// Lee los datos del txt y los guarda en una estructura que guarda en cada variable un valor.
void leerDatos(vector<datos> &bitacora) {
    ifstream fin;
    datos temp;
    fin.open("bitacora.txt");
    while (!fin.eof()) {
        fin >> temp.mes >> temp.dia >> temp.hora >> temp.ip;
        getline(fin,temp.problema);
        temp.key = mesValor(temp.mes, temp.dia);
        //cout << temp.key << " " << temp.mes << " " << temp.dia << " " << temp.hora << " " << temp.ip << temp.problema << endl;
        bitacora.push_back(temp);
    }
    fin.close();
}

void ordenaIntercambio(vector<datos> &bitacora) {
  int size = bitacora.size();
  datos temp;

  for(int i = 0;i < size-1;i++) {
    for(int j = i+1;j < size;j++) {
      if(bitacora[j].key < bitacora[i].key) {
        temp = bitacora[i];
        bitacora[i] = bitacora[j];
        bitacora[j] = temp;
      }
    }
  }
}

void altaDatos(vector<datos> bitacora) {
  ofstream outfile;

  outfile.open("ordenado.txt", ios::out);

  for(int i = 0; i < bitacora.size(); i++) {
    outfile << bitacora[i].mes << " " << bitacora[i].dia  << " " << bitacora[i].hora << " " << bitacora[i].ip << bitacora[i].problema << endl;
  }
}

void busqSecuencial(vector <datos> &bitacora,int lim1,int lim2) {
  vector<datos> aux;
  for(int i = 0;i < bitacora.size();i++) {
    if((bitacora[i].key >= lim1) && (bitacora[i].key <= lim2)) {
      aux.push_back(bitacora[i]);
    }
  }
  imprimir(aux);
  altaDatos(aux);
}

/*
void busqSecuencial(vector <datos> &bitacora,int lim1,int lim2) {
  vector<datos> aux;
  for(int i = 0;i < bitacora.size();i++) {
    if((bitacora[i].key >= lim1) && (bitacora[i].key <= lim2)) {
      aux.push_back(bitacora[i]);
    }
  }
  imprimir(aux);
  altaDatos(aux);
}
*/
int main() {
    vector<datos> bitacora;
    string mes,mesIni,mesFin;
    int dia,diaIni,diaFin;
    
    leerDatos(bitacora);

    ordenaIntercambio(bitacora);

    cout << "Fecha Inicial (Mes y Dia): ";
    cin >> mesIni;
    cin >> diaIni;

    int lim1 = mesValor(mesIni, diaIni);

    cout << "Fecha Final (Mes y Dia): ";
    cin >> mesFin;
    cin >> diaFin;

    int lim2 = mesValor(mesFin, diaFin);

    busqSecuencial(bitacora, lim1, lim2);
    
    return 0;
}