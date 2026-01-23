#include<stdio.h>

int main(){
    int n;
    printf("Enter number whose factorial you want to print : ");
    scanf("%d",&n);

    int fact = 1;

    for (int i=1;i<=n;i++){
        fact = fact*i;
    }

    printf("The factorial of %d is %d .",n,fact);
    return 0;
}