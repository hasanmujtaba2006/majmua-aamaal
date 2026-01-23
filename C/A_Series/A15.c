#include<stdio.h>

int main(){
    int a;
    printf("Enter 1st Number : ");
    scanf("%d",&a);

    int b;
    printf("Enter 2nd numnber : ");
    scanf("%d",&b);

    int c;
    printf("Enter 3rd number : ");
    scanf("%d",&c);

    if (a>b && a>c){
        printf("%d is greatest...",a);
    }

    else if (b>a && b>c){
        printf("%d is greatest...",b);
    }

    else{
        printf("%d is greatest..",c);
    }

    return 0;
}