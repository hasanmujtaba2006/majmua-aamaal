#include <stdio.h>

int main() {
    int n;
    printf("Enter term you want : ");
    scanf("%d",&n);
    
    int x = 1, y = 1,sum;

    for ( int i=1; i<=(n-2); i++) {
        sum = x+y;
        x=y;
        y=sum;
    }

    printf("The %dth term of Fibonacci series is %d",n,y);
    return 0;

}