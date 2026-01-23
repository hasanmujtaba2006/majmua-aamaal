#include<stdio.h>

int main(){
    float l;
    printf("Enter length of rectangle : ");
    scanf("%f",&l);

    float b;
    printf("Enter breadth of rectangle : ");
    scanf("%f",&b);

    float prmt = 2*(l+b);
    float area = l*b;

    printf("Area = %.2f\nPerimeter = %.2f",area,prmt);
    return 0;
}