// Alejandro Daniel González Carrillo
// A01570396
// Act 3.2 - Árbol Heap: Implementando una fila priorizada
#include<iostream>
#include <vector>
#include "p_queue.h"

using namespace std;

int main(){
    Pqueue v;
    cout << "Size: " << v.size() << endl;
    v.push(8);
    v.push(25);
    v.push(23);
    v.push(30);
    v.push(15);
    v.pop();
    v.pop();
    
    cout << "Size despues: "<< v.size() << endl;
    cout << "Mayor Prioridad: " << v.top() << endl;
    cout << "Vacia: ";
    if(v.empty() == 0) {
        cout << "False" << endl;
    } else {
        cout << "True" << endl;
    }

    v.print();
    
    

    return 0;
}