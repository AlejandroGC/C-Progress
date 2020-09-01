#include <iostream>

using namespace std;

long long fibonacciIterativo(int n) {
    long long pos = 1, pos2 = 1, pos3;
    for (int i = 3; i <= n; i++) {
        pos3 = pos + pos2;
        pos = pos2;
        pos2 = pos3;
    }
    return pos3;
}

long long fibonacciRegresivo(int n) {
    if (n <= 2) {
        return 1;
    }
    return fibonacciRegresivo(n-1) + fibonacciRegresivo(n-2);
}


int main() {
    int n;
    cin >> n;
    cout << "fibonnaci iterativo:" << fibonacciIterativo(n) << endl;
    cout << "fibonnaci recursivo:" << fibonacciRegresivo(n) << endl;    
}