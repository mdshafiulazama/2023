#include<stdio.h>
#include<math.h>
int main()
{
    double A,B,C,x,y,d;
   scanf("%lf %lf %lf", &A,&B,&C);
if (A==0){
    printf("Impossivel calcular\n");
    return 0;
}
    d=B*B - 4*A*C;
        if (d>=0){
        x=(-B + sqrt(d))/(2*A);
        y=(-B - sqrt(d))/(2*A);
        printf("R1 = %.5lf\nR2 = %.5lf\n",x,y);
    }
    else{
        printf("Impossivel calcular\n");
    }
    return 0;
}

