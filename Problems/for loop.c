//Multilingual Code With SKT
//Learning Code
//for loop Multiplication table
#include<stdio.h>
int main(){
    int i,n;
    printf("Enter the value: ");
    scanf("%d",&n);
    for(i=1; i<=10; i++){
        printf("%d x %d = %d\n",i,n,i*n);
    }
    return 0;
}
