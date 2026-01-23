#include <stdio.h>

int main() {
    int n;
    printf("Enter number of rows : ");
    scanf("%d",&n);

    for (int i=1;i<=n;i++){
        int a=65;
        int b=(65+i)-2;
        for (int j=1;j<=n-i;j++){
            printf(" ");
        }

        for (int k=1;k<=i;k++){
            printf("%c",(char)a);
            a =a+1;
        }

        for (int l=1;l<=i-1;l++){
            printf("%c",(char)b);
            b=b-1;
        }
        printf("\n");
    }
    return 0;
}