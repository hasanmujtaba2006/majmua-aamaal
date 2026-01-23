#include<stdio.h>

int main(){
    int a,b,c;

    printf("Enter first side of triangle : ");
    scanf("%d",&a);

    printf("Enter second side of triangle : ");
    scanf("%d",&b);

    printf("Enter third side of triangle : ");
    scanf("%d",&c);

    if (a+b>c || b+c>a || c+a>b){
        printf("Yes, %d,%d & %d are sides of triangle..",a,b,c);
    }

    else {
        printf("No, %d,%d & %d are not sides of triangle..",a,b,c);
    }

    return 0;
}