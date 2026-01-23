#include<stdio.h>

int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    int last_digit = 0,sum = 0,a=n;
    while ( n>0 ){
        last_digit = n%10;
        sum = sum + last_digit;
        n = n/10;
    }

    printf("The sum of digits of %d is %d ..",a,sum);

    return 0;
}