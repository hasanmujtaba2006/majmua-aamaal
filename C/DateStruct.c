#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main(){
    struct date{
        int date;
        int month;
        int year;
    };

    struct date date1;
    date1.date = 14;
    date1.month = 11;
    date1.year = 2006;

    struct date date2;
    date2.date = 1;
    date2.month = 5;
    date2.year = 2012;

    bool flag = true;

    if (date1.date!=date2.date){
        flag = false;
    }

    else if (date1.month!=date2.month){
        flag = false;
    }

    else if (date1.year!=date2.year){
        flag = false;
    }

    if (flag==true){
        printf("Equal...");
    }
    if (flag==false){
        printf("Unequal...");
    }

    return 0;
}