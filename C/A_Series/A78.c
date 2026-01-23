#include<stdio.h>

int min(int a,int b){
    if (a>b){
        return b;
    }
    else{
        return a;
    }
}

void gcd(int a,int b){

    int fact = 0;

    for (int i=1;i<=min(a,b);i++){
        if (min(a,b)%i==0){
            fact = i;
        }
    }
    printf("The highest common factor : %d",fact);
    return;
}

int main(){
    int a;
    printf("Enter 1st number : ");
    scanf("%d",&a);

    int b;
    printf("Enter 2nd number : ");
    scanf("%d",&b);

    gcd(a,b);
    return 0;
}