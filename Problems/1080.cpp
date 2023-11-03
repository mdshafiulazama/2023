#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,i;
    int hig=0;
    int pos=0;
    for (i=0; i<100; i++)
    {
        cin>>s;
        if(s>hig)
        {
            hig=s;
            pos=i;
        }
    }
    cout<< hig<< "\n"<< pos+1<< "\n";
    return 0;
}
