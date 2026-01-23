#include<stdio.h>

int main(){
    float a;
    printf("Enter a decimal number : ");
    scanf("%f",&a);

    int b=a;

    float fp = a-b;
    printf("The fractional part of %f is %f..",a,fp);
    return 0;
}