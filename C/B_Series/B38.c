#include<stdio.h>

int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    int l_d = 0,r_n = 0,sum = 0,a = n;

    while (n>0){
        l_d = n%10;
        sum += l_d;
        r_n = r_n*10 + l_d;
        n = n/10;
    }

    printf("The sum and reverse of %d are %d , %d ..",a,sum,r_n);

    return 0;
}