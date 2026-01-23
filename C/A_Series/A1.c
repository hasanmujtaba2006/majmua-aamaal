#include<stdio.h>

int main(){
    float r;
    printf("Enter radius of sphere : ");
    scanf("%f",&r);

    float vol = (4.0/3)*3.14*r*r*r;

    printf("Volume of sphere : %f",vol);
    return 0;
}