#include<stdio.h>
#include<string.h>

int main(){
    typedef struct date{
        int date;
        int month;
        int year;
    }date;

    date a,b;
    a.date = 12;
    a.month = 11;
    a.year = 2019;

    b.date = 23;
    b.month = 5;
    b.year = 2024;

    if (a.date == b.date){
        printf("Equal...");
    }
    else{
        printf("Unequal...");
    }

    return 0;
}