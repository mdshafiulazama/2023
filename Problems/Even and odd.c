//Multilingual Code With SKT
//Learning Code
//N number of summation
//without low.
#include<stdio.h>
int main()
{
    int i,n,sum=0;
    printf("Enter the positive number: ");
    scanf("%d",&n);
    for (i=0; i<=n; i++)
    {
        sum=sum+i;
    }
    printf("sum of 1st %d number:%d",n,sum);
    return 0;

}
