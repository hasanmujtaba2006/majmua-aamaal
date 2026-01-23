#include<stdio.h>

int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    if (n%3==0){
        if (n%5==0){
            if (n%15!=0){
                printf("%d is divisible by 3 or 5 but not by 15...",n);
            }
            else {
                printf("%d is divisible by 3,5 and 15...",n);
            }
        }
    }

    return 0;
}