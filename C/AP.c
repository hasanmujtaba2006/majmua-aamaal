#include <stdio.h>

int main() {
    int n;
    printf("Enter number of terms : ");
    scanf("%d",&n);

    int a;
    printf("Enter first term : ");
    scanf("%d",&a);

    int d;
    printf("Enter common difference : ");
    scanf("%d",&d);

    for (int i = 1; i<=n; i = i+1) {
        printf("%d ",a);
        a = a+d;

    }
    return 0;
}