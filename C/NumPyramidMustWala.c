#include <stdio.h>

int main() {
    int n;
    printf("Enter number of rows : ");
    scanf("%d",&n);

    int nsp=1,nst=n;

    for (int i=1;i<=n;i++){
        int a=1;
        if (i==1){
            for (int j=1;j<=2*n+1;j++){
                printf("%d",j);
            }
        }

        else {
            for (int k=1;k<=nst;k++){
                printf("%d",a);
                a++;
            }

            for (int l=1;l<=nsp;l++){
                printf(" ");
                a++;
            }

            for (int m=1;m<=nst;m++){
                printf("%d",a);
                a++;
            }
        }
        printf("\n");
        nsp+=2;
        nst--;
    }
    return 0;
}