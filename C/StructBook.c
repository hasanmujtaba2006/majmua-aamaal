#include<stdio.h>
#include<string.h>

int main(){
    struct book{
        char name[50];
        float price;
        int pages;
    };
    struct book a;
    strcpy(a.name,"Ethics Of Islam");
    a.price = 120;
    a.pages = 100;

    printf("Name of book : %s\n",a.name);
    printf("Price of book : %f\n",a.price);
    printf("Number of pages in book : %d\n",a.pages);

    return 0;
}