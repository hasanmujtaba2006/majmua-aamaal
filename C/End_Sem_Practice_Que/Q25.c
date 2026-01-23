#include<stdio.h>

int main(){
    float marks;
    printf("Enter your marks : ");
    scanf("%f",&marks);

    if (marks>=75){
        printf("Distinction ..");
    }

    else if(marks>=60 && marks<=74){
        printf("First Class ..");
    }

    else if(marks>=40 && marks<=59){
        printf("Pass ..");
    }

    else{
        printf("Fail ..");
    }

    return 0;
}