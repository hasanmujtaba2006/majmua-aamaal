#include<stdio.h>

int factorial(int a){
    if (a==1){
        return 1;
    }

    return a*factorial(a-1);
}

int main(){
    int n;
    printf("Enter number whose factorial you want to print : ");
    scanf("%d",&n);

    printf("The factorial of %d is equal to %d ..",n,factorial(n));

    return 0;
}