#include <stdio.h>

int min(int a,int b){
    if (a>b) {
        return b;
    }
    else {
        return a;
    }
}

int gcd(int a,int b){
    int hcf;
    for (int i=1;i<=min(a,b);i++){
        hcf = i;
    }
    return hcf;
}

int main(){
    int a;
    printf("Enter first number : ");
    scanf("%d",&a);

    int b;
    printf("Enter second number : ");
    scanf("%d",&b);

    int l = gcd(a,b);
    printf("The greatest common divisor of %d and %d is %d.",a,b,l);
    return 0;
}