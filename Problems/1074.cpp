#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,s;
    cin>>n;
    for (i=0; i<n; i++)
    {
        cin>>s;
    if(s==0){
        cout<< "NULL\n";
    }
    else {
        if(s%2==0)cout<< "ENEN";
        else cout << "ODD";
        if(s<0)cout<< " NEGATIVE\n";
        else cout << " POSITIVE\n";
        }
    }
    return 0;
}
