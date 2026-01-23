#include<stdio.h>

int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    if (n%15 == 0){
        printf("%d is divisible by both 3 and 5...",n);
    }

    if (n%3 == 0 && n%5 !=0){
        printf("%d is divisible by 3 but not divisible by 5...",n);
    }

    if (n%3 != 0 && n%5 == 0){
        printf("%d is not divisible by 3 but divisible by 5...",n);
    }

    if (n%3 != 0 && n%5 != 0){
        printf("%d is neither divisible by 3 nor 5...",n);
    }

    return 0;
}