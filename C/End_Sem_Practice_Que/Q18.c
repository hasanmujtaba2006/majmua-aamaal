#include <stdio.h>

int main() {
    int a, b;

    printf("Enter a number : ");
    scanf("%d", &a);

    printf("Enter another number : ");
    scanf("%d", &b);

    int x = a+=b;
    int y = a-=b;
    int z = a*=b;
    int p = a/=b;
    int q = a%=b;

    printf("%d %d %d %d %d", x, y, z, p, q);
    
    return 0;
}
