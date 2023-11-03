#include<bits/stdc++.h>
using namespace std;
int main()
{
 float A,B,C,area;
 cin>>A>>B>>C;
 if (A<(B+C)&& B<(A+C)&& C<(A+B)){
    cout<<fixed;
 cout <<setprecision(1)<<"Perimetro = "<<A+B+C<<endl;
 }else  {
 area= 0.5*(A+B)*C;
 cout<<fixed;
 cout <<setprecision(1)<<"Area = "<<area<<endl;

 }
    return 0;

}
