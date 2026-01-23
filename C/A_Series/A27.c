#include<stdio.h>

int main(){
    int n;
    printf("Enter a number whose table you wants : ");
    scanf("%d",&n);

    printf("The Table of Given Number : \n");

    for (int i=n;i<=n*10;i+=n){
        printf("%d\n",i);
    }

    return 0;
}