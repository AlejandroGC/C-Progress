#include <bits/stdc++.h>

using namespace std;

#include "BST.h";

int main(){
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
    miArbol.printPre();
    
    if( miArbol.search(21)){
        cout << "Si encontre el 21" << endl;
    } else {
        cout << "No encontre el 21" << endl;
    }

    if( miArbol.search(100)){
        cout << "Si encontre el 100" << endl;
    } else {
        cout << "No encontre el 100" << endl;
    }

    if( miArbol.search(7)){
        cout << "Si encontre el 7" << endl;
    } else {
        cout << "No encontre el 7" << endl;
    }

    return 0;
}