#include<stdio.h>

int main(){
    int per;
    printf("Enter Your Percentage : ");
    scanf("%d",&per);

    if (per<=100 && per>90){
        printf("Excellent...");
    }

    else if (per<=90 && per>80){
        printf("Very Good...");
    }

    else if (per<=80 && per>70){
        printf("Good...");
    }

    else if (per<=70 && per>60){
        printf("Can do better...");
    }

    else if (per<=60 && per>50){
        printf("Average...");
    }

    else if (per<=50 && per>40){
        printf("Below Average...");
    }

    else{
        printf("Fail...");
    }

    return 0;
}