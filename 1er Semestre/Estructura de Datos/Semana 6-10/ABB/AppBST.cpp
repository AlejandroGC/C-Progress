// Alejandro Daniel González Carrillo
// A01570396
// Act 3.1 - Operaciones avanzadas en un BST

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
	miArbol.ancestors(18);
	cout << endl;
	cout << "Nivel: " << miArbol.whatlevelamI(18) << endl;
	cout << "Valor inexistente: " << miArbol.whatlevelamI(28) << endl;
	cout << "Pre Orden: ";
	miArbol.visit(1);
	cout << "In Orden: ";
	miArbol.visit(2);
	cout << "Post Orden: ";
	miArbol.visit(3);
	cout << "Nivel Orden: ";
	miArbol.visit(4);
	
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