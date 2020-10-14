#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

#include "BST.h"

int main(){
	stack<int> stk;
	queue<int> fila;
	BST miArbol;
	miArbol.add(7);
	miArbol.add(10);
	miArbol.add(21);
	miArbol.add(40);
	miArbol.add(6);
	miArbol.add(18);
	miArbol.add(9);
	miArbol.add(5);
	miArbol.add(2);
	miArbol.add(1);
	cout << "Altura: " << miArbol.height() << endl;
	cout << "Ancestros: ";
	miArbol.printAncestors(18);
	cout << endl;
	cout << "Nivel: " << miArbol.whatlevelamI(18) << endl;
	cout << "Pre Orden: ";
	miArbol.printPre();
	cout << "In Orden: ";
	miArbol.printPre();
	cout << "Post Orden: ";
	miArbol.printPost();
	cout << "Nivel Orden: ";
	miArbol.printNivel();
	
	// cout << "Cantidad de datos: "<< miArbol.size()<< endl;
	// miArbol.remove(10);
	// miArbol.printPre();
	// cout << "Cantidad de datos: "<< miArbol.size()<< endl;
/*	if (miArbol.search(21))
		cout  << "SI encontre al 21"<< endl;
	else
		cout << "NO encontre al 21" << endl;
	if (miArbol.search(100))
		cout  << "SI encontre al 100"<< endl;
	else
		cout << "NO encontre al 100" << endl;
	if (miArbol.search(7))
		cout  << "SI encontre al 7"<< endl;
	else
		cout << "NO encontre al 7" << endl;
*/
	return 0;
}