#include<stdio.h>

int main(){
    int a;
    printf("Enter a integer : ");
    scanf("%d",&a);

    float half;
    half = a/2.0;

    printf("The half of %d is %.2f..",a,half);
    return 0;
}