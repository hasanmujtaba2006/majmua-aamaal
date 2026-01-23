#include<stdio.h>

int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    if (n>99 && n<1000){
        printf("%d is a three digit number..",n);
    }

    else{
        printf("%d is not a three digit number..",n);
    }

    return 0;
}