#include<iostream>
#include <iomanip>
using namespace std;
int main()
{
    double x,y,z;
    x=0;
    y=0;
    while(true){
        cin>>x;
        if(x<0 || x>10){
            cout<< "nota invalida\n";
        }
        else if(z==0){
            y=x;
            z=1;
        }else{
        cout<< fixed<<setprecision(2)<<"media = "<<(x+y)/2<<endl;
        }
    }
return 0;
}
