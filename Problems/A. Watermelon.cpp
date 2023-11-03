//Multilingual Code With SKT.
//Learning Code in C++
//A Watermelon (CODEFORCES)
#include<iostream>
using namespace std;
int main()
{
    int w,a;
    cin>>w;
    if(w>2)
    {
        a=w%2;
        if(a==0)
        {
            cout<< "YES"<<endl;
        }
        else
        {
            cout<< "NO"<<endl;

        }
    }
    else
    {
        cout<< "NO"<<endl;
    }
    return 0;
}
