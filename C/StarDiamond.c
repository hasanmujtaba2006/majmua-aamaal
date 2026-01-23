#include <stdio.h>

int main() {
    int n;
    printf("Enter number of rows : ");
    scanf("%d",&n);

    int nsp=(n+1)/2,nst=1;

    for (int i=1;i<=n;i++) {
        for (int j=1;j<=nsp;j++) {
            printf(" ");

        }

        for (int k=1;k<=nst;k++) {
            printf("*");
        }

        if (i<(n+1)/2){
            nsp--;
            nst+=2;
        }

        else{
            nsp++;
            nst-=2;
        }
        printf("\n");
    }
    return 0;
}