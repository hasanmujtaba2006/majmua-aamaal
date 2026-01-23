#include<stdio.h>

void swap(int a,int b){
    int temp = a;
    a = b;
    b = temp;
    printf("Swap of number ---> (%d,%d)..",a,b);
    return;
}

int main(){
    int a;
    printf("Enter 1st number : ");
    scanf("%d",&a);

    int b;
    printf("Enter 2nd number : ");
    scanf("%d",&b);

    swap(a,b);
    return 0;
}