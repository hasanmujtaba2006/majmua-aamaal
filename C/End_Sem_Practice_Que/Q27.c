#include<stdio.h>
#define pie 3.1415

int main(){
    float r;
    printf("Enter radius of circle : ");
    scanf("%f",&r);

    float circum = 2*pie*r;

    printf("The circumference of circle is %.2f",circum);
    return 0;
}