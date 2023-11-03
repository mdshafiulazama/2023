#include<bits/stdc++.h>
using namespace std;
void solve()
{
    int n,i;
    cin>>n;
    int a[n];
    int t=0;
    for(i=0; i<=n; i++){
    cin>>a[i];
    if(a[i]==2)
        t++;
}
if(t&1)
    cout<<-1<<endl;
else{
    int current_t=0;
    int i,k=-1;
    for(i=0; i<n; i++){
        if(a[i]==2)
            current_t++;
        if(current_t==t/2){
            k=i;
            break;
        }
    }
    cout<<k+1<<endl;
}
}
int main()
{
    int t;
    cin>>t;
    while(t--)
        solve();
}

