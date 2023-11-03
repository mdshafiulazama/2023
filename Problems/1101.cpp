#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,m,n,math,sum;
    while(true)
    {
        cin>>m>>n;
        if(m<=0)
            break;
        if(n<=0)
            break;
        if(m>n){
            math=m;
            m=n;
            n=math;
        }
        sum=0;
        for(i=m; i<=n; i++)
        {
            cout<< i <<" ";
            sum+=i;
        }
        cout<< "Sum="<<sum<<endl;
    }
      return 0;
}
