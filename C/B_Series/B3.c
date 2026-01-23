#include<stdio.h>

int main(){
    float sub1,sub2,sub3,sub4,sub5;

    printf("Enter marks of Subject 1: ");
    scanf("%f",&sub1);

    printf("Enter marks of Subject 2: ");
    scanf("%f",&sub2);

    printf("Enter marks of Subject 3: ");
    scanf("%f",&sub3);

    printf("Enter marks of Subject 4: ");
    scanf("%f",&sub4);

    printf("Enter marks of Subject 5: ");
    scanf("%f",&sub5);

    float per;
    per = (sub1+sub2+sub3+sub4+sub5)/5;

    printf("The total percentage of all subject is %.2f percent..",per);

    return 0;
}