#include <stdio.h>

int power(int a,int b){
    if (b==0){
        return 1;
    }
    return a*power(a,b-1);
}

int main(){
    int a;
    printf("Enter value of base : ");
    scanf("%d",&a);

    int b;
    printf("Enter value of power : ");
    scanf("%d",&b);

    printf("The %d raise to power %d is %d..",a,b,power(a,b));
    return 0;
}