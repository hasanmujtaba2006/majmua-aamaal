#include<stdio.h>

int main(){
    int dvd;
    printf("Enter Dividend : ");
    scanf("%d",&dvd);

    int dvr;
    printf("Enter Divisor : ");
    scanf("%d",&dvr);

    int Qut = dvd/dvr;

    int remainder = dvd - (dvr*Qut);

    printf("The remainder is %d",remainder);
    return 0;
}