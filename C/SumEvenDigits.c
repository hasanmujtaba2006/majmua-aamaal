#include <stdio.h>

int main() {
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);

    int sum = 0, last_digit;

    while(n>0) {
        last_digit = n%10;
        if (last_digit%2!=0) {
            n=n/10;
            continue;
            
        }

        else if (last_digit%2==0) {
            sum = sum + last_digit;
            n = n/10;
        }
    
    }
    printf("Sum of even digits : %d",sum);
    return 0;
}