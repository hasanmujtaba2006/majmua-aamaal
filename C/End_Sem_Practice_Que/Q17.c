#include<stdio.h>

int main(){
    int a,b;

    printf("Enter a number : ");
    scanf("%d",&a);

    printf("Enter a number : ");
    scanf("%d",&b);

    int and,or,xor;

    and = a&b;
    or = a|b;
    xor = a^b;

    printf("AND output = %d\n OR output = %d\n XOR output = %d",and,or,xor);

    return 0;
}