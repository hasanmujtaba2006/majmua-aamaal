#include<stdio.h>

int main(){
    float per;
    printf("Enter your percentage : ");
    scanf("%f",&per);

    if (per>90 && per<=100){
        printf("Excellent..");
    }

    if (per>80 && per<=90){
        printf("Very Good..");
    }

    if (per>70 && per<=80){
        printf("Good..");
    }

    if (per>60 && per<=70){
        printf("Can do better..");
    }

    if (per>50 && per<=60){
        printf("Average..");
    }

    if (per>40 && per<=50){
        printf("below Average..");
    }

    if (per<=40){
        printf("Fail..");
    }

    if (per<0){
        printf("INVALID INPUT");
    }

    return 0;
}