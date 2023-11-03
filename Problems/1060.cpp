#include<bits/stdc++.h>
using namespace std;
int main()
{
    float s;
    int i,sum=0;
    for (i=1; i<=6; i++)
    {
        cin>>s;
        if (s>0)
        {
            sum++;
        }
    }
    cout <<sum<< " valores positivos"<<endl;
    return 0;
}
