// Alejandro Daniel Gonzalez Carrillo A01570396
// Act 4.2 - Grafos: Algoritmos complementarios
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Complejidad: O(n)
// Descripcion: Carga los arcos del grafo y los almacena en  una Lista de Adjacencia
void loadGraph(vector<vector<int>> &listAdj, int m, vector<int> &indegree){
	int a, b, c;
	for (int i=1; i<=m; i++){
		cin >> a >> b >> c;
		listAdj[a-1].push_back(b-1);
		indegree[b-1]++;
	}
}

// Complejidad: O(n+m)
// Descripcion: Se realiza el Depth First Search para buscar.
bool DFS(vector<vector<int>> &listAdj, vector<bool> &visit, int inicio){
	stack<int> stack;
	int nodoInicial = inicio-1;
	stack.push(nodoInicial);
	int contadorVisitado = 0;
	int dato;

	while(!stack.empty() && contadorVisitado != listAdj.size()){
		dato = stack.top();
		stack.pop();
		if(!visit[dato]){
			// cout << dato + 1 << " ";
			visit[dato] = true;
			contadorVisitado++;
			for(int j = listAdj[dato].size()-1; j >= 0; j--){
				if(!visit[listAdj[dato][j]]){
					stack.push(listAdj[dato][j]);
				} else {
					return true;
				}
			}
		} else {
			return true;
		}

	}
	cout << endl;
	return false;
}

// Complejidad: O(n+m)
// Descripcion: Dice si el Grafo Dirigido es un árbol o no.
bool isTree(vector<vector<int>> &listAdj, int n, int m, int inicio) {
	vector<bool> visit(listAdj.size(), false);
			
	bool ciclo = DFS(listAdj, visit, inicio);

	for(int i = 0; i < visit.size(); i++){
		if(!visit[i] || ciclo || m != n-1){
			return false;
		}
	}
	return true;
}

// Complejidad: O(n+m)
// Descripcion: Despliega en orden topológico el grafo.
void topologicalSort(int n, int m, vector<vector<int>> listAdj, vector<int> indegree){
	vector<int> output;
	queue<int> q;
	for(int i=0; i<n; i++){
		if(indegree[i] == 0){
			q.push(i);
		}
	}

	while(!q.empty()){
		int currentNode = q.front();
		q.pop();
		output.push_back(currentNode);
		for(int i=0; i<listAdj[currentNode].size(); i++){
			int neighbor = listAdj[currentNode][i];
			indegree[neighbor]--;
			if(indegree[neighbor] == 0){
				q.push(neighbor);
			}
		}
	}
	if(output.size() != n){
		cout << "Es ciclico, debido a que no estan ordenados los datos." << endl;
		return;
	}

	for(int i=0; i<output.size(); i++){
		cout << output[i]+1 << " ";
	}
}

// Complejidad: O(n+m)
// Descripcion: Checa para cada uno de los vertices si sus vecinos tienen el color contrario mediante recursion.
bool bipartite(vector<vector<int>> &listadj, int vertices, vector<bool> &visited, vector<int> &colors){
	for(int u : listadj[vertices]){
		if(visited[u] ==false){
			visited[u] = true;
			colors[u] = !colors[vertices];
			if(!bipartite(listadj,u,visited,colors)){
				return false;
			} else if (colors[u] == colors[vertices]){
				return false;
			}
		}
	}
	return true;
}

// Complejidad: O(n+m)
// Descripcion: Dice si el Grafo Dirigido puede ser representado como Grafo bipartita.
bool bipartiteGraph(vector<vector<int>> &listAdj, int n, int m, int inicio) {
	vector<bool> visited(n, false);
	vector<int> colors(n, -1);

	visited[inicio] = true;
	colors[inicio] = 0;

	if(isTree(listAdj,n,m, inicio)){
		return true;
	} else {
		for(int i=0; i<n; i++){
			if(colors[i] == -1) {
				if(bipartite(listAdj, i, visited, colors) == false){
					return false;
				}
			}
		}
	}

	return true;

}

int main(){
	int n, m, inicio;
	cin >> n >> m >> inicio;
	if(inicio == 0){
		inicio++;
	};
	vector<vector<int>> listAdj(n);
	vector<int> indegree(n);
	loadGraph(listAdj, m, indegree);
	isTree(listAdj, n, m, inicio) ? cout << "Esto es un arbol." << endl : cout << "Esto NO es un arbol." << endl;
	cout << "Topological Sort: ";
	topologicalSort(n, m, listAdj, indegree);
	bipartiteGraph(listAdj,n,m, inicio) ? cout << "Es un grafo bipartito." : cout << "NO es un grafo bipartito." << endl;


	return 0;
}

/* Test Cases

BIPARTITO Y ARBOL, 1 2 3 5 4 7 6
7 6 1
1 2 1
2 3 1
2 5 1
3 4 1
4 6 1
5 7 1

BIPARTITO, 1 2 3 4 Y NO ARBOL
4 6 1
1 2 10
1 3 8
1 4 6
2 3 15
2 4 12
3 4 3


NO ARBOL, ES CICLICO Y BIPARTITA
6 18 0
1 2 0
1 4 0
1 6 0
2 1 0
2 3 0
2 5 0
3 2 0
3 4 0
3 6 0
4 1 0
4 3 0
4 5 0
5 2 0
5 4 0
5 6 0
6 1 0
6 3 0
6 5 0

*/
