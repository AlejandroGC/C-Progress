#include <iostream>
#include "queue.h"

using namespace std;

int main(){
    queue<char> miFila;
    miFila.push('A');
    miFila.push('B');
    miFila.push('C');
    cout << "El tamano es: " << miFila.size() << endl;
    cout << "El frente es: " << miFila.front() << endl;
    miFila.push('D');
    while(!miFila.empty()){
        cout << miFila.front() << " ";
        miFila.pop();
    } 
    cout << endl;
    return 0;
}