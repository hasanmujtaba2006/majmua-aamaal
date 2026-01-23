#include<stdio.h>

int main(){
    int a;
    printf("Enter a number : ");
    scanf("%d",&a);

    if (a%5==0 && a%3==0){
        printf("%d is divisible by 5 and 3...",a);
    }

    else{
        printf("%d is not divisible by 5 and 3...",a);
    }

    return 0;
}