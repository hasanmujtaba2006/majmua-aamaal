#include<stdio.h>

int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    int count = 0, a = n;

    while (n>0){
        n = n/10;
        count ++;
    }

    printf("The number of digits in %d are %d ..",a,count);

    return 0;
}