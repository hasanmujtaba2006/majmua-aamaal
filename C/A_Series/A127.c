#include<stdio.h>
#include<string.h>

int main(){
    typedef struct person{
        char name[15];
        float salary;
        int age;
    }person;

    person a,b;
    strcpy(a.name,"Hasan Mujtaba");
    a.salary = 100000;
    a.age = 18;

    strcpy(b.name,"Husain Mujtaba");
    b.salary = 120000;
    b.age = 14;

    printf("%s \n",a.name);
    printf("%d ",b.age);

    return 0;
}