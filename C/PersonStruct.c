#include<stdio.h>
#include<string.h>

typedef struct persons{
    int age;
    float weight;
}person;

void check(person* x){
    x->age=18;
    x->weight=70;
    return;
}

int main(){
    person a;
    a.age=15;
    a.weight=70;
    check(&a);
    printf("%d",a.age);
    return 0;
} 