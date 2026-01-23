#include<stdio.h>

int main(){
    int a = 1,b = 1,c,n;
    printf("Enter number of terms you want to find : ");
    scanf("%d",&n);

    printf("The Fibonacci Series : ");
    for (int i=0;i<n;i++){
        printf("%d ",a);
        c = a+b;
        a = b;
        b = c;
    }

    return 0;
}