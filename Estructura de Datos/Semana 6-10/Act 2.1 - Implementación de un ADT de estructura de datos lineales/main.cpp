// A01570396 Alejandro Daniel González Carrillo
// Act 2.1 - Implementación de un ADT de estructura de datos lineales
// Act 2.2 - Verificación de las funcionalidades de una estructura de datos lineal

#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList<string> lista, lista2, lista3;


    // Casos de Prueba - Metodo Create
    cout << "Caso CREATE" << endl;
    lista.create("papas",19); // Caso donde la posicion es un valor por encima del rango de la linkedlist.
    lista.create("Alex",-6); // Caso donde la posicion es un valor por debajo del rango de la linkedlist.
    lista.create("come",1); // Caso donde la posicion es 1.
    lista.create("papas",2); // Caso donde la posicion es entre el valor de rangos de la linkedlist.
    lista.create("con", 5); // Caso extra.
    lista.create("chile", 6); // Caso extra.
    lista.print();

    // Caso de Especial para delete donde una lista esta llena del mismo valor.
    lista3.create("Alex",0);
    lista3.create("Alex",0);
    lista3.create("Alex",0);
    lista3.create("Alex",0);

    // Casos de Prueba - Metodo Read 
    cout << "Caso READ" << endl; 
    cout << lista.read("dulces") << endl; // Caso donde no exista una palabra.
    cout << lista.read("Alex") << endl; // Caso donde sea cualquier palabra dentro de la estructura.
    cout << lista.read("") << endl; // Caso donde se introduce un string vacio.
    cout << lista2.read("Alex") << endl; // Caso donde se recibe una lista vacia, debe regresar -1;
    cout << lista.read("papas") << endl; // Caso donde hay una palabra repetida se muestra la posicion de la primera palabra encontrada.

    // Casos de Prueba - Metodo Update
    cout << "Caso UPDATE" << endl;
    lista.update("Alex", "Daniel"); // Caso en donde es intercambio de palabras.
    lista.update("papas", ""); // Caso en donde se intercambia por un string vacio.
    lista.print();

    // Casos de Prueba - Metodo Del
    cout << "Caso DEL" << endl;
    lista.del(""); // Caso donde se eliminan los string que esten vacios.
    lista.del("Daniel"); // Caso donde se busca eliminar al primer valor.
    lista2.del("Alex"); // Caso donde se busca eliminar datos de una lista vacia.
    lista.print();

    // Caso Especial Del (Una lista completamente del mismo valor)
    lista3.print();
    lista3.del("Alex");
    lista3.print();

    return 0;
}