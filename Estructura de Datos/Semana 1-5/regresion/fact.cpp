#include <iostream>

using namespace std;

long long factorialIterativo(int n) {
    long long acum = 1;
    for (int i = 0; i <= n; i++){
        acum += i;
    }   
}

long long factorialRecursivo(int n) {
    if (n == 0) {
        return 1;
    }
    return n*factorialRecursivo(n-1);
    
}

int main() {
    int n;
    cin >> n;
    cout << factorialIterativo(n) << endl;
    cout << factorialRecursivo(n) << endl;
    return 0;
}