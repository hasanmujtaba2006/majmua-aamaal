#include<stdio.h>

int main(){
    int year;
    printf("Enter any year to check leap year : ");
    scanf("%d",&year);

    if (year%4==0){
        printf("Yahh! %d is leap year...",year);
    }

    else{
        printf("No, %d is not leap year...",year);
    }

    return 0;
}