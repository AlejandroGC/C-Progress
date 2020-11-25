// Alejandro Daniel Gonzalez Carrillo A01570396
// Act 4.1 - Grafo: sus representaciones y sus recorridos
#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define N 10

// Complejidad: O(n)
// Descripcion: Carga los arcos del grafo y los almacene en una Matriz de Adjacencia y en una Lista de Adjacencia
void loadGraph(vector<vector<int>> &listAdj, bool matAdj[N][N], int m){
    int a, b, c;
	for (int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			matAdj[i][j] = false;
		}
	}
	for (int i=1; i<=m; i++){
		cin >> a >> b >> c;
		listAdj[a-1].push_back(b-1);
		listAdj[b-1].push_back(a-1);
		matAdj[a-1][b-1] = matAdj[b-1][a-1] = true;
	}
}

// Complejidad: O(Vertices + Edges) -> O(n + m)
// Descripcion: Imprime el Recorrido de DFS (Profundidad) a partir de nodo inicial.
void DFS(vector<vector<int>> &listAdj, int nodoInicial){
    stack<int> stack;
	vector<bool> status(listAdj.size(), false);

	stack.push(nodoInicial - 1);
	
	int contadorVisitado = 0;
	int dato;
	while(!stack.empty() && contadorVisitado != listAdj.size()){
		dato = stack.top();
		stack.pop();
		if(!status[dato]){
			cout << dato + 1 << " ";
			status[dato] = true;
			contadorVisitado++;
			for(int j = listAdj[dato].size()-1; j >= 0; j--){
				if(!status[listAdj[dato][j]]){
					stack.push(listAdj[dato][j]);
				}
			}
		}

	}
	cout << endl << endl;
	for (int i=0; i<listAdj.size(); i++){
		cout << (i+1)<< " ";
		for (int j=0; j< listAdj[i].size(); j++){
			cout << " - " << (listAdj[i][j]+1);
		}
		cout << endl;
	}
}

// Complejidad: O(Vertices + Edges) -> O(n + m)
// Descripcion: Imprime el Recorrido de BFS (Anchura) a partir de nodo inicial.o. 
void BFS(bool matAdj[N][N], int n, int nodoInicial){
	queue<int> fila;
	int arranque = nodoInicial-1, dato;
	fila.push(arranque); 
	vector<bool> status(n, false);
	status[arranque] = true;
	while(!fila.empty()){
		dato = fila.front();
		cout << (dato+1) << " ";
		fila.pop();
		for(int j = 0; j<n; j++){
			if(matAdj[dato][j] && !status[j]){
				fila.push(j);
				status[j] = true;
			}
		}
	}
	cout << endl << endl;

	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cout << (matAdj[i][j]) << " ";
		}
		cout << endl;
	}
}

int main() {
    int n,m, nodoInicial;
    cin >> n >> m >> nodoInicial;
    vector<vector<int>> listAdj(n);
    bool matAdj[N][N];
    
	loadGraph(listAdj, matAdj, m);
	
	cout << endl << "DFS" << endl;
    DFS(listAdj, nodoInicial);
	cout << endl << "BFS" << endl;
    BFS(matAdj, n, nodoInicial);

    return 0;
}

/*
Caso Prueba
4 6 2
1 2 10
1 3 8
1 4 6
2 3 15
2 4 1
3 4 3
*/
