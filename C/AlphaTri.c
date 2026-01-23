#include <stdio.h>

int main() {
    int n;
    printf("Enter number of rows & columns : ");
    scanf("%d",&n);

    for (int i=1;i<=n;i++) {
        int a = 65;
        for (int j=1;j<=n-i;j++) {
            printf(" ");
        }

        for (int k=1;k<=i;k++) {
            printf("%c",(char)a);
            a = a+1;
        }
        printf("\n");
    }
    return 0;
}