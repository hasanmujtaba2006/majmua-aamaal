#include<stdio.h>

int main(){
    int a;
    printf("Enter a number : ");
    scanf("%d",&a);

    int ld=0,sum=0;

    while(a>0){
        ld = a%10;
        a = a/10;
        sum += ld;
    }

    printf("The sum of the digits are %d",sum);

    return 0;
}