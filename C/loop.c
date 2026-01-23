#include <stdio.h>

int main() {
    int n;
    printf("Enter how many times to print 'Hello World' : ");
    scanf("%d",&n);

    for ( int i = 1; i <= n; i = i+1 ) {
        printf("%d \n",i);

    }

    return 0;
}