#include <stdio.h>

int main() {
    int n;
    printf("Enter number of terms : ");
    scanf("%d", &n);

    int a;
    printf("Enter first term : ");
    scanf("%d",&a);

    int r;
    printf("Enter common ratio : ");
    scanf("%d",&r);

    for (int i = 1; i<=n; i = i+1){

        printf("%d ",a);
        a = a*r;

    }
    return 0;
} 