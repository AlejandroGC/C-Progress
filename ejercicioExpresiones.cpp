#include <iostream>

using namespace std;

int main(){
    float n1, n2, res = 0;

    cout<<"Valor a: "<<endl;cin>>n1;
    cout<<"Valor b: "<<endl;cin>>n2;

    res = (n1/n2) + 1;

    cout.precision(2);
    cout<<"\nLa respuesta es: "<<res<<endl;

    return 0;
}