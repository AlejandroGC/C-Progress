#include <iostream>
#include <map>

using namespace std;

int main(){

    map<char,int> m;
    m['a'] = 1;
    m['b'] = 2;
    m['c'] = 3;
    
    for (map<char,int> iterator it = m.begin(); it != m.end(); ++it){ 
        cout << it->first << " = " << it->second << '\n'; 
    }
    // for(map<char,int> iterator it = m.begin(); it != m.end(); it++) {
    //     cout << m.first
    // }

    return 0;
}