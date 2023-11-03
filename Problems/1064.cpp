#include<bits/stdc++.h>
using namespace std;
int main()
{
    float s,t,a,b=0;
    int i, sum=0;
    for (i=1; i<=6; i++){
        cin>>s;
        if (s>0)
    {
        a=a+s;
        sum++;
    }
    }
t= a/sum;
    cout<<sum<< " valores positivos"<<endl;
    cout<<fixed<<setprecision(1)<<t<< endl;
    return 0;
}
