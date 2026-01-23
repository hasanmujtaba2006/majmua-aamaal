#include <stdio.h>

int main() {
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    int sum = 0,last_digit;

    while (n>0) {
        last_digit = n%10;
        sum = sum+last_digit;
        n = n/10;
    
    }
    printf("The sum of digits : %d",sum);
    return 0;
}