#include<stdio.h>

int main(){
    int n;
    printf("Enter number of terms : ");
    scanf("%d",&n);

    int x=1,y=1;

    for (int i=1;i<=n-2;i++){
        int sum = x+y;
        x = y;
        y = sum;
    }

    printf("The %dth term of Fibonacci Series is %d ..",n,y);
    return 0;
}