#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,x,y,sum,mat;
    cin>>n;
    while(true){
            if(n==0)
            break;

         cin>>x;
         cin>>y;
         if(x>y){
            sum=x;
            x=y;
            y=sum;
         }
         mat=0;
         for(i= x+1; i<y; i++){
            if (i%2!=0)
                mat+=i;
         }
         cout<<mat<<endl;
         n--;
    }

    return 0;
}
