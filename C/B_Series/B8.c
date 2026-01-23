#include<stdio.h>

int main(){
    int num;
    printf("Enter a number : ");
    scanf("%d",&num);

    if (num%5==0){
        printf("Yehh! %d is divisible by 5..",num);
    }

    else{
        printf("Nahhh! %d is not divisible by 5..",num);
    }

    return 0;
}