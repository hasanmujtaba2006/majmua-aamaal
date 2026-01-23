#include<stdio.h>
#include<string.h>

int main(){
    struct cricketer{
        char name[15];
        int age;
        int noOftest;
        float average;
    };

    struct cricketer a[20];

    for (int i=0;i<20;i++){
        printf("Name of player : ");
        scanf("%[^\n]%s",a[i].name);
        printf("Age of player : ");
        scanf("%d",&a[i].age);
        printf("Number Matches : ");
        scanf("%d",&a[i].noOftest);
        printf("Average : ");
        scanf("%f",&a[i].average);

        printf("\n");
    }
    return 0;
}