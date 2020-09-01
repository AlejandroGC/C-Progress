#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int busqSec(string q) {
    for (int i = 0; i < q; i++) {
        if (q[i] != q[i-1]) {
            
        }
        
    }
    
}

int main(){

    int n;
    string q;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> q;
        cout << busqSec(q);
    }
    


    return 0;
}