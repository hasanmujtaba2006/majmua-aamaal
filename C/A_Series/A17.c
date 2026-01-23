#include<stdio.h>

int main(){
    int a;
    printf("Enter age of Hasan : ");
    scanf("%d",&a);

    int b;
    printf("Enter age of Husain : ");
    scanf("%d",&b);

    int c;
    printf("Enter age of Mohsin : ");
    scanf("%d",&c);

    if (a<b && a<c){
        printf("Hasan is youngest brother...");
    }

    else if (b<a && b<c){
        printf("Husain is youngest brother...");
    }

    else{
        printf("Mohsin is youngest brother...");
    }

    return 0;
}