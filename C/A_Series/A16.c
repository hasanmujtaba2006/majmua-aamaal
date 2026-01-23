#include<stdio.h>

int main(){
    int a;
    printf("Enter 1st Side of triangle : ");
    scanf("%d",&a);

    int b;
    printf("Enter 2nd side of triangle : ");
    scanf("%d",&b);

    int c;
    printf("Enter 3rd side of triangle : ");
    scanf("%d",&c);

    if (a+b>c || b+c>a || c+a>b){
        printf("Yes, These are length of sides of a triangle..");
    }

    else{
        printf("No, these are not length of sides of a triangle..");
    }

    return 0;
}