#include<stdio.h>

int main(){
    float a;
    printf("Enter side of square : ");
    scanf("%f",&a);

    float perimeter = 4*a;
    float area = a*a;

    printf("Area = %.2f\n Perimeter = %.2f ..",area,perimeter);
    return 0;
}