#include<stdio.h>

int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    int l_d = 0,sum = 0,a = n;

    while(n>0){
        l_d = n%10;
        if (l_d%2 == 0){
            sum += l_d;
        }
        n = n/10;
    }

    printf("The sum of even digits of %d is %d ..",a,sum);

    return 0;
}