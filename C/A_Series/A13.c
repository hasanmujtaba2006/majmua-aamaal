#include<stdio.h>

int main(){
    int a;
    printf("Enter a number : ");
    scanf("%d",&a);

    if (a/1000==0){
        printf("%d is a three digit number...",a);
    }

    else{
        printf("%d is not a three digit number...",a);
    }

    return 0;
}