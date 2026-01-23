#include <stdio.h>

int main() {
    int n;
    printf("Enter a number whose factorial you want : ");
    scanf("%d",&n);

    int product = 1;

    for (int i=1; i<=n;i++) {
        product = product * i;

    }
    printf("The factorial of %d is : %d",n,product);
    return 0;
}