#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a,b,c,d,e,f,g,temp;
    cin>>n;
    a=n/100;
    temp=n%100;
    b=temp/50;
    temp=temp%50;
    c=temp/20;
    temp=temp%20;
    d=temp/10;
    temp=temp%10;
    e=temp/5;
    temp=temp%5;
    f=temp/2;
    temp=temp%2;
    g=temp;
    cout<<n<<endl;
    cout<<a<< " nota(s) de R$ 100,00"<<endl;
    cout<<b<< " nota(s) de R$ 50,00"<<endl;
    cout<<c<< " nota(s) de R$ 20,00"<<endl;
    cout<<d<< " nota(s) de R$ 10,00"<<endl;
    cout<<e<< " nota(s) de R$ 5,00"<<endl;
    cout<<f<< " nota(s) de R$ 2,00"<<endl;
    cout<<g<< " nota(s) de R$ 1,00"<<endl;
    return 0;
}
