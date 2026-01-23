#include<stdio.h>

int main(){
    int x ;
    printf("Enter a number : ");
    scanf("%d",&x);

    int a[5] = {1,2,3,4,5},count=0;

    for (int i=0;i<5;i++){
        if (a[i]<x){
            count++;
        }
    }

    printf("The number of element less %d are %d...",x,count);
    return 0;
}