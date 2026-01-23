#include<stdio.h>

int main(){
    float base;
    printf("Enter the base of triangle : ");
    scanf("%f",&base);

    float height;
    printf("Enter the height of triangle : ");
    scanf("%f",&height);

    float area = (0.5)*base*height;
    printf("Area of triangle of having base=%f,height=%f is equal to %.2f ..",base,height,area);

    return 0;
}