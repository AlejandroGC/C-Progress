#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

int main(){
    stack<int> miPila;
    miPila.push(4);
    miPila.push(52);
    miPila.push(14);
    cout << "El size es: " << miPila.size();
    while(!miPila.empty()){
        cout << miPila.top() << endl;
        miPila.pop();
    }
    return 0;
}