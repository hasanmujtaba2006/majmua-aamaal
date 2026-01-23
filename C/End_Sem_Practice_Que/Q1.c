#include<stdio.h>

int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    int a = 0;

    while(1){
        if (n>0){
            int l_d = 0;
            l_d = n%10;
            n = n/10;
            a = a + l_d;
        }

        if (n==0){
            break;
        }
    }

    printf("The sum of the digits of number %d is equal to -> %d",n,a);
    return 0;
}