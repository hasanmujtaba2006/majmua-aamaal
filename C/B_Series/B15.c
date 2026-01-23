#include<stdio.h>

int main(){
    int a,b,c;

    printf("Enter first number : ");
    scanf("%d",&a);

    printf("Enter second number : ");
    scanf("%d",&b);

    printf("Enter third number : ");
    scanf("%d",&c);

    if (a>b && a>c){
        printf("%d is greatest in the set of numbers {%d,%d,%d}",a,a,b,c);
    }

    if (b>a && b>c){
        printf("%d is greatest in the set of numbers {%d,%d,%d}",b,a,b,c);
    }

    if (c>a && c>b){
        printf("%d is greatest in the set of numbers {%d,%d,%d}",c,a,b,c);
    }

    if (a == b && b == c){
        printf("Set of numbers {%d,%d,%d} containing all equal elements",a,b,c);
    }

    return 0;
}