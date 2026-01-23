#include<stdio.h>

int main(){
    int n;
    printf("Enter number of term you want to print : ");
    scanf("%d",&n);

    int x=1,y=1,sum=0;

    if (n>=1){
        printf("1 ");
    }

    if (n>=2){
        printf("1 ");
    }

    for (int i=1;i<=n-2;i++){
        sum = x+y;
        printf("%d ",sum);
        x = y;
        y = sum;
    }
}