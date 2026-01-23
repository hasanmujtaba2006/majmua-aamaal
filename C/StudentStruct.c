#include<stdio.h>
#include<string.h>
#include<stdbool.h>

typedef struct students{
        int rollNo;
        char name[15];
        char Dept[50];
        char Course[10];
        int yearOfJoin;
}student;

void compare(student a,student b){
    if (a.Dept==b.Dept){
        printf("Same Department");
    }
    else{
        printf("Different Department");
    }
    return;
}

int main(){
    student std1;
    std1.rollNo = 112;
    strcpy(std1.name,"Hasan Mujtaba");
    strcpy(std1.Dept,"Engineering");
    strcpy(std1.Course,"B.Tech");
    std1.yearOfJoin = 2025;

    student std2;
    std2.rollNo = 109;
    strcpy(std2.name,"Husain Mujtaba");
    strcpy(std2.Dept,"Management");
    strcpy(std2.Course,"BBA");
    std2.yearOfJoin = 2023;

    compare(std1,std2);
    return 0;
}