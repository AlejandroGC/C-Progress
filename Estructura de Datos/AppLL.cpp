#include <iostream>

using namespace std;

#include "LinkedList.h"

int main(){
	LinkedList<string> lista;
	lista.addLast("HOLA");
	lista.addLast("CRAYOLA");
	lista.addFirst("AQUI");
	lista.addLast("ESTOY");
	lista.print();
	cout << "--------"<<endl;
/*
	lista.add("MTY",1);
	lista.print();
	cout << "--------"<<endl;
	lista.change(3,1);
	lista.print();
	cout << "--------"<<endl;
	lista.del(2);
	lista.print();
	cout << "--------"<<endl;	
	lista.deleteFirst();
	lista.print();
	cout << "--------"<<endl;
	lista.addFirst("WICHO");
	lista.print();
	cout << "--------"<<endl;
	lista.deleteLast();
	lista.print();
	cout << "--------"<<endl;
	cout << lista.getSize()<<endl;
	cout << lista.get(2)<<endl;
	cout << lista.set("ABC",1)<<endl;
	lista.print();
	cout << "--------"<<endl;

	lista.deleteAll();
	lista.addFirst("SOY RAYADO");
	lista.addLast("Y GANAREMOS EL CLASICO");
	lista.addLast(" :)");
	lista.print();
	cout << "--------"<<endl;
	*/
}
