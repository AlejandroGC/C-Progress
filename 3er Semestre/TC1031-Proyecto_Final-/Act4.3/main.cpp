// Alejandro Daniel González Carrillo A01570396
// Agustin Blanco Oliver A00828415
// Act 4.3 - Actividad Integral de Grafos

#include <bits/stdc++.h>
using namespace std;

// Complejidad: O(n)
// Descripcion: Convierte el IP de string a int, asi mismo, remueve el puerto.
string ipToString(string ipLong) {
  int pos = ipLong.find(":");
  ipLong.erase(pos);
  return ipLong;
}

// Complejidad: O(n)
// Descripcion: Lee, almacena los datos en una lista de adyacencia y regresa el valor maximo de outdegrees.
int loadGraph(int &n, int &m, unordered_map<string,pair<int,int>> &nodos_ips, vector<vector<int>> &listAdj) {
  ifstream fin;
  string mes, dia, hora, ip, ipsale, ipentra, problema;
  fin.open("bitacoraACT4_3_B.txt");
  fin >> n >> m;
  listAdj.resize(n);
  for(int i=0; i<n; i++) {
    fin >> ip;
    pair<int, int> dato;
    dato.first = i;
    dato.second = 0;
    nodos_ips[ip] = dato;
  }
  int maximo = 0;
  for(int i=0; i<m; i++) {
    fin >> mes >> dia >> hora >> ipsale >> ipentra;
    fin.ignore();
    getline(fin,problema);
    ipsale = ipToString(ipsale);
    ipentra = ipToString(ipentra);
    //cout << ipsale << " " << ipentra << endl;
    //cout << nodos_ips[ipsale].first-1 << " " << nodos_ips[ipentra].first-1 << endl;
    nodos_ips[ipsale].second++;
    if(nodos_ips[ipsale].second > maximo){
      maximo = nodos_ips[ipsale].second;
    }
    listAdj[nodos_ips[ipsale].first].push_back(nodos_ips[ipentra].first);
  }
  fin.close();
  return maximo;
}

// Complejidad: O(n^2)
// Descripcion: Imprime la lista de adyacencia.
void printListAdj(vector<vector<int>> &listAdj) {
	for (int i=0; i<listAdj.size(); i++) {
		cout << (i+1);
		for (int j=0; j<listAdj[i].size(); j++) {
			cout << " - " << (listAdj[i][j]+1);
		}
		cout << endl;
	}
}

// Complejidad: O(n)
// Descripcion: Imprime el IP, su ID y el numero de outdegree del máximo.
void printNodos_ips(unordered_map<string,pair<int,int>> &nodos_ips, int max) {
	for (auto i : nodos_ips) {
    if(max == (i.second).second) {
		  cout << i.first << " : " << (i.second).second << endl;
    }
  }
}

int main() {
  int n,m,max;
  vector<vector<int>> listAdj;
  unordered_map<string,pair<int,int>> nodos_ips;
  max = loadGraph(n,m,nodos_ips,listAdj);
  //printListAdj(listAdj);
  printNodos_ips(nodos_ips, max);
  
  return 0;
}