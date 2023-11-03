#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a,b,c,money, percent,x;
    cin>>a;

    if (a>=0 && a<=400.00)
    {
        x=0.15;
    }
    else if(a>= 400.01 && a<=800.00){
    x=0.12;
    }
    else if(a>=800.01 && a<=1200.00)
    {
        x=0.1;
    }
    else if(a>=1200.01 && a<=2000.00)
    {
        x=0.07;
    }
    else {
        x=0.04;
    }
    money=a*x;
    b=a+money;
    percent=x*100;
    cout<<fixed;
    cout<< "Novo salario: "<<setprecision(2)<<b<<endl;
    cout<< "Reajuste ganho: "<<setprecision(2)<<money<<endl;
    cout<< "Em percentual: "<< setprecision(0)<<percent<< " %"<<endl;
    return 0;
}
