#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a;
    if(a>2)
    {
        b=a%2;
        if(b==0)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<< "NO"<<endl;
        }

    }
    /*else
    {
        cout<<"NO"<<endl;
    }*/
    return 0;
}
