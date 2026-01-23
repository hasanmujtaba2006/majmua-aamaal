#include <stdio.h> 

int main() {
    int a;
    printf("Enter first number : ");
    scanf("%d",&a);

    int b;
    printf("Enter second number : ");
    scanf("%d",&b);

    int power = 1;

    for ( int i=1;i<=b;i++) {
        power = power*a;

    }
    printf("Answer : %d",power);
    return 0;
}