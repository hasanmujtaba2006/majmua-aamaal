#include<stdio.h>

int main(){
    float r;
    printf("Enter radius of circle : ");
    scanf("%f",&r);

    float area = 3.14*r*r;

    printf("The area of circle is %f ",area);
    return 0;

}