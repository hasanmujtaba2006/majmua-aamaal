#include<stdio.h>

int main(){
    int a;
    printf("Enter a number : ");
    scanf("%d",&a);

    if (a%5==0 && a%3==0){
        if (a%15!=0){
            printf("%d is divisible by 5 and 3 but not 15..",a);
        }

        else{
            printf("%d is divisible by 5 and 3 also by 15..",a);
        }
    }

    return 0;
}