#include<stdio.h>

int power(int a,int b){
    if (b==0){
        return 1;
    }

    return a*power(a,b-1);
}
int main(){
    int a;
    printf("Enter base value : ");
    scanf("%d",&a);

    int b;
    printf("Enter power value : ");
    scanf("%d",&b);

    printf("%d raise to power %d is equal to %d..",a,b,power(a,b));
    return 0;
}