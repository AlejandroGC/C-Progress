#include <iostream>
#include <math.h>

using namespace std;

int main(){
    float x,y,res = 0;

    cout<<"Valor x: "<<endl; cin>>x;
    cout<<"Valor y: "<<endl; cin>>y;

    res = (sqrt(x))/(pow(y,2)-1);

    cout<<"\nEl resultado es: "<<res<<endl; 

    return 0;
}