#include<stdio.h>

void inc(int n){
    if (n==0){
        return;
    }
    inc(n-1);
    printf("%d ",n);
    return;
}

void dec(int n){
    if (n==0){
        return;
    }
    printf("%d ",n);
    dec(n-1);
    return;
}

int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    printf("Increasing Order : ");
    inc(n);

    printf("\nDecreasing Order : ");
    dec(n);

    return 0;
}