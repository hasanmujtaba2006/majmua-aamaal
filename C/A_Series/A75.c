#include<stdio.h>

int combination(int n,int r){
    int nfact = 1;
    for (int i=1;i<=n;i++){
        nfact = nfact*i;
    }

    int rfact = 1;
    for (int j=1;j<=r;j++){
        rfact = rfact*j;
    }

    int nrfact = 1;
    for (int k=1;k<=(n-r);k++){
        nrfact = nrfact*k;
    }

    int combination = nfact/(rfact*nrfact);

    return combination;
}

int main(){
    int n;
    printf("Enter number of rows : ");
    scanf("%d",&n);

    for (int i=1;i<=n;i++){
        for (int j=1;j<=i;j++){
            printf("%d ",combination(i,j));
        }
        printf("\n");
    }
    return 0;
}