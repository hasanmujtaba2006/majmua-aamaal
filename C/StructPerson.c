#include<stdio.h>
#include<string.h>

int main(){
    struct Person{
        char name[15];
        float salary;
        int age;
    };

    struct Person a;
    strcpy(a.name,"Hasan Mujtaba");
    a.salary = 100000;
    a.age = 18;

    struct Person b;
    strcpy(b.name,"Husain Mujtaba");
    b.salary = 20000;
    b.age = 14;

    printf("Name of 1st Person : %s\n",a.name);
    printf("Age of 1st Person : %d\n",a.age);
    printf("Age of 2nd Person : %d\n",b.age);

    return 0;
}