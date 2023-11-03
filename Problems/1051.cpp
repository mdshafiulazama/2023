#include<bits/stdc++.h>
using namespace std;
int main()
{
    double s;
    cin>>s;

    if (s <= 2000.00)
    {
        cout<< "Isento\n"<<endl;
    }
    else if (s>=2000.01 && s<=3000.00)
    {
        cout <<fixed<<setprecision(2)<< "R$ "<< (s-2000.00)*0.08<<endl;
        }
        else if (s>=3000.01 && s<=4500.00)
    {
        cout <<fixed<<setprecision(2)<< "R$ "<< (s-3000.00)*0.18+1000.00*0.08<<endl;
        }
        else if (s>=4500.00)
    {
        cout <<fixed<<setprecision(2)<< "R$ "<< (s-4500.00)*0.28+1500.00*0.18+1000.00*0.08<<endl;
        }
return 0;
}

