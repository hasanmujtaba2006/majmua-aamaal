#include <stdio.h>

int main() {
    int n;
    printf("Entger a number : ");
    scanf("%d",&n);

    int r = 0,last_digit;
    
    while (n>0) {
        last_digit = n%10;
        r = r*10+last_digit;
        n = n/10;
    }
    printf("Reverse : %d",r);
    return 0;
}