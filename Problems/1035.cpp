#include<bits/stdc++.h>
using namespace std;
int main()

{
    double A,B,C,x,y,d;
    cin>>A>>B>>C;

    d=B*B - 4*A*C;
        if (d < 0 || A==0){
        cout<<"Impossivel calcular\n";
    }else{
        x=(-B + sqrt(d))/(2*A);
        y=(-B - sqrt(d))/(2*A);
        cout<<fixed<<setprecision(5)<< "R1 = "<<x<<"\n"<<endl;
        cout<<fixed<<setprecision(5)<< "R2 = "<<y<<"\n"<<endl;
    }
    return 0;
}
