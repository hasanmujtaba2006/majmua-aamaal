#include<stdio.h>

int main(){
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    int x=1,y=1,sum = 0;

    for (int i=1;i<=n-2;i++){
        sum = x+y;
        x=y;
        y=sum;
    }

    printf("The nth fabonacci number is %d",y);

    return 0;
}