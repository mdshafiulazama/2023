#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,x,y;
    int time;
    cin>>a>>x>>b>>y;
   time = (((b*60)+y)-((a*60)+x));
   if (time<=0)time += 24*60;
   cout<< "O JOGO DUROU "<<time/60<< " HORA(S) E " <<time%60<<" MINUTO(S)"<<endl;
return 0;
}
