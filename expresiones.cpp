#include <iostream>

using namespace std;

int main(){
    float a, b, c, d, res = 0;

    cout<<"Valor a: "<<endl; cin>>a;
    cout<<"Valor b: "<<endl; cin>>b;
    cout<<"Valor c: "<<endl; cin>>c;
    cout<<"Valor d: "<<endl; cin>>d;

    res = (a+b)/(c+d);

    cout.precision(2);
    cout<<"\nLa respuesta es: "<<res<<endl;

    return 0;
}

