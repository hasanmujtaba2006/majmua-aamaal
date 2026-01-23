#include<stdio.h>
#include<string.h>

int main(){
    typedef struct cricketer{
        char name[15];
        int age;
        int noOftest;
        float average;
    }cricketer;

    cricketer a[20];

    for (int i=0;i<20;i++){
        printf("Name of Player : ");
        scanf("%s",&a[i].name);
        printf("Age : ");
        scanf("%d",&a[i].age);
        printf("No. of test Played : ");
        scanf("%d",&a[i].noOftest);
        printf("Average : ");
        scanf("%f",&a[i].average);
        printf("\n");
    }

    return 0;
}