#include<stdio.h>

int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    int l_d = 0,a = n,r_n = 0;

    while (n>0){
        l_d = n%10;
        r_n = r_n*10+l_d;
        n = n/10;
    }

    printf("The reverse of %d is %d ..",a,r_n);

    return 0;
}