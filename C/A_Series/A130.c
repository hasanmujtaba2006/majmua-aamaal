#include<stdio.h>
#include<string.h>

int main(){
    typedef struct students{
        int RollNo;
        char Name[15];
        char Dept[50];
        char Course[20];
        int yearOfJoin;
    }student;

    student a,b;

    a.RollNo = 117;
    strcpy(a.Name,"Hasan Mujtaba");
    strcpy(a.Dept,"Bachler of Technology");
    strcpy(a.Course,"Computer Science & Engineering");
    a.yearOfJoin = 2025;

    b.RollNo = 93;
    strcpy(b.Name,"Ansh Pratap");
    strcpy(b.Dept,"Bachler of Technology");
    strcpy(b.Course,"Computer Science & Engineering");
    b.yearOfJoin = 2025;

    if (a.Dept == b.Dept){
        printf("Equal...");
    }
    else{
        printf("Unequal...");
    }

    return 0;
}