#include <iostream>
#include <math.h>
#include <string>

using namespace std;

char busqSecuencial(string s, int &cantBS) {
    cantBS = 0;
    int n = s.size();
    for (int i = 0; i < n-1; i+=2) {
        cantBS++;
        if (s[i] != s[i+1]) {
            return s[i];
        }
    }
    return s[n-1];
}

char busqBinaria(string s, int &cantBB) {
    int ini = 0, fin = s.size() - 1, m, Ld, Li;
    cantBB = 0;
    while (ini < fin) {
        m = (ini + fin)/2;
        cantBB++;
        if ((s[m] != s[m-1]) && (s[m] != s[m+1])) {
            return s[m];
        }
        if (s[m] == s[m+1]) {
            Li = m - ini;
            Ld = fin - (m+1);
            if (Li % 2 != 0) {
                fin = m - 1;
            } else {
                ini = m + 2;
            }
        } else {
            Li = m - 1 - ini;
            Ld = fin - m;
            if (Li % 2 != 0) {
                fin = m - 2;
            } else {
                ini = m + 1;
            }
        }
    }
    return s[ini];
    
}

int main(){
    int n, cantBS, cantBB;
    string s;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        cout << busqSecuencial(s, cantBS) << " " ;
        cout << cantBS << " ";
        cout << busqBinaria(s, cantBB) << " " ;
        cout << cantBB << endl;
        
    }
    


    return 0;
}