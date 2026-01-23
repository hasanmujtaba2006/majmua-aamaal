#include<stdio.h>

int main(){
    int a,b;
    printf("Enter two integers a and b where(a>b) : ");
    scanf("%d %d",&a,&b);

    int rem;
    rem = a-(b*(a/b));
    printf("The remainder when %d is divided by %d is %d...",a,b,rem);
    return 0;
}