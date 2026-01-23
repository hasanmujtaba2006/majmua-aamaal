#include<stdio.h>

int main(){
    int a;
    printf("Enter a number : ");
    scanf("%d",&a);

    float b = (float)a/2;
    printf("The Half of number %d is %f",a,b);
    return 0; 
}