#include<stdio.h>

int main(){
    float pie = 3.14;
    float r;
    printf("Enter Radius of sphere : ");
    scanf("%f",&r);
    float vol;
    vol = (4.0/3)*pie*r*r*r;

    printf("The volume is %.2f ",vol);
    return 0;
}