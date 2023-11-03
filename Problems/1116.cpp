#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,x,y;

    cin>>n;
    for(i=0; i<n; i++){
        cin>>x>>y;

        if(y==0){
            cout<< "divisao impossivel"<<endl;
        }else{
            cout<<fixed<<setprecision(1)<<""<<(float)x/(float)y<<endl;
        }

    }

    return 0;
}
