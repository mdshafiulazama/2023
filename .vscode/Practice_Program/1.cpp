#include <stdio.h>
 
int main() {
    int n,a;
    float b;
    double c;
    scanf("%d %d %f", &n, &a, &b);
    c=a*b;
    printf("\nNUMBER= %d\n",n);
    printf("\nSALARY= U$ %.2lf\n\t",c);
 
    return 0;
};
