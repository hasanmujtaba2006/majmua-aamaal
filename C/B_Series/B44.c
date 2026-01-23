#include<stdio.h>

int main(){
    int n;
    printf("Enter first number : ");
    scanf("%d",&n);

    int m;
    printf("Enter second number : ");
    scanf("%d",&m);

    int power = 1;

    for (int i=1;i<=m;i++){
        power = power * n;
    }

    printf("The value of %d raise to power %d = %d",n,m,power);
    return 0;
}