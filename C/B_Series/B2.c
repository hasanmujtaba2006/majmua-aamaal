#include<stdio.h>

int main(){
    float r,area;
    printf("Enter radius of circle : ");
    scanf("%f",&r);

    area = 3.14*r*r;

    printf("The area of circle of radius %.1f is %.2f...",r,area);
    return 0;
}