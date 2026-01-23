#include<stdio.h>

int main(){
    float a;
    printf("Enter a number : ");
    scanf("%f",&a);

    float b;
    printf("Enter a number : ");
    scanf("%f",&b);

    float sum,diff,mult,div;
    int mod;

    sum = a+b;
    diff = a-b;
    mult = a*b;
    div = a/b;
    mod = (int)a%(int)b;

    printf("Sum = %f\n Difference = %f\n Product = %f\n Division = %f\n Modulus = %d",sum,diff,mult,div,mod);

    return 0;
}