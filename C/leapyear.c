#include <stdio.h>
int main(){
    int year;
    printf("Eneter a year : ");
    scanf("%d",&year);
    if ( year%4 == 0){
        printf("It is a leap year");
    }    
    else{
        printf("It is not leap year");

    }
    return 0;

    
}