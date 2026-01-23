#include<stdio.h>

int main(){
    int a;
    printf("Enter first number : ");
    scanf("%d",&a);

    int b;
    printf("Enter second number : ");
    scanf("%d",&b);

    int x=a,y=b;

    //Swaping both number
    int c = a;
    a = b;
    b = c;

    printf("The original values a=%d and b=%d.\n\nThe Swapped values a=%d and b=%d.",x,y,a,b);

    return 0;
}