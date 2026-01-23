#include<stdio.h>

int main(){
    int n;
    printf("Enter a number whose table you want to print : ");
    scanf("%d",&n);

    printf("Table of %d : \n",n);
    for (int i=n;i<=n*10;i=i+n){
        printf("%d\n",i);
    }

    return 0;
}