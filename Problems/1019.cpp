#include<bits/stdc++.h>
using namespace std;
int main()
{
int n,h,m,s,a;
cin>>n;
h=n/(60*60);
s=n%3600;
m=s/60;
a=s%60;
cout<<h<< ":"<<m<< ":"<<a<<endl;
return 0;
}
