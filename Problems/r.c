#include<stdio.h>
int main()
{
    int i,s;
    scanf("%d",&s);
    for (i=1; i<=10; i++)
    {
        printf("%d x %d = %d\n",s,i,i*s);

    }
    return 0;
}
