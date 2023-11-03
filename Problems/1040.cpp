#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
    double a,b,c,d,last,sum;
    cin>>a>>b>>c>>d;
    sum =(a*2 + b*3 + c*4 +d)/10;
    cout<<fixed;
    cout<<setprecision(1)<< "Media: "<<sum<<endl;
    if (sum >= 7.0){
        cout<<"Aluno aprovado.\n";
    }
    else if (sum >= 5.0){
    cout<< "Aluno em exame.\n";
    cin>>last;

    cout<<setprecision(1)<<"Nota do exame: "<<last<<endl;
    if (last+sum/2.0 > 5.0){
       cout<< "Aluno aprovado.\n";
    }
    else
    {
        cout<< "Aluno reprovado.\n";
    }
    cout<<setprecision(1)<< "Media final: "<<(last+sum)/2.0<<endl;
    }
      else
    {
        cout<< "Aluno reprovado.\n";
    }
    return 0;
}
