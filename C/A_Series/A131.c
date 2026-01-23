#include<stdio.h>
#include<string.h>

typedef struct person{
    int age;
    int weight;
}person;


void get(person* x){
    x->age = 18;
    x->weight = 70;
    return;
}

int main(){
    person a;
    a.age = 8;
    a.weight = 0;
    get(&a);
    printf("Age : %d\n",a.age);
    printf("Weight : %d",a.weight);
    return 0;
}