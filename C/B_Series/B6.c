#include<stdio.h>

int main(){
    float a;
    printf("Enter a decimal number to print fractional part : ");
    scanf("%f",&a);

    int real = a;

    float frac;
    frac = a - real;

    printf("The fractional part of %f is %f..",a,frac);
    return 0;
}