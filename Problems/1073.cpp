#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,s;
    cin>>s;
    for (i=1; i<=s; i++){
        if(i%2==0){
            cout <<i<<"^2 = "<< i*i << "\n"<<endl;
        }
    }
    return 0;
}
