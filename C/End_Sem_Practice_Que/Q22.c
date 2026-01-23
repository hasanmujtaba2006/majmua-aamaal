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
        printf("Largest number is %d ..",a);
    }

    else if (b>a && b>c){
        printf("Largest number is %d ..",b);
    }

    else if (c>a && c>b){
        printf("Largest number is %d ..",c);
    }

    else{
        printf("All number are equal ..");
    }

    return 0;
}
