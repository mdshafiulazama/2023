#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,i;
    double a,b,c;
    cin>>s;
    for (i=0; i<s; i++)
    {
        cin>>a;
        cin>>b;
        cin>>c;
        cout<<fixed<<setprecision(1);
        cout<<""<<(a*2+b*3+c*5)/(2.0+3.0+5.0)<<endl;
    }
    return 0;
}
