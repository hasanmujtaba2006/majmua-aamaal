#include <stdio.h>

int powerlog(int a,int b){
    if (b==0){
        return 1;
    }
    if (b==1){
        return a;
    }
    if (b%2==0){
        return powerlog(a,b/2)*powerlog(a,b/2);
    }
    if (b%2!=0){
        return powerlog(a,b/2)*powerlog(a,b/2)*a;
    }
}

int main(){
    int a;
    printf("Enter base value : ");
    scanf("%d",&a);

    int b;
    printf("Enter power value : ");
    scanf("%d",&b);

    printf("The value of %d raise to power %d is %d...",a,b,powerlog(a,b));
    return 0;
}



