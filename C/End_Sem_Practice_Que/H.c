#include<stdio.h>
#include<math.h>
int main(){
    int n;
    printf("Enter a number whose square root you want : ");
    scanf("%d",&n);

    float udrt = sqrt(n);

    printf("Square root of %d is %.3f ..",n,udrt);
    return 0;
}