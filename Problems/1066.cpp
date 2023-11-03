#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,s,even=0, odd=0, positive=0, negative=0;
    for (i=0; i<5; i++)
        {
        cin>>s;
        if(s%2==0){
            even++;
        }
         if(s%2!=0){
            odd++;
        }
         if(0<s){
            positive++;
        }
         if(0>s){
            negative++;
        }
    }
    cout<<even<< " valor(es) par(es)"<<endl;
    cout<<odd<< " valor(es) impar(es)"<<endl;
    cout<<positive<< " valor(es) positivo(s)"<<endl;
    cout<<negative<< " valor(es) negativo(s)"<<endl;
return 0;
}
