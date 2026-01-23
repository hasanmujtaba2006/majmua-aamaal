#include<stdio.h>

int main(){
    int age;
    printf("Enter your age : ");
    scanf("%d",&age);

    if (age>=18){
        printf("Hurray! You're eligible to cast vote ..");
    }

    else{
        printf("Oops! You're not eligible to cast vote ..");
    }

    return 0;
}