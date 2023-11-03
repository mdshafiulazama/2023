#include<bits/stdc++.h>
using namespace std;
int main()
{
    int s,i,a;
    char t;
    int total=0, coelho=0, sapo=0, rato=0;
    cin>> s;
    for(i=0; i<s; i++)
    {
        cin>>a;
        cin>>t;
        total+=a;
        if(t== 'C')
            coelho+=a;
        if(t=='S')
            sapo+=a;
        if(t=='R')
            rato+=a;
    }
    cout<< "Total: "<<total << "cobaias\n";
    cout<< "Total de coelhos: "<< coelho << "\n";
    cout<< "Total de ratos: "<< rato<< "\n";
    cout<< "Total de sapos: "<<sapo<< "\n";

    cout<<fixed<<setprecision(2)<< "Percentual de coelhos: "<<((float)coelho/(float)total)*100.00<< " %\n"<<endl;
    cout<<fixed<<setprecision(2)<< "Percentual de ratos: "<<((float)rato/(float)total)*100.00<< " %\n"<<endl;
    cout<<fixed<<setprecision(2)<< "Percentual de sapos: " <<((float)sapo/(float)total)*100.00<< " %\n"<<endl;
    return 0;

}
