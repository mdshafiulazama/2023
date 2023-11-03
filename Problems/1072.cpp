#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,s;
    int in=0;
    int out=0;
    cin>>n;
    for (i=0; i<n; i++)
    {
        cin>>s;
        if (s>= 10 && s<=20) in++;
        else out++;
    }
    cout<< in << " in\n";
    cout << out<< " out\n";
    return 0;

}
