#include<stdio.h>
#include<math.h>

int main(){
    float side;
    printf("Enter the length of side : ");
    scanf("%f",&side);

    float area = (sqrtf(3)/2)*side*side;

    printf("The area of equilateral triangle is %.2f ..",area);
    return 0;
}