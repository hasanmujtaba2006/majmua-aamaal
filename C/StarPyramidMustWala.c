#include <stdio.h>

int main() {
    int n;
    printf("Enter number of rows : ");
    scanf("%d",&n);
    int nsp=1,nst=n;

    for (int i=1;i<=n;i++){
        if (i==1){
            for (int c=1;c<=2*n+1;c++){
                printf("*");
            }
        }
        else{
            for (int j=1;j<=nst;j++){
                printf("*");
            }
            for (int k=1;k<=nsp;k++){
                printf(" ");
            }
            for (int l=1;l<=nst;l++){
                printf("*");
            }
        }
        printf("\n");
        nst--;
        nsp+=2;
        
    }
    return 0;
}