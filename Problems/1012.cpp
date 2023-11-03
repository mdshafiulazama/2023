#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a,b,c;
    cin>>a>>b>>c;
    double pi=3.14159, tri, cir, tra, sqr, rec;
    tri = 0.5*a*c;
    cir = pi*c*c;
    tra = (a+b)/2*c;
    sqr = b*b;
    rec = a*b;
    cout<<fixed<<setprecision(3)<<"TRIANGULO: "<<tri<<endl;
    cout<<fixed<<setprecision(3)<<"CIRCULO: "<<cir<<endl;
    cout<<fixed<<setprecision(3)<<"TRAPEZIO: "<<tra<<endl;
    cout<<fixed<<setprecision(3)<<"QUADRADO: "<<sqr<<endl;
    cout<<fixed<<setprecision(3)<<"RETANGULO: "<<rec<<endl;
    return 0;
}
