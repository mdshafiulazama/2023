#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,n,y,m,d;
    cin>>n;
    d=n/365;
    a=n%365;
    m=a/30;
  y=a%30;
  cout<<d<< " ano(s)"<<endl;
  cout<<m<< " mes(es)"<<endl;
  cout<<y<< " dia(s)"<<endl;
return 0;
};
